#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

int money = 0;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int n){
    money += n;
    ui->lcdNumber->display(money);
}

void Widget::isExist(int money){

    if(money<100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }
    else if(money<150){
        ui->pbCoffee->setEnabled(true);
           ui->pbTea->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }
    else if(money<200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoke->setEnabled(false);
    }
    else if(money>=200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoke->setEnabled(true);
    }

}
void Widget::on_pb10_clicked()
{
    changeMoney(10);
    isExist(money);
}

void Widget::on_pb50_clicked()
{

    changeMoney(50);
    isExist(money);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
    isExist(money);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
    isExist(money);
}


void Widget::on_pbCoffee_clicked()
{
    if(money<=0){
        return;
    }
    changeMoney(-100);
    isExist(money);
}

void Widget::on_pbTea_clicked()
{
    if(money<=0){
        return;
    }
    changeMoney(-150);
    isExist(money);

}

void Widget::on_pbCoke_clicked()
{
    if(money<=0){
        return;
    }
    changeMoney(-200);
    isExist(money);
}

void Widget::on_pbReturn_clicked()
{
    QMessageBox msg;
    int five_hundred = 0, one_hundred = 0, fifty = 0, ten = 0;
    if(money>=0){
          five_hundred = money/500;
          money = money % 500;
          one_hundred = money/100;
          money = money % 100;
          fifty = money/50;
          money = money % 50;
          ten = money/10;
          money = money % 10;
    }

    QString str;
    str = QString("500 : %1, 100 : %2, 50 : %3, 10 : %4").arg(five_hundred).arg(one_hundred).arg(fifty).arg(ten);
    changeMoney(0);
    msg.information(nullptr, "Remain Money",str,"got it");

}
