#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;
string a ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    for ( auto &c : a ) {
        if ( c == 'U' ) { c = 'D' ; }
        else if ( c == 'D' ) { c = 'U' ; }
    }
    cout << a << "\n" ;
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