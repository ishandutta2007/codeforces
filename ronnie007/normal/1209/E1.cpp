#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 107
#define inf 100000007
int lim ;

int n , m ;
int a[ MAXN ][ MAXN ] ;

int dp[ 17 ] ;
int nw[ 17 ] ;

int get_shift ( int mask ) {
    int lst = ( mask & (lim/2) ) ;
    mask -= lst ;
    mask *= 2 ;
    mask += ( lst != 0 ) ;
    return mask ;
}

int get_val ( int c , int mask ) {
    int ret = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( ( mask & (1<<i) ) != 0 ) {
            ret += a[ i + 1 ][ c ] ;
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
    lim = (1<<n) ;
}

void solve ( ) {
    for ( int i = 0 ; i < lim ; ++ i ) {
        dp[ i ] = -inf ;
    }
    dp[ 0 ] = 0 ;
    for ( int j = 1 ; j <= m ; ++ j ) {
        for ( int cm = 0 ; cm < lim ; ++ cm ) {
            nw[ cm ] = dp[ cm ] ;
        }
        for ( int mask = 1 ; mask < lim ; ++ mask ) {
            int aux = mask ;
            int val = get_val ( j , mask ) ;
            for ( int j = 0 ; j < n ; ++ j ) {
                for ( int cm = 0 ; cm < lim ; ++ cm ) {
                    if ( dp[ cm ] < 0 ) { continue ; }
                    if ( ( cm & aux ) == 0 ) {
                        nw[ cm | aux ] = max ( nw[ cm | aux ] , dp[ cm ] + val ) ;
                    }
                }
                aux = get_shift ( aux ) ;
            }
        }
        for ( int cm = 0 ; cm < lim ; ++ cm ) {
            dp[ cm ] = max ( dp[ cm ] , nw[ cm ] ) ;
        }
    }
    printf ( "%d\n" , dp[ lim - 1 ] ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }

    return 0 ;
}