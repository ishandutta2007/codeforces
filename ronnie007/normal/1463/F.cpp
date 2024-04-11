#include<bits/stdc++.h>
using namespace std ;

int n ;
int x , y ;

int dp[ ( 1 << 22 ) ][ 2 ] ;

void input ( ) {
    cin >> n >> x >> y ;
}

void solve ( ) {
    int prv = 0 , nxt = 1 ;
    int lim = ( 1 << 22 ) ;
    int sr = ( ( 1 << ( x - 1 ) ) | ( 1 << ( y - 1 ) ) ) ;
    int ans = 0 ;
    for ( int i = 0 ; i < x + y ; ++ i ) {
        int add = ( ( n - 1 ) / ( x + y ) ) + ( ( ( n - 1 ) % ( x + y ) ) >= i ) ;
        for ( int j = 0 ; j < lim ; ++ j ) {
            int nw = ( ( 2 * j ) & ( lim - 1 ) ) ;
            dp[ nw ][ nxt ] = max ( dp[ nw ][ nxt ] , dp[ j ][ prv ] ) ;
            if ( ( j & sr ) > 0 ) { continue ; }
            ++ nw ;
            dp[ nw ][ nxt ] = max ( dp[ nw ][ nxt ] , dp[ j ][ prv ] + add ) ;
        }
        for ( int j = 0 ; j < lim ; ++ j ) {
            dp[ j ][ prv ] = 0 ;
        }
        prv ^= 1 ; nxt ^= 1 ;
    }
    for ( int j = 0 ; j < lim ; ++ j ) {
        ans = max ( ans , dp[ j ][ prv ] ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}