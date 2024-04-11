#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 300007

int n , m ;
long long x[ MAXN ] ;
long long y[ MAXN ] ;

long long diff[ MAXN ] ;
long long pref[ MAXN ] ;
vector < int > v[ MAXN ] ;

long long initsm = 0 ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%I64d%I64d" , &x[ i ] ,&y[ i ] ) ;
        diff[ i ] = ( x[ i ] - y[ i ] ) ;
        initsm += y[ i ] ;
    }
    sort ( diff + 1 , diff + n + 1 ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        pref[ i ] = ( pref[ i - 1 ] + diff[ i ] ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        int h1 , h2 ;
        scanf ( "%d%d" , &h1 , &h2 ) ;
        v[ h1 ].push_back ( h2 ) ;
        v[ h2 ].push_back ( h1 ) ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int cur = ( y[ i ] - x[ i ] ) ;
        int l , r , mid ;
        l = 1 ;
        r = n ;
        while ( r - l > 3 ) {
            mid = ( l + r ) / 2 ;
            if ( cur + diff[ mid ] >= 0 ) { r = mid ; }
            else { l = mid ; }
        }
        while ( r > 0 && cur + diff[ r ] >= 0 ) { r -- ; }
        long long ans = 0 ;
        ans += y[ i ] * r ;
        ans += x[ i ] * ( n - r ) ;
        ans += initsm ;
        ans += pref[ r ] ;
        ///printf ( "%I64d " , ans ) ;
        int sz = v[ i ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            int p = v[ i ][ j ] ;
            ans -= min ( x[ i ] + y[ p ] , x[ p ] + y[ i ] ) ;
        }
        ans -= ( x[ i ] + y[ i ] ) ;
        printf ( "%I64d " , ans ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}