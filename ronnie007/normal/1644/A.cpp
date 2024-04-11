#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    set < int > s ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] >= 'a' && a[ i ] <= 'z' ) {
            s.insert ( a[ i ] - 'a' ) ;
        }
        else {
            if ( s.find ( a[ i ] - 'A' ) == s.end ( ) ) {
                cout << "NO\n" ;
                return ;
            }
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