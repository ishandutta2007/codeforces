#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 3007
#define MOD 1000000007

int n , d ;
vector < int > v[ MAXN ] ;
long long dp[ MAXN ][ MAXN ] ;

long long inv[ MAXN ] ;


long long fastpow ( long long a , long long x ) {
    long long ret = 1 ;
    while ( x != 0 ) {
        if ( ( x % 2 ) == 0 ) {
            a = ( a * a ) % MOD ;
            x /= 2 ;
        }
        else {
            ret = ( ret * a ) % MOD ;
            x -- ;
        }
    }
    return ret ;
}

void dfs ( int vertex ) {
    int i , j ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 1 ; i <= n + 1 ; i ++ ) { dp[ vertex ][ i ] = 1 ; }
    for ( i = 0 ; i < sz ; i ++ ) {
        dfs ( v[ vertex ][ i ] ) ;
        long long aux = 0 ;
        for ( j = 1 ; j <= n + 1 ; j ++ ) {
            aux = ( aux + dp[ v[ vertex ][ i ] ][ j ] ) % MOD ;
            dp[ vertex ][ j ] = ( dp[ vertex ][ j ] * aux ) % MOD ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &d ) ;
    int i ;
    for ( i = 2 ; i <= n ; i ++ ) {
        int x ;
        scanf ( "%d" , &x ) ;
        v[ x ].push_back ( i ) ;
    }
    for ( i = 0 ; i <= ( n + 1 ) ; i ++ ) {
        inv[ i ] = fastpow ( i , MOD - 2 ) ;
    }
}

void solve ( ) {
    dfs ( 1 ) ;
    int i , j ;
    for ( i = 1 ; i <= ( n + 1 ) ; i ++ ) {
        dp[ 1 ][ i ] += dp[ 1 ][ i - 1 ] ;
        dp[ 1 ][ i ] %= MOD ;
    }
    long long ans = 0 ;
    for ( i = 1 ; i <= n + 1 ; i ++ ) {
        long long aux = dp[ 1 ][ i ] ;
        for ( j = 1 ; j <= n + 1 ; j ++ ) {
            if ( i == j ) { continue ; }
            int ff = ( i - j ) ;
            int coef = 1 ;
            if ( ff < 0 ) { ff = -ff ; coef = -1 ; }
            aux = ( aux * ( d - j ) ) % MOD ;
            aux = ( aux * ( inv[ ff ] * coef ) ) % MOD ;
        }
        ans = ( ans + aux + MOD ) % MOD ;
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