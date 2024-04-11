#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
int a[ 107 ] ;

int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i , j , k ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < n ; j ++ )
            {
            for ( k = j + 1  ; k < n ; k ++ )
                {
                if ( a[ i ] == a[ j ] + a[ k ] )
                    {
                    printf ( "%d %d %d\n" , i + 1 , j + 1 , k + 1 ) ;
                    return 0 ;
                    }
                }
            }
        }
    printf ( "-1\n" ) ;
    return 0 ;
    }