#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n , m ;
string a[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        ans += ( a[ i ][ m - 1 ] == 'R' ) ;
    }
    for ( int i = 0 ; i < m - 1 ; ++ i ) {
        ans += ( a[ n - 1 ][ i ] == 'D' ) ;
    }
    cout << ans << "\n" ;
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