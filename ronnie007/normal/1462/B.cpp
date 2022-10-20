#include<bits/stdc++.h>
using namespace std ;

int n ;
string s ;

void input ( ) {
    cin >> n ;
    cin >> s ;
}

void solve ( ) {
    if ( s == "2020" ) {
        cout << "YES\n" ;
        return ;
    }
    if ( s.size ( ) >= 4 ) {
        for ( int i = 0 ; i <= 4 ; ++ i ) {
            string aux = "" ;
            for ( int j = 0 ; j < i ; ++ j ) {
                aux += s[ j ] ;
            }
            int lft = 4 - i ;
            for ( int j = lft ; j >= 1 ; -- j ) {
                aux += s[ n - j ] ;
            }
            if ( aux == "2020" ) {
                cout << "YES\n" ;
                return ;
            }
        }
    }
    cout << "NO\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}