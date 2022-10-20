#include<iostream>
#include<stdio.h>
using namespace std ;


int a[ 107 ][ 107 ] ;

int main ( )
    {
    int n ;
    scanf ( "%d" , &n ) ;
    int i , j , t ;

    int br = 0 ;
    for ( j = 0 ; j < 100 ; j ++ )
        {
        for ( i = 0 ; i < j ; i ++ )
            {
            br = 0 ;
            for ( t = 0 ; t < 100 ; t ++ )
                {
                if ( t == i || t == j ) continue ;
                if ( a[ i ][ t ] == 1 && a[ t ][ j ] == 1 )
                    {
                    br ++ ;
                    }
                }
            if ( br <= n )
                {
                a[ i ][ j ] = 1 ;
                a[ j ][ i ] = 1 ;
                n = n - br ;
                }
            }
        }
    printf ( "100\n" ) ;
    for ( i = 0 ; i < 100 ; i ++ )
        {
        for ( j = 0 ; j < 100 ; j ++ )
            {
            printf ( "%d" , a[ i ][ j ] ) ;
            }
        printf ( "\n" ) ;
        }
    return 0 ;
    }