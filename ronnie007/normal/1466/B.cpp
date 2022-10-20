#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

int cnt[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 0 ; i <= 2 * n + 3 ; ++ i ) {
        cnt[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        ++ cnt[ a[ i ] ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 2 * n ; i >= 1 ; -- i ) {
        if ( cnt[ i ] == 0 ) { continue ; }
        if ( cnt[ i ] == 1 ) {
            ++ ans ;
            if ( cnt[ i + 1 ] == 0 ) {
                cnt[ i ] = 0 ;
            }
        }
        else {
            ++ ans ;
            if ( cnt[ i + 1 ] == 0 ) {
                ++ ans ;
            }
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // t = 1 ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}