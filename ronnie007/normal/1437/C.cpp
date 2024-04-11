#include<bits/stdc++.h>
using namespace std ;

#define inf 1000000007
#define MAXN 707

int n ;
int a[ MAXN ] ;

int dp[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= 3 * n ; ++ j ) {
            dp[ i ][ j ] = inf ;
        }
    }
    dp[ 0 ][ 0 ] = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j <= 3 * n ; ++ j ) {
            for ( int t = j + 1 ; t <= 3 * n ; ++ t ) {
                dp[ i + 1 ][ t ] = min ( dp[ i + 1 ][ t ] , dp[ i ][ j ] + abs ( a[ i + 1 ] - t ) ) ;
            }
        }
    }
    int ans = inf ;
    for ( int i = 0 ; i <= 3 * n ; ++ i ) {
        ans = min ( ans , dp[ n ][ i ] ) ;
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