#include<iostream>
#include<stdio.h>
using namespace std ;

int main ( )
    {
    long long n ;
    long long x = 1 ;
    long long k = 0 ;
    scanf ( "%I64d" , &n ) ;
    while ( x <= n * 3  )
        {
        x = x * 3 ;
        if ( k < n / x + 1 && n % x != 0 ) k = n / x + 1 ;
        }
    printf ( "%I64d\n" , k ) ;
    return 0 ;
    }