#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107
#define MAXVAL 100007

int n , m ;
int a[ MAXN ] ;
double dp[ 2 ][ MAXVAL ] ;

int sr ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        sr += a[ i ] ;
    }
}

void solve ( ) {
    if ( m == 1 ) {
        printf ( "1.000000\n" ) ;
        return ;
    }
    int prv = 0 , nxt = 1 ;
    dp[ prv ][ 0 ] = m - 1 ;
    for ( int t = 1 ; t <= n ; ++ t ) {
        double sm = dp[ prv ][ 0 ] ;
        for ( int i = 1 ; i <= sr ; ++ i ) {            
            if ( i >= m + 1 ) { sm -= dp[ prv ][ i - m - 1 ] ; }
            dp[ nxt ][ i ] = sm ;
            if ( i - a[ t ] >= 0 ) {
                dp[ nxt ][ i ] -= dp[ prv ][ i - a[ t ] ] ;
            }
            dp[ nxt ][ i ] /= ( m - 1 ) ;
            sm += dp[ prv ][ i ] ;
        }
        for ( int i = 0 ; i <= sr ; ++ i ) {
            dp[ prv ][ i ] = 0.0 ;
        }
        prv ^= 1 ; nxt ^= 1 ;
    }
    double ans = 1.0 ;
    for ( int i = 1 ; i < sr ; ++ i ) {
        ans += dp[ prv ][ i ] ;
    }
    printf ( "%.12lf\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}