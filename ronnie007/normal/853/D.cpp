#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std ;

#define MAXN 300007
#define inf 1000000007


int n ;
int a[ MAXN ] ;

int dp[ MAXN ][ 42 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        a[ i ] /= 100 ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i <= n ; i ++ ) {
        for ( j = 0 ; j <= 40 ; j ++ ) {
            dp[ i ][ j ] = inf ;
        }
    }
    dp[ 0 ][ 0 ] = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 0 ; j <= 40 ; j ++ ) {
            if ( dp[ i ][ j ] == inf ) { continue ; }
            if ( j + ( a[ i + 1 ] / 10 ) <= 40 ) {
                dp[ i + 1 ][ j + ( a[ i + 1 ] / 10 ) ] = min ( dp[ i + 1 ][ j + ( a[ i + 1 ] / 10 ) ] , dp[ i ][ j ] + a[ i + 1 ] ) ;
            }
            int sp = j ;
            if ( sp > a[ i + 1 ] ) { sp = a[ i + 1 ] ; }
            int nw = j - a[ i + 1 ] ;
            if ( nw < 0 ) { nw = 0 ; }
            dp[ i + 1 ][ nw ] = min ( dp[ i + 1 ][ nw ] , dp[ i ][ j ] + ( a[ i + 1 ] - sp ) ) ;
        }
    }
    int ans = inf ;
    for ( i = 0 ; i <= 40 ; i ++ ) {
        if ( ans > dp[ n ][ i ] ) { ans = dp[ n ][ i ] ; }
    }
    ans *= 100 ;
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}