#include<bits/stdc++.h>
using namespace std ;

int n ;
string a , b ;

vector < int > v ;

void input ( ) {
    cin >> n >> a >> b ;
}

void solve ( ) {
    v.clear ( ) ;
    int c = ( a[ 0 ] - '0' ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( ( a[ i ] - '0' ) == c ) { continue ; }
        v.push_back ( i ) ;
        c ^= 1 ;
    }
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
        if ( ( b[ i ] - '0' ) == c ) { continue ; }
        v.push_back ( i + 1 ) ;
        c ^= 1 ;
    }
    int sz = v.size ( ) ;
    cout << sz << "\n" ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        cout << v[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}