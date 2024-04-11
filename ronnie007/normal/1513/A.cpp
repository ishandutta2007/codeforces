#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , k ;
int ans[ 107 ] ;

void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    int l , r ;
    l = 2 ;
    r = n ;
    int pos = 2 ;
    ans[ 1 ] = 1 ; 
    while ( k -- ) {
        ans[ pos ++ ] = r -- ;
        ans[ pos ++ ] = l ++ ;
        if ( pos > n + 1 ) { cout << "-1\n" ; return ; }
    }
    while ( pos <= n ) {
        ans[ pos ++ ] = l ++ ;
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
    // scanf ( "%d" , &t ) ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}