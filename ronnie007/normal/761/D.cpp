#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
using namespace std ;

#define MAXN 100007

int n , l , r ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int pos[ MAXN ] ;

int ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &l , &r ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
        b[ i ] = ( n - b[ i ] + 1 ) ;
        pos[ b[ i ] ] = i ;
    }
}

void solve ( ) {
    int i ;
    ans[ pos[ 1 ] ] = r ;
    int sr = a[ pos[ 1 ] ] - r ;
    for ( i = 2 ; i <= n ; i ++ ) {
        int id = pos[ i ] ;
        int lo , hi , mid ;
        lo = l ;
        hi = r ;
        while ( hi - lo > 3 ) {
            mid = ( lo + hi ) / 2 ;
            if ( a[ id ] - mid <= sr ) { hi = mid ; }
            else { lo = mid ; }
        }
        while ( hi >= l && a[ id ] - hi <= sr ) { hi -- ; }
        if ( hi < l || a[ id ] - hi <= sr ) { printf ( "-1\n" ) ; return ; }
        ans[ id ] = hi ;
        sr = a[ id ] - hi ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}