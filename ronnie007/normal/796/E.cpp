#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1003
#define MAXK 53

int n , p , k ;

bool a[ 2 ][ MAXN ] ;

int dp[ 2 ][ MAXN ][ MAXK ][ MAXK ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &p , &k ) ;
    for ( int t = 0 ; t < 2 ; ++ t ) {
        int sz ; scanf ( "%d" , &sz ) ;
        for ( int i = 1 ; i <= sz ; ++ i ) {
            int x ; scanf ( "%d" , &x ) ;
            a[ t ][ x ] = true ;
        }
    }
}

void solve ( ) {
    if ( 2 * ( ( n + k - 1 ) / k ) <= p ) {
        int ans = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            ans += ( a[ 0 ][ i ] | a[ 1 ][ i ] ) ;
        }
        printf ( "%d\n" , ans ) ;
        return ;
    }
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j <= p ; ++ j ) {
            for ( int t = 0 ; t <= k ; ++ t ) {
                for ( int z = 0 ; z <= k ; ++ z ) {
                    dp[ i ][ j ][ t ][ z ] = -1 ;
                }
            }
        }
    }
    int prv = 0 , nxt = 1 ;
    dp[ 0 ][ 0 ][ 0 ][ 0 ] = 0 ;
    dp[ 0 ][ 1 ][ k - 1 ][ 0 ] = a[ 0 ][ 1 ] ;
    dp[ 0 ][ 1 ][ 0 ][ k - 1 ] = max ( dp[ 0 ][ 1 ][ 0 ][ k - 1 ] , (int)a[ 1 ][ 1 ] ) ;
    dp[ 0 ][ 2 ][ k - 1 ][ k - 1 ] = ( a[ 0 ][ 1 ] | a[ 1 ][ 1 ] ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= p ; ++ j ) {
            for ( int t = 0 ; t < k ; ++ t ) {
                for ( int z = 0 ; z < k ; ++ z ) {
                    if ( dp[ prv ][ j ][ t ][ z ] == -1 ) { continue ; }
                    for ( int u1 = 0 ; u1 < 2 ; ++ u1 ) {
                        for ( int u2 = 0 ; u2 < 2 ; ++ u2 ) {
                            int nx = t , ny = z ;
                            if ( u1 == 1 ) { nx = k ; }
                            if ( u2 == 1 ) { ny = k ; }
                            int add = 0 ;
                            if ( nx > 0 && a[ 0 ][ i ] == true ) { add = 1 ; }
                            if ( ny > 0 && a[ 1 ][ i ] == true ) { add = 1 ; }
                            dp[ nxt ][ j + u1 + u2 ][ max ( 0 , nx - 1 ) ][ max ( 0 , ny - 1 ) ] =
                                max ( dp[ nxt ][ j + u1 + u2 ][ max ( 0 , nx - 1 ) ][ max ( 0 , ny - 1 ) ] , dp[ prv ][ j ][ t ][ z ] + add ) ;
                        }
                    }
                }
            }
        }

        for ( int j = 0 ; j <= p ; ++ j ) {
            for ( int t = 0 ; t <= k ; ++ t ) {
                for ( int z = 0 ; z <= k ; ++ z ) {
                    dp[ prv ][ j ][ t ][ z ] = -1 ;
                }
            }
        }
        prv ^= 1 ; nxt ^= 1 ;
    }
    int ans = 0 ;
    for ( int j = 0 ; j <= p ; ++ j ) {
        for ( int t = 0 ; t < k ; ++ t ) {
            for ( int z = 0 ; z < k ; ++ z ) {
                ans = max ( ans , dp[ prv ][ j ][ t ][ z ] ) ;
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
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}