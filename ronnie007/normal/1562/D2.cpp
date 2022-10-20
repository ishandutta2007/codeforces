#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 300007

int n , q ;
string a ;

int suff[ MAXN ] ;

set < int > s[ 4 * MAXN ] ;

void input ( ) {
    cin >> n >> q ;
    cin >> a ;
    for ( int i = 1 ; i < n ; i += 2 ) {
        if ( a[ i ] == '-' ) { a[ i ] = '+' ; }
        else { a[ i ] = '-' ; }
    }
    for ( int i = 2 * MAXN - 2 * n - 2 ; i <= 2 * MAXN + 2 * n + 2 ; ++ i ) {
        s[ i ].clear ( ) ;
    }
    suff[ n + 1 ] = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        suff[ i ] = suff[ i + 1 ] ;
        int hh = 0 ;
        if ( a[ i - 1 ] == '+' ) { ++ suff[ i ] ; hh = 1 ; }
        else { -- suff[ i ] ; hh = -1 ; }
        
        s[ 2 * MAXN - hh - 2 * suff[ i + 1 ] ].insert ( i ) ;
    }
}

void solve ( ) {
    while ( q -- ) {
        int l , r ; cin >> l >> r ;
        if ( ( suff[ l ] - suff[ r + 1 ] ) == 0 ) {
            cout << "0\n" ;
            continue ;
        }
        vector < int > ans ; ans.clear ( ) ;
        if ( ( r - l + 1 ) % 2 == 0 ) {
            ans.push_back ( r ) ;
            -- r ;
        }
        int sm = suff[ l ] - suff[ r + 1 ] ;
        int aux = suff[ r + 1 ] ;
        auto it = s[ 2 * MAXN - sm - 2 * aux ].lower_bound ( l ) ;
        ans.push_back ( (*it) ) ;
        cout << (int)ans.size ( ) << "\n" ;
        for ( auto x : ans ) {
            cout << x << " " ;
        }
        cout << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}