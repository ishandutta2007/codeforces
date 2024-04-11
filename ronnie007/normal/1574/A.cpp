#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < i ; ++ j ) {
            cout << "()" ;
        }
        for ( int j = 0 ; j < n - i ; ++ j ) {
            cout << "(" ;
        }
        for ( int j = 0 ; j < n - i ; ++ j ) {
            cout << ")" ;
        }
        cout << "\n" ;
    }
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