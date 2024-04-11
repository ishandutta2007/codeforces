#include<iostream>
#include<stdio.h>
using namespace std ;


int nod ( int x , int y )
    {
    if ( y == 0 ) return x ;
    return nod ( y , x % y ) ;
    }

int main ( )
    {
    int n ;
    int x ;
    scanf ( "%d" , &n ) ;
    int i ;
    int mx = 0 ;
    int ans = 0 ;
    scanf ( "%d" , &x ) ;
    ans = x ;
    mx = x ;
    for ( i = 0 ; i < n - 1 ; i ++ )
        {
        scanf ( "%d" , &x ) ;
        ans = nod ( ans , x ) ;
        if ( mx < x ) mx = x ;
        }
    int t = mx / ans - n ;
    if ( t % 2 == 1 ) printf ( "Alice\n" ) ;
    else printf ( "Bob\n" ) ;
    return 0 ;
    }