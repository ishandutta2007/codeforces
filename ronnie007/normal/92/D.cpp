#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
int a[ 100007 ] ;
int f[ 100007 ] ;
int ans[ 100007 ] ;

int main ( )
    {
    int i , j ;
    int l , r , mid ;
    scanf ( "%d" , &n ) ;
    for ( i = 0 ; i < n ; i ++ ) scanf ( "%d" , &a[ i ] ) ;
    ans[ n - 1 ] = -1 ;
    f[ n - 1 ] = a[ n - 1 ] ;
    for ( i = n - 2 ; i >= 0 ; i -- )
        {
        l = i + 1 ;
        r = n - 1 ;
        if ( f[ i + 1 ] >= a[ i ] )
            {
            ans[ i ] = -1 ;
            f[ i ] = min ( f[ i + 1 ] , a[ i ] ) ;
            continue ;
            }
        while ( r - l > 1 )
            {
            mid = ( r + l ) / 2 ;
            if ( f[ mid ] >= a[ i ] ) r = mid ;
            else l = mid ;
            }
        if ( f[ l + 1 ] < a[ i ] && l + 1 < n ) l ++ ;
        ///cout << l << "\n" ;
        if ( f[ l ] > a[ i ]  ) ans[ i ] = -1 ;
        else ans[ i ] = l - i - 1 ;
        f[ i ] = min ( f[ i + 1 ] , a[ i ] ) ;
        }
    for ( i = 0 ; i < n ; i ++ )
        {
        printf ( "%d " , ans[ i ] ) ;
        }
    printf ( "\n" ) ;
    return 0 ;
    }