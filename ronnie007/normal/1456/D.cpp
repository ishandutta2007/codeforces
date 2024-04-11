#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 5007
#define inf 1000000007

int n ;
long long t[ MAXN ] ;
int x[ MAXN ] ;

long long mntime[ MAXN ] ;
bool dp[ MAXN ][ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%lld%d" , &t[ i ] , &x[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        mntime[ i ] = inf ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( mntime[ i ] <= t[ i ] ) {
            mntime[ i + 1 ] = min ( mntime[ i + 1 ] , max ( t[ i ] , mntime[ i ] + abs ( x[ i + 1 ] - x[ i ] ) ) ) ;
            for ( int j = i + 2 ; j <= n ; ++ j ) {
                if ( max ( t[ i ] , mntime[ i ] + abs ( x[ j ] - x[ i ] ) ) + abs ( x[ i + 1 ] - x[ j ] ) <= t[ i + 1 ] ) {
                    dp[ i + 1 ][ j ] = true ;
                }
            }
        }
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            if ( dp[ i ][ j ] == false ) { continue ; }
            if ( j == i + 1 ) {
                mntime[ i + 2 ] = min ( mntime[ i + 2 ] , max ( t[ i + 1 ] , t[ i ] + abs ( x[ i + 2 ] - x[ i ] ) ) ) ;
                for ( int nw = i + 3 ; nw <= n ; ++ nw ) {
                    if ( max ( t[ i + 1 ] , t[ i ] + abs ( x[ nw ] - x[ i ] ) ) + abs ( x[ nw ] - x[ i + 2 ] ) <= t[ i + 2 ] ) {
                        dp[ i + 2 ][ nw ] = true ;
                    }
                }
            }
            else {
                if ( abs ( x[ i + 1 ] - x[ i ] ) <= t[ i + 1 ] - t[ i ] ) {
                    dp[ i + 1 ][ j ] = true ; 
                }
            }
        }
    }
    if ( dp[ n - 1 ][ n ] == true || mntime[ n ] <= t[ n ] ) {
        printf ( "YES\n" ) ;
    }
    else { printf ( "NO\n" ) ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}