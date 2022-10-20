#include<iostream>
#include<stdio.h>
using namespace std ;

int main ( )
    {
    int n , k ;
    int i ;
    scanf ( "%d%d" , &n , &k ) ;
    for ( i = 1 ; i <= k ; i ++ )
        {
        printf ( "%d " , 2 * i - 1 ) ;
        printf ( "%d " , 2 * i ) ;
        }
    for ( i = k + 1 ; i <= n ; i ++ )
        {
        printf ( "%d " , 2 * i ) ;
        printf ( "%d " , 2 * i - 1 ) ;
        }
    printf ( "\n" ) ;
    return 0 ;
    }