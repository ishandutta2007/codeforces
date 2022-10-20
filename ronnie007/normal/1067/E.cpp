#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007
#define MOD 998244353

int n ;
vector < int > v[ MAXN ] ;

int subtree[ MAXN ] ;
long long dp[ MAXN ][ 2 ] ;

long long pw[ MAXN ] ;

int ans = 0 ;

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    dp[ vertex ][ 0 ] = 1 ;
    dp[ vertex ][ 1 ] = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        if ( h == prv ) { continue ; }
        dfs ( h , vertex ) ;
        subtree[ vertex ] += 1 + subtree[ h ] ;
        dp[ vertex ][ 1 ] *= ( 2 * dp[ h ][ 0 ] + 2 * dp[ h ][ 1 ] ) % MOD ;
        dp[ vertex ][ 1 ] %= MOD ;
        dp[ vertex ][ 1 ] = ( dp[ vertex ][ 1 ] + ( dp[ vertex ][ 0 ] * dp[ h ][ 0 ] ) % MOD ) % MOD ;

        dp[ vertex ][ 0 ] *= ( dp[ h ][ 0 ] + 2 * dp[ h ][ 1 ] ) % MOD ;
        dp[ vertex ][ 0 ] %= MOD ;
    }
    ans += ( dp[ vertex ][ 1 ] * pw[ n - subtree[ vertex ] - 1 ] ) % MOD ;
    if ( ans >= MOD ) { ans -= MOD ; }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    pw[ 0 ] = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pw[ i ] = ( pw[ i - 1 ] * 2 ) % MOD ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    ans = ( ans * 2 ) % MOD ;
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}