#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> n >> a ;
}

void solve ( ) {
    int cnt = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cnt += ( a[ i ] == 'b' ) ;
    }
    for ( int i = 0 ; i < cnt ; ++ i ) { cout << "b" ; }
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] != 'b' ) { cout << a[ i ] ; }
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