#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

int fst[ MAXN ] ;
int lst[ MAXN ] ;

void input ( ) {
    int k ;
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        fst[ i ] = MAXN ;
    }
    for ( int i = 1 ; i <= k ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        lst[ x ] = i ;
        if ( fst[ x ] == MAXN ) { fst[ x ] = i ; }
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = -1 ; j <= 1 ; ++ j ) {
            int nw = i + j ;
            if ( nw < 1 || n < nw ) { continue ; }
            if ( lst[ i ] < fst[ nw ] ) {
                ++ ans ;
            }
        }
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