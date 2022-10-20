#include<iostream>
#include<stdio.h>
using namespace std ;

int main ( )
    {
    long long  n , k , y ;
    scanf ( "%I64d%I64d%I64d" , &y , &k , &n ) ;
    bool fl = false ;
    long long i ;
    for ( i = k ; i <= n ; i += k )
        {
        if ( i > y )
            {
            printf ( "%I64d " , i - y ) ;
            fl = true ;
            }
        }
    if ( fl == false ) printf ( "-1" ) ;
    printf ( "\n" ) ;
    return 0 ;
    }