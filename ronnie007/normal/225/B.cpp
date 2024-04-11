#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

long long  a[ 107 ] ;

int main ( )
    {
    int n , k ;
    int i, j  ;
    scanf ( "%d%d" , &n , &k ) ;
    int p ;
    if ( k <= 32 )
        {
        for ( i = 0 ; i < k ; i ++ ) a[ i ] = 0 ;
        a[ k ] = 1 ;
        p = 1 ;
        for ( j = k + 1 ; j <= 100 ; j ++ )
            {
            if ( p > n ) break ;
            a[ j ] = p ;
            p -= a[ j - k ] ;
            p += a[ j ] ;
            }
        }
    else
        {
        a[ 0 ] = 1 ;
        for ( i = 1 ; i <= 32 ; i ++ ) { if ( 2 * a[ i - 1 ] >= n ) break ; a[ i ] = 2 * a[ i - 1 ] ; }
        }
    vector < int > ans ;
    ///printf ( "2\n" ) ;
    while ( n != 0 )
        {
        if ( n == 0 ) break ;
        ///printf ( "%d\n" , n ) ;
        for ( i = 1; i <= 100 ; i ++ )
            {
            if ( a[ i - 1 ] <= n && a[ i - 1 ] != 0 && ( a[ i ] == 0 || a[ i ] > n ) ) break ;
            }
        ///cout << a[ i - 1 ]  << "\n" ;
        ///system ( "pause" ) ;
        ans.push_back ( a[ i - 1 ] ) ;
        n -= a[ i - 1 ] ;
        }
    if ( ans.size ( ) == 1 ) ans.push_back ( 0 ) ;
    printf ( "%d\n" , ans.size ( ) ) ;

    for ( i = 0 ; i < ans.size ( ) ; i ++ )
        {
        printf ( "%d " , ans[ i ] ) ;
        }
    printf ( "\n" ) ;
    return 0 ;
    }