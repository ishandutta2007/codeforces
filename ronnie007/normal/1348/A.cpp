#include<bits/stdc++.h>
using namespace std ;

int n ;
long long ans = 0 ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    int sr = ( n / 2 ) ;
    ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i < sr || i == n ) { ans += (1<<i) ; }
        else { ans -= (1<<i) ; }
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