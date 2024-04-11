#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n , m ;
long long dp[ MAXN ][ MAXN ] ;

int prv[ MAXN ][ MAXN ] ;
int nxt[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int sz ;
        cin >> sz ;
        for ( int j = 1 ; j <= sz ; ++ j ) {
            int l , r ;
            cin >> l >> r ;
            for ( int t = l ; t <= r ; ++ t ) {
                prv[ i ][ t ] = l ;
                nxt[ i ][ t ] = r ;
            }
        }
    }
}

void solve ( ) {
    for ( int len = 0 ; len < m ; ++ len ) {
        for ( int i = 1 ; i + len <= m ; ++ i ) {
            int j = i + len ;
            for ( int t = i ; t <= j ; ++ t ) {
                int cnt = 0 ;
                for ( int z = 1 ; z <= n ; ++ z ) {
                    if ( prv[ z ][ t ] >= i && nxt[ z ][ t ] <= j ) { ++ cnt ; }
                }
                dp[ i ][ j ] = max ( dp[ i ][ j ] , dp[ i ][ t - 1 ] + dp[ t + 1 ][ j ] + cnt * cnt ) ;
            }
        }
    }
    cout << dp[ 1 ][ m ] << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}