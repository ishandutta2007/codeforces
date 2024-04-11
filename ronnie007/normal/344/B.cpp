#include<iostream>
#include<stdio.h>
using namespace std ;

int main ( )
    {
    int a, b , c ;
    scanf ( "%d%d%d" , &a , &b , &c ) ;
    int i ;
    for ( i = 0 ; i <= a ; i ++ )
        {
        if ( i > b ) break ;
        if ( c == a + b - 2 * i )
            {
            printf ( "%d %d %d\n" , i , b - i , a - i ) ;
            return 0 ;
            }
        }
    printf ( "Impossible\n" ) ;
    return 0 ;
    }