#include<bits/stdc++.h>
using namespace std ;

int n , k ;

void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    for ( int i = 0 ; i < n ; ++ i ) {
        cout << char ( 'a' + ( i % 3 ) ) ;
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