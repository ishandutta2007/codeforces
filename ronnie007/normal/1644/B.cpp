#include<bits/stdc++.h>
using namespace std ;

int n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    if ( n == 3 ) {
        cout << "3 2 1\n" ;
        cout << "1 3 2\n" ;
        cout << "3 1 2\n" ;
        return ;
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = i ; j >= 1 ; -- j ) {
            cout << j << " " ;
        }
        for ( int j = n ; j > i ; -- j ) {
            cout << j << " " ;
        }
        cout << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    ///scanf ( "%d" , &t ) ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}