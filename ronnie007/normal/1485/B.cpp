#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , q , k ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n >> q >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    while ( q -- ) {
        int l , r ;
        cin >> l >> r ;
        int ans = ( a[ r ] - a[ l ] + 1 ) - ( r - l + 1 ) ;
        ans *= 2 ;
        ans += ( a[ l ] - 1 ) + ( k - a[ r ] ) ;
        cout << ans << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}