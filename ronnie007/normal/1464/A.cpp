#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
int n , m ;
int nxt[ MAXN ] , used[ MAXN ] ;

int ans ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        nxt[ i ] = used[ i ] = 0 ;
    }
    ans = m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        cin >> x >> y ;
        if ( x == y ) { -- ans ; continue ; }
        nxt[ x ] = y ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == 0 && nxt[ i ] > 0 ) {
            int x = i ;
            while ( x > 0 && used[ x ] == 0 ) {
                used[ x ] = 1 ;
                x = nxt[ x ] ;
            }
            ans += ( x == i ) ;
        }
    }
    cout << ans << "\n" ;
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