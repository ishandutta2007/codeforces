#include<bits/stdc++.h>
using namespace std ;

int n ;
string s ;

void input ( ) {
    cin >> s ;
    n = s.size ( ) ;
}

void solve ( ) {
    int pos1 = 0 ;
    int pos2 = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( s[ i ] == '0' ) {
            cout << pos2 + 1 << " 4\n" ;
            pos2 = ( pos2 + 2 ) % 4 ;
        }
        else {
            cout << pos1 + 1 << " 1\n" ;
            pos1 = ( pos1 + 1 ) % 4 ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}