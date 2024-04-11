#include<iostream>
#include<stdio.h>
using namespace std ;

int main ( )
    {
    int n ;
    int i , j ;
    scanf ( "%d" , &n ) ;
    for ( i = 0  ; i < n ; i ++ )
        {
        for ( j = 1 ; j <= n / 2 ; j ++ )
            {
            printf ( "%d " , i * ( n / 2 )  + j ) ;
            }
        for ( j = 0 ; j < n / 2 ; j ++ )
            {
            printf ( "%d " , n * n - i * ( n / 2 )  - j  ) ;
            }
        printf ( "\n" ) ;
        }
    return 0 ;
    }