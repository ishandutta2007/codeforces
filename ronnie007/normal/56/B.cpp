#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
int a[ 1007 ] ;

int main ( )
    {
    int i , j ;
    int k ;
    int br = 0 ;
    scanf ( "%d" , &n ) ;
    for ( i = 1 ; i <= n ; i ++ ) scanf ( "%d" , &a[ i ] ) ;
    int sw ;
    int l , r ;
    for ( i = 1 ; i <= n ; i ++ )
        {
        if ( a[ i ] != i )
            {
            br ++ ;
            for ( j = i + 1 ; j < n ; j ++ )
                {
                if ( a[ j ] == i )
                    {
                    break ;
                    }
                }
            k = j ;
            for ( j = 0 ; j < ( k - i + 1 ) / 2 ; j ++ )
                {
                sw = a[ i + j ] ;
                a[ i + j ] = a[ k - j ] ;
                a[ k - j ] = sw ;
                }
            l = i ;
            r = k ;
            }

        }
    if ( br == 1 )
        {
        printf ( "%d %d\n" , l , r ) ;
        }
    else
        {
        printf ( "0 0\n" ) ;
        }
    return 0 ;
    }