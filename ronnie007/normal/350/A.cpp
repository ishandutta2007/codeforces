#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int main ( )
    {
    int n , m ;
    int a[ 107 ] ;
    int b[ 107 ] ;
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , &a[ i ] ) ;
    for ( i = 0 ; i < m ; i ++ ) scanf ( "%d" , &b[ i ] ) ;
    sort ( a , a + n ) ;
    sort ( b , b + m ) ;
    int mx = a[ 0 ] * 2 ;
    if ( mx < a[ n - 1 ] ) mx = a[ n - 1 ] ;
    if ( mx < b[ 0 ] ) printf ( "%d\n" , mx  ) ;
    else printf ( "-1\n" ) ;
    return 0 ;
    }