#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007

int n ;
vector < int > v[ MAXN ] ;
int cnt[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dfs ( x , vertex ) ;
        if ( cnt[ x ] == 0 ) { ++ cnt[ vertex ] ; }
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        cnt[ i ] = 0 ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ; cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( cnt[ i ] > 0 ) {
            if ( ans != 0 ) { -- ans ; }
            ans += cnt[ i ] ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}