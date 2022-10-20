#include<iostream>
#include<stdio.h>
using namespace std ;

int d[ 1000007 ] ;

int main ( )
    {
    long long ans = 0 ;
    int n , m ;
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    int x , y ;
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d%d" , &x , &y ) ;
        d[ x ] ++ ;
        d[ y ] ++ ;
        }
    ans = 0 ;
    long long a , b ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        a = d[ i ] ;
        b = n - 1 - a ;
        ans += a * ( a - 1 ) + b * ( b - 1 ) - a * b ;
        }
    printf ( "%I64d\n" , ans / 6 ) ;
    return 0 ;
    }