#include<iostream>
#include<stdio.h>
using namespace std ;


int main ( )
    {
    int n , m ;
    scanf ( "%d%d" , &n , &m ) ;
    int i , j ;
    printf ( "%d\n" , n + m - 1 ) ;
    for ( j =  1 ; j <= m ; j ++ )
        {
        printf ( "1 %d\n" , j ) ;
        }
    for ( j =  2 ; j <= n ; j ++ )
        {
        printf ( "%d 1\n" , j ) ;
        }

    return 0 ;
    }