#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n , m ;
int ext[ MAXN ][ MAXN ] ;
bool stat[ MAXN ][ MAXN ] ;
long long ans ;

int proc ( int x , int y ) {
    if ( ext[ x ][ y ] == 0 ) { return 0 ; }
    int ret = 0 ;
    if ( ext[ x ][ y + 1 ] >= ext[ x ][ y ] ) {
        ret += 2 * ext[ x ][ y ] ;
    }
    else {
        ret += 2 * ext[ x ][ y + 1 ] + 1 ;
    }

    if ( ext[ x + 1 ][ y ] >= ext[ x ][ y ] ) {
        ret += 2 * ext[ x ][ y ] ;
    }
    else {
        ret += 2 * ext[ x + 1 ][ y ] + 1 ;
    }
    ret -= 1 ;
    return ret ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = m ; j >= 1 ; -- j ) {
            ext[ i ][ j ] = ext[ i + 1 ][ j + 1 ] + 1 ;
        }
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            ans += proc ( i , j ) ;
        }
    }
    int q ;
    cin >> q ;
    while ( q -- ) {
        int x , y ;
        cin >> x >> y ;
        if ( stat[ x ][ y ] == true ) {
            stat[ x ][ y ] = false ;
        }
        else {
            stat[ x ][ y ] = true ;
        }
        int diag = ( x - y ) ;
        for ( int i = diag - 1 ; i <= diag + 1 ; ++ i ) {
            for ( int x = 1 ; x <= n ; ++ x ) {
                int y = x - i ;
                if ( y <= 0 || y > m ) { continue ; }
                ans -= proc ( x , y ) ;
            }
        }

        for ( int x = n ; x >= 1 ; -- x ) {
            int y = x - diag ;
            if ( y <= 0 || y > m ) { continue ; }
            if ( stat[ x ][ y ] == true ) { ext[ x ][ y ] = 0 ; }
            else { ext[ x ][ y ] = ext[ x + 1 ][ y + 1 ] + 1 ; }
        }

        for ( int i = diag - 1 ; i <= diag + 1 ; ++ i ) {
            for ( int x = 1 ; x <= n ; ++ x ) {
                int y = x - i ;
                if ( y <= 0 || y > m ) { continue ; }
                ans += proc ( x , y ) ;
            }
        }
        cout << ans << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}