#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;


long long l , r ;

long long dp[ 35 ][ 2 ][ 2 ][ 2 ][ 2 ] ;

void input ( ) {
    cin >> l >> r ;
}

void solve ( ) {
    for ( int i = 0 ; i <= 33 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                for ( int z = 0 ; z < 2 ; ++ z ) {
                    for ( int k = 0 ; k < 2 ; ++ k ) {
                        dp[ i ][ j ][ t ][ z ][ k ] = 0 ;
                    }
                }
            }
        }
    }
    dp[ 30 ][ 1 ][ 1 ][ 1 ][ 1 ] = 1 ;
    for ( int i = 30 ; i >= 1 ; -- i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                for ( int z = 0 ; z < 2 ; ++ z ) {
                    for ( int k = 0 ; k < 2 ; ++ k ) {
                        if ( dp[ i ][ j ][ t ][ z ][ k ] == 0 ) { continue ; }
                        int h1 = 0 ;
                        if ( ( r & (1<<(i-1)) ) != 0 ) { h1 = 1 ; }
                        int h2 = 0 ;
                        if ( ( l & (1<<(i-1)) ) != 0 ) { h2 = 1 ; }

                        int st1 , en1 ;
                        if ( j == 1 && h1 == 0 ) { en1 = 0 ; }
                        else { en1 = 1 ; }
                        if ( t == 1 && h2 == 1 ) { st1 = 1 ; }
                        else { st1 = 0 ; }

                        int st2 , en2 ;
                        if ( z == 1 && h1 == 0 ) { en2 = 0 ; }
                        else { en2 = 1 ; }
                        if ( k == 1 && h2 == 1 ) { st2 = 1 ; }
                        else { st2 = 0 ; }

                        for ( int nw1 = st1 ; nw1 <= en1 ; ++ nw1 ) {
                            for ( int nw2 = st2 ; nw2 <= en2 ; ++ nw2 ) {
                                if ( nw1 == 1 && nw2 == 1 ) { continue ; }
                                int id1 = j ;
                                if ( nw1 < h1 ) { id1 = 0 ; }
                                int id2 = t ;
                                if ( nw1 > h2 ) { id2 = 0 ; }

                                int id3 = z ;
                                if ( nw2 < h1 ) { id3 = 0 ; }
                                int id4 = k ;
                                if ( nw2 > h2 ) { id4 = 0 ; }
                                dp[ i - 1 ][ id1 ][ id2 ][ id3 ][ id4 ] += dp[ i ][ j ][ t ][ z ][ k ] ;
                            }
                        }
                    }
                }
            }
        }
    }
    long long ans = 0 ;
    for ( int j = 0 ; j < 2 ; ++ j ) {
        for ( int t = 0 ; t < 2 ; ++ t ) {
            for ( int z = 0 ; z < 2 ; ++ z ) {
                for ( int k = 0 ; k < 2 ; ++ k ) {
                    ans += dp[ 0 ][ j ][ t ][ z ][ k ] ;
                }
            }
        }
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