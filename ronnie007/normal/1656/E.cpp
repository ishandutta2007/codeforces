#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;
int ans[ MAXN ] ;

int dep[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    int sm = 0 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        sm += dep[ vertex ] ;
        dep[ x ] = -dep[ vertex ] ;
        dfs ( x , vertex ) ;
    }
    if ( prv >= 1 ) {
        ans[ vertex ] = dep[ prv ] - sm ; 
    }
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    int root = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( v[ i ].size ( ) == 1 ) {
            root = i ;
            break ;
        }
    }
    dep[ root ] = 1 ;
    dfs ( root , -1 ) ;
    ans[ root ] = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    cin >> t ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}