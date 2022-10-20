#include<bits/stdc++.h>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 1 ; i < n ; ++ i ) {
        ans += ( a[ i ] == a[ i - 1 ] ) ;
    }
    cout << ( ans + 1 ) / 2 << "\n" ;
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