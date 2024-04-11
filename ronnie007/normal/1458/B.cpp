#include<bits/stdc++.h>
using namespace std ;

#define MAXN 101
#define OFFSET 20000

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int dp[ MAXN ][ 4 * MAXN * MAXN ] ;

double ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ] , &b[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= 2 * OFFSET ; ++ j ) {
            dp[ i ][ j ] = -1 ;
        }
    }
    dp[ 0 ][ OFFSET ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = n ; j >= 0 ; -- j ) {
            for ( int t = 2 * OFFSET ; t >= 0 ; -- t ) {
                if ( dp[ j ][ t ] == -1 ) { continue ; }
                if ( j <= n ) {
                    dp[ j + 1 ][ t - 2 * ( a[ i ] - b[ i ] ) ] = max ( dp[ j + 1 ][ t - 2 * ( a[ i ] - b[ i ] ) ] , dp[ j ][ t ] + a[ i ] ) ;
                }
                dp[ j ][ t + b[ i ] ] = max ( dp[ j ][ t + b[ i ] ] , dp[ j ][ t ] ) ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= 2 * OFFSET ; ++ j ) {
            if ( dp[ i ][ j ] == -1 ) { continue ; }
            ans[ i ] = max ( ans[ i ] , dp[ i ][ j ] - ( max ( OFFSET - j , 0 ) ) / 2.0 ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%.12lf " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
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