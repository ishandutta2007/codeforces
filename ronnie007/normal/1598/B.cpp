#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ][ 7 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= 5 ; ++ j ) {
            cin >> a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= 5 ; ++ i ) {
        for ( int j = i + 1 ; j <= 5 ; ++ j ) {
            int cnt[ 2 ][ 2 ] ;
            for ( int x = 0 ; x < 2 ; ++ x ) {
                for ( int y = 0 ; y < 2 ; ++ y ) {
                    cnt[ x ][ y ] = 0 ;
                }
            }
            for ( int t = 1 ; t <= n ; ++ t ) {
                ++ cnt[ a[ t ][ i ] ][ a[ t ][ j ] ] ;
            }
            if ( cnt[ 0 ][ 0 ] > 0 ) { continue ; }
            if ( cnt[ 0 ][ 1 ] > ( n / 2 ) ) { continue ; }
            if ( cnt[ 1 ][ 0 ] > ( n / 2 ) ) { continue ; }
            cout << "YES\n" ;
            return ;
        }
    }
    cout << "NO\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    ///scanf ( "%d" , &t ) ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}