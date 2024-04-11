#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
int a[ 107 ] ;


int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i ;
    int mn = 1000000 ;
    int ans = 0 ;
    int br = 0 ;
    for ( i = 0 ; i < n ; i ++ )
        {
        scanf ( "%d" , &a[ i ] ) ;
        ans += a[ i ] ;
        if ( a[ i ] % 2 == 1 )
            {
            br ++ ;
            if ( mn > a[ i ] ) mn = a[ i ] ;
            }
        }
    if ( mn == 1000000 ) printf ( "0\n" ) ;
    else
        {
        if ( ans % 2 == 0 ) printf ( "%d\n" , ans - mn ) ;
        else printf ( "%d\n" , ans ) ;
        }
    return 0 ;
    }