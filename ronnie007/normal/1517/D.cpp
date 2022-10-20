#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 501

int n , m , k ;

int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ;

int dist[ MAXN ][ MAXN ][ 4 ] ;

int dp[ 11 ][ MAXN ][ MAXN ] ;


void input ( ) {
    cin >> n >> m >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j < m ; ++ j ) {
            cin >> dist[ i ][ j ][ 2 ] ;
            dist[ i ][ j + 1 ][ 3 ] = dist[ i ][ j ][ 2 ] ;
        }
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cin >> dist[ i ][ j ][ 0 ] ;
            dist[ i + 1 ][ j ][ 1 ] = dist[ i ][ j ][ 0 ] ;
        }
    }
}


void solve ( ) {
    if ( ( k % 2 ) == 1 ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( int j = 1 ; j <= m ; ++ j ) {
                cout << "-1 " ;
            }
            cout << "\n" ;
        }
        return ;
    }
    k /= 2 ;

    for ( int t = 1 ; t <= k ; ++ t ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( int j = 1 ; j <= m ; ++ j ) {
                int cand = -1 ;
                for ( int dir = 0 ; dir < 4 ; ++ dir ) {
                    int nx = i + dx[ dir ] ;
                    int ny = j + dy[ dir ] ;
                    if ( nx < 1 || n < nx ) { continue ; }
                    if ( ny < 1 || m < ny ) { continue ; }
                    int sr = dp[ t - 1 ][ nx ][ ny ] + 2 * dist[ i ][ j ][ dir ] ;
                    if ( cand < 0 || cand > sr ) { cand = sr ; }
                }
                dp[ t ][ i ][ j ] = cand ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cout << dp[ k ][ i ][ j ] << " " ;
        }
        cout << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}