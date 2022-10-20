#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;
int lo[ MAXN ] , hi[ MAXN ] ;

long long dp[ MAXN ][ 2 ] ;

void dfs ( int vertex , int prv ) {
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dfs ( x , vertex ) ;
    }
    dp[ vertex ][ 0 ] = dp[ vertex ][ 1 ] = 0 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dp[ vertex ][ 0 ] += max ( abs ( lo[ vertex ] - lo[ x ] ) + dp[ x ][ 0 ] ,
                                   abs ( lo[ vertex ] - hi[ x ] ) + dp[ x ][ 1 ] ) ;
        dp[ vertex ][ 1 ] += max ( abs ( hi[ vertex ] - lo[ x ] ) + dp[ x ][ 0 ] ,
                                   abs ( hi[ vertex ] - hi[ x ] ) + dp[ x ][ 1 ] ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        scanf ( "%d%d" , &lo[ i ] , &hi[ i ] ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ; scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    printf ( "%lld\n" , max ( dp[ 1 ][ 0 ] , dp[ 1 ][ 1 ] ) ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    // cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}