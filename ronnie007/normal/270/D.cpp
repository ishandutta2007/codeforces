#include<iostream>
#include<stdio.h>
using namespace std ;

int n , m ;

struct tuhla
    {
    int type ;
    double x ;
    };

struct tuhla a[ 5007 ] ;



int dp[ 5007 ] ;

int main ( )
    {
    scanf ( "%d%d" , &n , &m ) ;
    int i , j ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d%lf" , &a[ i ].type , &a[ i ].x ) ;
        }

    for ( i = 0 ; i < n ; i ++ ) dp[ i ] = 1 ;

    for ( i = 0 ; i < n ; i ++ )
        {
        for ( j = 0 ; j < i ; j ++ )
            {
            if ( a[ i ].type >= a[ j ].type ) if ( dp[ i ] < dp[ j ] + 1 ) dp[ i ] = dp[ j ] + 1 ;
            }
        }
    int ans = 0  ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( dp[ i ] > ans ) ans = dp[ i ] ;
        }
    printf ( "%d\n" , n - ans  ) ;
    return 0 ;
    }