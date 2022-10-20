#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

bool f ( int x , int y )
    {
    if ( x > y ) return true ;
    return false ;
    }

int n ;
int a[ 2000007 ] ;

int main ( )
    {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 0 ;  i < n ; i ++ )
        {
        scanf( "%d" , &a[ i ] ) ;
        }
    sort ( a , a + n , f ) ;
    long long ans = 0 ;
    while ( n >= 1 )
        {
        for (  i = 0 ; i < n ; i ++ ) ans += a[ i ] ;
        n = n / 4 ;
        }
    printf ( "%I64d\n" , ans ) ;
    return 0 ;
    }