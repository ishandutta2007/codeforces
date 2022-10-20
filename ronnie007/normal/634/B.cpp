#include<bits/stdc++.h>
using namespace std ;

long long sm , xr ;

long long dp[ 50 ][ 2 ] ;

void input ( ) {
    scanf ( "%lld%lld" , &sm , &xr ) ;
}

void solve ( ) {
    dp[ 0 ][ 0 ] = 1 ;
    for ( int i = 0 ; i <= 48 ; ++ i ) {
        long long bit = ( 1LL << i ) ;
        int sm_target = ( ( sm & bit ) > 0 ) ;
        int xr_target = ( ( xr & bit ) > 0 ) ;
        for ( int carry = 0 ; carry < 2 ; ++ carry ) {
            if ( dp[ i ][ carry ] == 0 ) { continue ; }
            for ( int j = 0 ; j < 2 ; ++ j ) {
                for ( int t = 0 ; t < 2 ; ++ t ) {
                    if ( ( carry ^ j ^ t ) == sm_target && ( j ^ t ) == xr_target ) {
                        dp[ i + 1 ][ ( carry + j + t ) >= 2 ] += dp[ i ][ carry ] ;
                    }
                }
            }
        }
    }
    if ( sm == xr ) { dp[ 49 ][ 0 ] -= 2 ; } 
    printf ( "%lld\n" , dp[ 49 ][ 0 ] ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}