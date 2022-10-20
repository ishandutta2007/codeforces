#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007

int n , m ;
set < int > s[ MAXN ] ;

int ans = 0 ;

int proc ( int x ) {
    if ( s[ x ].empty ( ) == true ) { return 1 ; }
    auto it = s[ x ].end ( ) ;
    -- it ;
    if ( x < (*it) ) { return 0 ; }
    return 1 ; 
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i < m ; ++ i ) {
        int x , y ; cin >> x >> y ;
        s[ x ].insert ( y ) ;
        s[ y ].insert ( x ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        ans += proc ( i ) ;
    }
}

void solve ( ) {
    int q ; cin >> q ;
    while ( q -- ) {
        int type , x , y ;
        cin >> type ;
        if ( type == 1 ) {
            cin >> x >> y ;
            ans -= proc ( x ) + proc ( y ) ;
            s[ x ].insert ( y ) ;
            s[ y ].insert ( x ) ;
            ans += proc ( x ) + proc ( y ) ;
        }
        else if ( type == 2 ) {
            cin >> x >> y ;
            ans -= proc ( x ) + proc ( y ) ;
            s[ x ].erase ( y ) ;
            s[ y ].erase ( x ) ;
            ans += proc ( x ) + proc ( y ) ;
        }
        else {
            cout << ans << "\n" ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}