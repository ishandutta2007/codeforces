#include<iostream>
#include<stdio.h>
using namespace std ;

int main ( )
    {
    int n , k ;
    int i ;
    scanf ( "%d%d" , &n , &k ) ;
    if ( k >= ( n * ( n - 1 ) / 2 ) ) printf ( "no solution\n" ) ;
    else
        {
        for ( i = 0 ; i < n ; i ++ )
            {
            printf ( "0 %d\n" , i ) ;
            }
        }
    return 0 ;
    }