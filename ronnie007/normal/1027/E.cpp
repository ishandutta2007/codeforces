#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 507
#define MOD 998244353

int n , k ;

long long dp[ MAXN ][ MAXN ] ;

long long h[ MAXN ] ;
long long row[ MAXN ][ 2 ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    int i , j , t ;
    for ( t = 1 ; t <= n ; t ++ ) {
    }
    for ( t = 1 ; t <= n ; t ++ ) {
        for ( i = 0 ; i <= n ; i ++ ) { row[ i ][ 0 ] = row[ i ][ 1 ] = 0 ; }
        row[ 0 ][ 0 ] = 1 ;
        row[ 0 ][ 1 ] = 1 ;
        for ( i = 0 ; i < n ; i ++ ) {
            for ( int p = 0 ; p < 2 ; p ++ ) {
                for ( j = 1 ; j <= t ; j ++ ) {
                    if ( i + j > n ) { break ; }
                    row[ i + j ][ (p^1) ] += row[ i ][ p ] ;
                    if ( row[ i + j ][ (p^1) ] >= MOD ) {
                        row[ i + j ][ (p^1) ] -= MOD ;
                    }
                }
            }
        }
        h[ t ] = ( row[ n ][ 0 ] + row[ n ][ 1 ] ) % MOD ;
        for ( j = 1 ; j < t ; j ++ ) {
            h[ t ] = ( h[ t ] - h[ j ] ) ;
            if ( h[ t ] < 0 ) { h[ t ] += MOD ; }
        }
    }
    long long ans = 0 ;
    for ( t = 1 ; t <= n ; t ++ ) {
        long long cur = 0 ;
        int lim = ( ( k - 1 ) / t ) ;
        if ( lim > n ) { lim = n ; }
        for ( i = 0 ; i <= n ; i ++ ) {
            for ( j = 0 ; j <= lim ; j ++ ) {
                dp[ i ][ j ] = 0 ;
            }
        }
        dp[ 1 ][ 1 ] = 1 ;
        for ( i = 1 ; i < n ; i ++ ) {
            for ( j = 1 ; j <= lim ; j ++ ) {
                dp[ i + 1 ][ j + 1 ] += dp[ i ][ j ] ;
                if ( dp[ i + 1 ][ j + 1 ] >= MOD ) {
                    dp[ i + 1 ][ j + 1 ] -= MOD ;
                }
                dp[ i + 1 ][ 1 ] += dp[ i ][ j ] ;
                if ( dp[ i + 1 ][ 1 ] >= MOD ) {
                    dp[ i + 1 ][ 1 ] -= MOD ;
                }
            }
        }
        for ( j = 1 ; j <= lim ; j ++ ) {
            cur += dp[ n ][ j ] ;
            cur %= MOD ;
        }
        cur = ( cur * h[ t ] ) % MOD ;
        ans = ( ans + cur ) % MOD ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}