#include<bits/stdc++.h>
using namespace std ;

#define MAXN 87
#define MAXK 11

int n , k ;
long long a[ MAXN ][ MAXN ] ;
long long dp[ MAXN ][ 2 ] ;

int col[ MAXN ] ;

vector < int > v[ 2 ] ;
int sz[ 2 ] ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            cin >> a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    int magic = 10007 ;
    long long ans = -1 ;
    while ( magic -- ) {
        v[ 0 ].clear ( ) ; v[ 1 ].clear ( ) ;
        col[ 1 ] = 0 ;
        v[ 0 ].push_back ( 1 ) ;
        for ( int i = 2 ; i <= n ; ++ i ) {
            col[ i ] = ( rand ( ) % 2 ) ;
            v[ col[ i ] ].push_back ( i ) ;
        }
        sz[ 0 ] = v[ 0 ].size ( ) ;
        sz[ 1 ] = v[ 1 ].size ( ) ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( int j = 0 ; j < 2 ; ++ j ) {
                dp[ i ][ j ] = -1 ;
            }
        }
        dp[ 1 ][ 0 ] = 0 ;
        int nxt = 1 ;
        int prv = 0 ;
        for ( int tm = 1 ; tm <= k ; ++ tm ) {
            for ( int j = 0 ; j < sz[ prv ] ; ++ j ) {
                if ( dp[ v[ prv ][ j ] ][ prv ] == -1 ) { continue ; }
                for ( int t = 0 ; t < sz[ nxt ] ; ++ t ) {
                    long long aux = dp[ v[ prv ][ j ] ][ prv ] + a[ v[ prv ][ j ] ][ v[ nxt ][ t ] ] ;
                    if ( dp[ v[ nxt ][ t ] ][ nxt ] < 0 ) { dp[ v[ nxt ][ t ] ][ nxt ] = aux ; }
                    dp[ v[ nxt ][ t ] ][ nxt ] = min ( dp[ v[ nxt ][ t ] ][ nxt ] , aux ) ;
                }
            }

            for ( int j = 1 ; j <= n ; ++ j ) {
                dp[ j ][ prv ] = -1 ;
            }
            prv ^= 1 ; nxt ^= 1 ;
        }
        if ( dp[ 1 ][ prv ] == -1 ) { continue ; }
        if ( ans < 0 ) { ans = dp[ 1 ][ prv ] ; }
        ans = min ( ans , dp[ 1 ][ prv ] ) ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}