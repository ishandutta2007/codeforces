#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507
#define inf 1000000007

int n , len , k ;
int x[ MAXN ] ;
int a[ MAXN ] ;

int dp[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n >> len >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> x[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    ++ n ;
    x[ n ] = len ;
    a[ n ] = 0 ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= n ; ++ j ) {
            dp[ i ][ j ] = inf ;
        }
    }
    dp[ 1 ][ 1 ] = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        for ( int j = 2 ; j <= n ; ++ j ) {
            for ( int t = 1 ; t < i ; ++ t ) {
                dp[ i ][ j ] = min ( dp[ i ][ j ] , dp[ t ][ j - 1 ] + ( x[ i ] - x[ t ] ) * a[ t ] ) ;
            }
        }
    }
    int st = n - k ;
    int ans = dp[ n ][ n ] ;
    for ( int i = st ; i <= n ; ++ i ) {
        ans = min ( ans , dp[ n ][ i ] ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}