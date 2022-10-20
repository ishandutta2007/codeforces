#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define MOD 998244353

int n ;
vector < int > v[ MAXN ] ;

long long ans[ MAXN ] ;

int dfs ( int vertex , int prv , int hh ) {
    int aux = 0 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        int ret = dfs ( x , vertex , hh ) ;
        if ( ret == -1 ) { return -1 ; }
        aux += ( ret == 0 ) ;
    }
    if ( ( aux % hh ) == 0 ) { return 0 ; }
    ++ aux ;
    if ( ( aux % hh ) == 0 ) { return 1 ; }
    return -1 ;
}

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        ans[ i ] = 0 ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    ans[ 1 ] = 1 ;
    for ( int i = 1 ; i < n ; ++ i ) {
        ans[ 1 ] *= 2 ;
        if ( ans[ 1 ] >= MOD ) {
            ans[ 1 ] -= MOD ;
        }
    }
    for ( int i = n - 1 ; i >= 1 ; -- i ) {
        if ( ( n - 1 ) % i == 0 && i > 1 ) {
            int ret = dfs ( 1 , -1 , i ) ;
            if ( ret == 0 ) { ans[ i ] = 1 ; }
        }
        for ( int j = 2 * i ; j < n ; j += i ) {
            ans[ i ] -= ans[ j ] ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}