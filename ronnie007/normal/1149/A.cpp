#include<bits/stdc++.h>
using namespace std ;

int n ;
int cnt[ 3 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        cin >> x ;
        ++ cnt[ x ] ;
    }
}

void solve ( ) {
    if ( cnt[ 2 ] > 0 ) {
        cout << "2 " ;
        -- cnt[ 2 ] ;
    }
    if ( cnt[ 1 ] > 0 ) {
        cout << "1 " ;
        -- cnt[ 1 ] ;
    }
    for ( int i = 2 ; i >= 1 ; -- i ) {
        while ( cnt[ i ] > 0 ) {
            cout << i << " " ;
            -- cnt[ i ] ;
        }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}