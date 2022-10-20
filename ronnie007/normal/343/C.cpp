#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
using namespace std ;

int n , m ;
long long a[ 100007 ] ;
long long b[ 100007 ] ;



bool works ( long long  x , long long y , long long z , long long t )
    {
    if ( x <= y )
        {
        return ( z - x ) <= t ;
        }

    if ( x >= z )
        {
        return ( x - y ) <= t ;
        }
    long long mn = min ( 2 * ( x - y ) + ( z - x ) , 2 * ( z - x ) + ( x - y ) ) ;
    return mn <= t ;
    }



bool f ( long long t )
    {
    long long ind = 0 ;
    int i ;
    int  l , r ;
    int mid ;
    for ( i = 0 ; i < n ; i ++ )
        {
        if ( abs ( b[ ind ] - a[ i ] ) > t ) continue ;
        l = ind ;
        r = m - 1 ;
        while ( l < r  )
            {
            mid = ( r + l + 1 ) / 2 ;
            if ( works ( a[ i ] , b[ ind ] , b[ mid ] , t ) == true )
                {
                l = mid ;
                }
            else r = mid - 1 ;
            }
        ind = l + 1 ;
        if ( ind == m ) return true ;
        }
    if ( ind == m ) return true ;
    return false ;
    }

int main ( )
    {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 0 ;  i < n ; i ++ )
        {
        scanf ( "%I64d" , &a[ i ] ) ;
        }
    for ( i = 0 ; i < m ; i ++ )
        {
        scanf ( "%I64d" , &b[ i ] ) ;
        }

    long long l , r ;
    long long mid ;
    l = 0 ;
    r = 1e11;


    while ( r - l > 1 )
        {
        mid = ( r + l ) / 2 ;
        if ( f ( mid ) == true ) r = mid ;
        else l = mid ;
        }
    if ( f( l ) == false ) l ++ ;

    printf ( "%I64d\n" , l ) ;

    return 0 ;
    }