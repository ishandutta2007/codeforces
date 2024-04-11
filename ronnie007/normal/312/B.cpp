#include<iostream>
#include<stdio.h>
using namespace std ;

int main ( )
    {
    int a , b , c , d ;
    double x , y ;
    cin >> a >> b >> c >> d ;
    x = a * d ;
    y = b * d - ( b - a ) * ( d - c ) ;
    printf ( "%.6lf\n" , x / y ) ;
    return 0 ;
    }