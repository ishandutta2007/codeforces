#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 0 ; i < 30 ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( ( a[ j ] & ( 1 << i ) ) > 0 ) {
                ans += ( 1 << i ) ;
                break ;
            }
        }
    }
    cout << ans << "\n" ;
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