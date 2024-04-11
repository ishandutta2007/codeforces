#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 5007 ;

int n , k ;
string a , b ;

int mn_unused[ MAXN ][ MAXN ] ;
int mx_unused[ MAXN ][ MAXN ] ;

void solve ( ) {
    cin >> n >> k ;
    cin >> a >> b ;
    int tp = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( tp == k ) { break ; }
        if ( b[ tp ] == a[ i ] ) { ++ tp ; }
    }
    if ( tp < k ) {
        cout << "-1\n" ;
        return ;
    }
    for ( int i = 0 ; i <= n - k ; ++ i ) {
        for ( int j = 0 ; j <= n + 1 ; ++ j ) {
            mn_unused[ i ][ j ] = MAXN ;
            mx_unused[ i ][ j ] = -1 ;
        }
    }
    mn_unused[ 0 ][ 0 ] = 0 ;
    mx_unused[ 0 ][ n + 1 ] = n + 1 ;
    for ( int i = 0 ; i <= n - k ; ++ i ) {
        for ( int j = i ; j < n ; ++ j ) {
            if ( mn_unused[ i ][ j ] == MAXN ) { continue ; }
            if ( i < n - k ) {
                mn_unused[ i + 1 ][ j + 1 ] = min ( mn_unused[ i + 1 ][ j + 1 ] , j + 1 ) ;
            }
            int wh = j - i ;
            if ( wh < k && a[ j ] == b[ wh ] ) {
                mn_unused[ i ][ j + 1 ] = min ( mn_unused[ i ][ j + 1 ] , mn_unused[ i ][ j ] ) ;
            }
        }
    }
    for ( int i = 0 ; i <= n - k ; ++ i ) {
        for ( int j = n + 1 ; j >= 2 ; -- j ) {
            if ( mx_unused[ i ][ j ] == -1 ) { continue ; }
            if ( i < n - k ) {
                mx_unused[ i + 1 ][ j - 1 ] = max ( mx_unused[ i + 1 ][ j - 1 ] , j - 1 ) ;
            }
            int lft = n - ( j + i ) + 1 ;
            int wh = k - lft - 1 ;
            if ( wh >= 0 && a[ j - 2 ] == b[ wh ] ) {
                mx_unused[ i ][ j - 1 ] = max ( mx_unused[ i ][ j - 1 ] , mx_unused[ i ][ j ] ) ;
            }
        }
    }
    int ans = MAXN * MAXN ;
    for ( int i = 0 ; i <= n - k ; ++ i ) {
        for ( int j = 0 ; j <= n ; ++ j ) {
            if ( mn_unused[ i ][ j ] == MAXN || mx_unused[ n - k - i ][ j + 1 ] == -1 ) { continue ; }
            int cand = 0 ;
            if ( n - k - i > 0 ) {
                cand += n - mx_unused[ n - k - i ][ j + 1 ] + 1 ;
            }
            if ( i != 0 ) {
                ++ cand ;
                cand += mn_unused[ i ][ j ] ;
                cand += i ;
            }
            ans = min ( ans , cand ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}