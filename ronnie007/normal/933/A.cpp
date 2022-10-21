#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 2007

int n ;
int a[ MAXN ] ;

int pref[ MAXN ][ 3 ] ;
int suff[ MAXN ][ 3 ] ;
int p[ 3 ] ;
int br[ 3 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j , t , z ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int mx = 0 ;
        for ( j = 1 ; j <= a[ i ] ; j ++ ) {
            if ( mx < pref[ i - 1 ][ j ] ) {
                mx = pref[ i - 1 ][ j ] ;
            }
        }
        pref[ i ][ 1 ] = pref[ i - 1 ][ 1 ] ;
        pref[ i ][ 2 ] = pref[ i - 1 ][ 2 ] ;
        pref[ i ][ a[ i ] ] = mx + 1 ;
    }
    for ( i = n ; i >= 1 ; i -- ) {
        int mx = 0 ;
        for ( j = a[ i ] ; j <= 2 ; j ++ ) {
            if ( mx < suff[ i + 1 ][ j ] ) {
                mx = suff[ i + 1 ][ j ] ;
            }
        }
        suff[ i ][ 1 ] = suff[ i + 1 ][ 1 ] ;
        suff[ i ][ 2 ] = suff[ i + 1 ][ 2 ] ;
        suff[ i ][ a[ i ] ] = mx + 1 ;
    }
    int ans = 0 ;

    for ( j = 1 ; j <= n ; j ++ ) {
        p[ 1 ] = p[ 2 ] = 0 ;
        br[ 1 ] = br[ 2 ] = 0 ;
        for ( i = j ; i >= 1 ; i -- ) {
            int mx = 0 ;
            for ( t = 1 ; t <= a[ i ] ; t ++ ) {
                if ( mx < p[ t ] ) {
                    mx = p[ t ] ;
                }
            }
            br[ a[ i ] ] ++ ;
            p[ a[ i ] ] = mx + 1 ;
            for ( t = 1 ; t <= 2 ; t ++ ) {
                for ( z = t ; z <= 2 ; z ++ ) {
                    int cur = pref[ i - 1 ][ t ] + suff[ j + 1 ][ z ] ;
                    if ( t == 1 ) { cur += p[ z ] ; }
                    else { cur += br[ 2 ] ; }
                    if ( ans < cur ) { ans = cur ; }
                }
            }
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}