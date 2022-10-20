#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

#define MAX(x,y) ((x)<(y))?(y):(x)

int main ( )
    {
    int n ;
    scanf ( "%d" , &n ) ;
    if ( n >= 0 )
        {
        printf ( "%d\n" , n ) ;
        return 0 ;
        }
    printf ( "%d\n" , MAX( n / 10 , ( n / 100 ) * 10 + n % 10 ) );
    return 0 ;
    }