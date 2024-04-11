#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define MAXVAL 201
#define MOD 998244353

int n ;
int a[ MAXN ] ;

long long dp[ 2 ][ MAXVAL + 1 ][ 2 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }    
}

void solve ( ) {
    int prv = 0 ;
    int nxt = 1 ;
    if ( a[ 1 ] > 0 ) {
        dp[ prv ][ a[ 1 ] ][ 0 ] = 1 ;
    }
    else {
        for ( int i = 1 ; i < MAXVAL ; ++ i ) {
            dp[ prv ][ i ][ 0 ] = 1 ;
        }
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] != -1 ) {
            for ( int j = 1 ; j < a[ i ] ; ++ j ) {
                dp[ nxt ][ a[ i ] ][ 0 ] += dp[ prv ][ j ][ 0 ] ;
                if ( dp[ nxt ][ a[ i ] ][ 0 ] >= MOD ) {
                    dp[ nxt ][ a[ i ] ][ 0 ] -= MOD ;
                }
                dp[ nxt ][ a[ i ] ][ 0 ] += dp[ prv ][ j ][ 1 ] ;
                if ( dp[ nxt ][ a[ i ] ][ 0 ] >= MOD ) {
                    dp[ nxt ][ a[ i ] ][ 0 ] -= MOD ;
                }
            }
            for ( int j = a[ i ] ; j < MAXVAL ; ++ j ) {
                dp[ nxt ][ a[ i ] ][ 1 ] += dp[ prv ][ j ][ 1 ] ;
                if ( dp[ nxt ][ a[ i ] ][ 1 ] >= MOD ) {
                    dp[ nxt ][ a[ i ] ][ 1 ] -= MOD ;
                }
                if ( j == a[ i ] ) {
                    dp[ nxt ][ a[ i ] ][ 1 ] += dp[ prv ][ j ][ 0 ] ;
                    if ( dp[ nxt ][ a[ i ] ][ 1 ] >= MOD ) {
                        dp[ nxt ][ a[ i ] ][ 1 ] -= MOD ;
                    }
                }
            }
        }
        else {
            for ( int j = 1 ; j < MAXVAL ; ++ j ) {
                dp[ nxt ][ j ][ 0 ] = dp[ nxt ][ j - 1 ][ 0 ] ;
                dp[ nxt ][ j ][ 0 ] += dp[ prv ][ j - 1 ][ 0 ] ;
                if ( dp[ nxt ][ j ][ 0 ] >= MOD ) {
                    dp[ nxt ][ j ][ 0 ] -= MOD ;
                }
                dp[ nxt ][ j ][ 0 ] += dp[ prv ][ j - 1 ][ 1 ] ;
                if ( dp[ nxt ][ j ][ 0 ] >= MOD ) {
                    dp[ nxt ][ j ][ 0 ] -= MOD ;
                }
            }
            for ( int j = MAXVAL - 1 ; j >= 1 ; -- j ) {
                dp[ nxt ][ j ][ 1 ] = dp[ nxt ][ j + 1 ][ 1 ] ;
                dp[ nxt ][ j ][ 1 ] = ( dp[ nxt ][ j ][ 1 ] + MOD - dp[ prv ][ j + 1 ][ 0 ] ) ;
                if ( dp[ nxt ][ j ][ 1 ] >= MOD ) {
                    dp[ nxt ][ j ][ 1 ] -= MOD ;
                }

                dp[ nxt ][ j ][ 1 ] += dp[ prv ][ j ][ 1 ] ;
                if ( dp[ nxt ][ j ][ 1 ] >= MOD ) {
                    dp[ nxt ][ j ][ 1 ] -= MOD ;
                }
                dp[ nxt ][ j ][ 1 ] += dp[ prv ][ j ][ 0 ] ;
                if ( dp[ nxt ][ j ][ 1 ] >= MOD ) {
                    dp[ nxt ][ j ][ 1 ] -= MOD ;
                }
            }
        }
        for ( int j = 0 ; j < MAXVAL ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                dp[ prv ][ j ][ t ] = 0 ;
            }
        }
        prv ^= 1 ; nxt ^= 1 ;
    }
    int ans = 0 ;
    for ( int i = 1 ; i < MAXVAL ; ++ i ) {
        ans += dp[ prv ][ i ][ 1 ] ;
        if ( ans >= MOD ) { ans -= MOD ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}