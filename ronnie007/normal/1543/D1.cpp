#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , k ;

void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    int ret ;
    int hh = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cout << ( i ^ hh ) << "\n" ;
        fflush ( stdout ) ;

        cin >> ret ;
        if ( ret == -1 ) { exit ( 0 ) ; }
        if ( ret == 1 ) { return ; }
        hh = i ;
    }
}

int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
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