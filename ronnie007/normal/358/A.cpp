#include<iostream>
#include<stdio.h>
using namespace std ;

int main ( )
    {
    int n ;
    int a[ 1007 ] ;
    int i , j ;
    scanf ( "%d" , &n ) ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    int x , y ;
    int x1 , y1 ;
    for ( i = 0 ; i < n - 1 ; i ++ )
        {
        for ( j = 0 ; j < n - 1  ; j ++ )
            {
            if ( a[ i ] < a[ i + 1 ] ) { x = a[ i ] ; y = a[ i + 1 ] ; }
            else { x = a[ i + 1 ] ; y = a[ i ] ; }

            if ( a[ j ] < a[ j + 1 ] ) { x1 = a[ j ] ; y1 = a[ j + 1 ] ; }
            else { x1 = a[ j + 1 ] ; y1 = a[ j ] ; }

            if ( x < x1 && x1 < y && y < y1 )
                {
                printf ( "yes\n" ) ;
                return 0 ;
                }
            if ( x1 < x && x < y1 && y1 < y )
                {
                printf ( "yes\n" ) ;
                return 0 ;
                }

            }
        }
    printf ( "no\n" ) ;
    return 0 ;
    }