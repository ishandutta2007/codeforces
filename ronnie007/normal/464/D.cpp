#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAGIC 600

int n , k ;

double dp[ 2 ][ MAGIC ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    int prv = 0 , nxt = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j < MAGIC ; ++ j ) {
            dp[ nxt ][ j ] = ( ( k - 1 ) / (double)k ) * dp[ prv ][ j ] ;
            dp[ nxt ][ j ] += ( 1.0 / k ) * ( j / (double)( j + 1 ) ) * ( dp[ prv ][ j ] + ( j * ( j + 1 ) / 2.0 ) / j ) ;
            if ( j + 1 < MAGIC ) {
                dp[ nxt ][ j ] += ( 1.0 / k ) * ( 1.0 / ( j + 1 ) ) * ( dp[ prv ][ j + 1 ] + j ) ;
            }
        }
        prv ^= 1 ; nxt ^= 1 ;
    }
    printf ( "%.15lf\n" , ( dp[ prv ][ 1 ] * k ) ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}