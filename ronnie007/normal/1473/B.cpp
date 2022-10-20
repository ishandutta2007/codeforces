#include<bits/stdc++.h>
using namespace std ;

string a , b ;

string h ;

bool f ( ) {
    int len1 = b.size ( ) ;
    int len2 = h.size ( ) ;
    if ( ( len2 % len1 ) != 0 ) { return false ; }
    string aux = "" ;
    int cnt = ( len2 / len1 ) ;
    for ( int i = 0 ; i < cnt ; ++ i ) {
        aux += b ;
    }
    return ( h == aux ) ;
}

void input ( ) {
    cin >> a >> b ;
}

void solve ( ) {
    h = a ;
    for ( int i = 1 ; i <= 30 ; ++ i ) {
        if ( f ( ) == true ) {
            cout << h << "\n" ;
            return ;
        }
        h += a ;
    }
    cout << "-1\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}