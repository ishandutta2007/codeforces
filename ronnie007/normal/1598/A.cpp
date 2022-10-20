#include<bits/stdc++.h>
using namespace std ;

int n ;
string a[ 2 ] ;

void input ( ) {
    cin >> n ;
    cin >> a[ 0 ] >> a[ 1 ] ;
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ 0 ][ i ] == '1' && a[ 1 ][ i ] == '1' ) {
            cout << "NO\n" ;
            return ;
        }
    }
    cout << "YES\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// t = 1 ;
    /// scanf ( "%d" , &t ) ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}