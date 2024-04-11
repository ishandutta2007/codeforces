#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MOD 998244353

int n ;
vector < int > v[ MAXN ] ;

long long dp[ MAXN ][ 3 ] ;


void dfs ( int vertex ) {
    int sz = v[ vertex ].size ( ) ;
    if ( sz == 0 ) {
        dp[ vertex ][ 0 ] = dp[ vertex ][ 1 ] = 0 ;
        dp[ vertex ][ 2 ] = 1 ;
        return ;
    }
    dp[ vertex ][ 0 ] = 1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ] ;
        dfs ( h ) ;
        long long rm0 = dp[ vertex ][ 0 ] ;
        long long rm1 = dp[ vertex ][ 1 ] ;
        long long rm2 = dp[ vertex ][ 2 ] ;
        for ( int j = 0 ; j < 3 ; ++ j ) { 
            dp[ vertex ][ j ] *= ( dp[ h ][ 0 ] + dp[ h ][ 2 ] ) % MOD ;
            dp[ vertex ][ j ] %= MOD ;
        }
        dp[ vertex ][ 2 ] += ( ( ( rm2 + rm1 ) % MOD ) * ( ( dp[ h ][ 1 ] + dp[ h ][ 2 ] ) % MOD ) ) % MOD ;
        dp[ vertex ][ 2 ] %= MOD ;
        dp[ vertex ][ 1 ] += ( rm0 * ( ( dp[ h ][ 1 ] + dp[ h ][ 2 ] ) % MOD ) ) % MOD ;
        dp[ vertex ][ 1 ] %= MOD ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        v[ x ].push_back ( i ) ;
    }
}

void solve ( ) {
    dfs ( 1 ) ;
    printf ( "%I64d\n" , ( dp[ 1 ][ 0 ] + dp[ 1 ][ 2 ] ) % MOD ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}