#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007

int n , m ;
vector < int > v[ MAXN ] ;

int cnt[ MAXN ] ;
int ans[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int sz ; cin >> sz ;
        v[ i ].resize ( sz ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            cin >> v[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( v[ i ].size ( ) == 1 ) {
            ++ cnt[ v[ i ][ 0 ] ] ;
            ans[ i ] = v[ i ][ 0 ] ;
        }
    }
    int lim = ( ( m + 1 ) / 2 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( cnt[ i ] > lim ) {
            cout << "NO\n" ;
            return ;
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( v[ i ].size ( ) == 1 ) { continue ; }
        for ( auto x : v[ i ] ) {
            if ( cnt[ x ] < lim ) {
                ++ cnt[ x ] ;
                ans[ i ] = x ;
                break ;
            }
        }
    }
    cout << "YES\n" ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}