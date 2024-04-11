#include<iostream>
#include<stdio.h>
using namespace std ;

int n , m ;

int eatenr[ 1007 ];
int eatenc[ 1007 ];


int main ( )
    {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    int x , y ;
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%d%d" , &x , &y );
        eatenr[ x ] = 1 ;
        eatenc[ y ] = 1 ;
        }
    if ( n % 2 == 1 )
        {
        if ( eatenr[ n / 2 + 1 ] == 0 && eatenc[ n / 2 + 1 ] == 0 )
            {
            eatenc[ n / 2 + 1 ] = 1 ;
            }
        }
    int ans = 0 ;
    for ( i = 2 ; i < n ; i ++ )
        {
        if ( eatenr[ i ] == 0 ) ans ++ ;
        if ( eatenc[ i ] == 0 ) ans ++ ;
        }
    printf ( "%d\n" , ans ) ;
    return 0 ;
    }