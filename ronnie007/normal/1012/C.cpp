#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
using namespace std ;

#define MAXN 5007
#define inf 1000000007

int n ;
int a[ MAXN ] ;
int dp[ MAXN ][ MAXN ] ;
int pref[ MAXN ][ MAXN ] ;

int ans[ MAXN ] ;

void upd ( int &best , int cur ) {
    if ( best > cur ) { best = cur ; }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j , t ;
    for ( i = 1 ; i <= n ; i ++ ) {
        ans[ i ] = inf ;
        for ( j = 1 ; j <= n ; j ++ ) {
            dp[ i ][ j ] = pref[ i ][ j ] = inf ;
        }
    }
    for ( j = 1 ; j <= ( i + 1 ) / 2 ; j ++ ) {
        for ( i = 2 * j - 1 ; i <= n ; i ++ ) {
            int aux1 = 0 ;
            if ( j > 1 && i >= 2 ) {
                int g = min ( a[ i ] , a[ i - 2 ] ) ;
                if ( g <= a[ i - 1 ] ) {
                    aux1 = a[ i - 1 ] - g + 1 ;
                }
                upd ( dp[ i ][ j ] , dp[ i - 2 ][ j - 1 ] + aux1 ) ;
            }
            aux1 = 0 ;
            if ( i > 1 && a[ i ] <= a[ i - 1 ] ) {
                aux1 = a[ i - 1 ] - a[ i ] + 1 ;
            }
            if ( j == 1 ) { upd ( dp[ i ][ j ] , aux1 ) ; }
            if ( i >= 4 ) {
                upd ( dp[ i ][ j ] , pref[ i - 3 ][ j - 1 ] + aux1 ) ;
            }
            if ( i == n ) { upd ( ans[ j ] , dp[ i ][ j ] ) ; }
        }
        for ( i = 2 * j - 1 ; i < n ; i ++ ) {
            int cur = dp[ i ][ j ] ;
            if ( a[ i ] <= a[ i + 1 ] ) { cur += ( a[ i + 1 ] - a[ i ] + 1 ) ; }
            upd ( ans[ j ] , cur ) ;
            pref[ i ][ j ] = cur ;
            if ( i > 2 * j - 1 ) { upd ( pref[ i ][ j ] , pref[ i - 1 ][ j ] ) ; }
        }
    }
    for ( i = 1 ; i <= ( n + 1 ) / 2 ; i ++ ) {
        printf ( "%d" , ans[ i ] ) ;
        if ( i == ( n + 1 ) / 2 ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}