#include<bits/stdc++.h>
using namespace std ;

#define MAXN 5007

int n , m ;
string a , b ;

int dp[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    cin >> a ; a = '#' + a ;
    cin >> b ; b = '#' + b ;
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            dp[ i ][ j ] = max ( dp[ i - 1 ][ j ] - 1 , dp[ i ][ j - 1 ] - 1 ) ;
            if ( a[ i ] == b[ j ] ) {
                dp[ i ][ j ] = max ( dp[ i ][ j ] , dp[ i - 1 ][ j - 1 ] + 2 ) ;
            }
            if ( dp[ i ][ j ] < 0 ) { dp[ i ][ j ] = 0 ; }
            ans = max ( ans , dp[ i ][ j ] ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    ///scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}