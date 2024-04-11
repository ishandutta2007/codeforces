#include<iostream>
#include<stdio.h>
using namespace std ;

int n , k ;
int x ;
int ans = 0 ;
int used[ 17 ] ;


void input ( ) ;
void solve ( ) ;


int main ( )
    {
    input ( ) ;
    return 0 ;
    }



void input ( )
    {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        solve ( ) ;
        }
    printf ( "%d\n" , ans ) ;
    }
void solve ( )
    {
    int i ;
    for ( i = 0 ; i < 10 ; i ++ ) used[ i ] = 0 ;
    while ( x != 0 )
        {
        used[ x % 10 ] ++ ;
        x = x / 10 ;
        }
    for ( i = 0 ; i <= k ; i ++ )
        {
        if ( used[ i ] == 0 ) break ;
        }
    if ( i == k + 1 ) ans ++ ;
    }