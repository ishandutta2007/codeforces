#include<bits/stdc++.h>
using namespace std ;

int n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    if ( n == 1 ) {
        cout << "9\n" ;
    }
    else if ( n == 2 ) {
        cout << "98\n" ;
    }
    else {
        cout << "989" ;
        int lst = 9 ;
        for ( int i = 3 ; i < n ; ++ i ) {
            lst = ( lst + 1 ) % 10 ;
            cout << lst ;
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