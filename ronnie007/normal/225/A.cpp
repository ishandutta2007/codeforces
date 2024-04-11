#include<iostream>
#include<stdio.h>
using namespace std ;


int n ;
int x ;
int a[ 107 ] ;
int b[ 107 ] ;

void input ( ) ;
void solve ( ) ;

int main ( )
    {
    input ( ) ;
    solve ( ) ;
    return 0 ;
    }


void input ( )
    {
    scanf ( "%d%d" , &n , &x ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d%d" , &a[ i ] , &b[ i ] ) ;
        }
    }

void solve ( )
    {
    int i ;
    for ( i = 1 ; i < n ; i ++ )
        {
        if ( a[ i ] == x || 7 - a[ i ] == x || b[ i ] == x || 7 - b[ i ] == x ) break ;
        }
    if ( i == n ) printf ( "YES\n" );
    else printf ( "NO\n" ) ;
    }