#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
using namespace std ;

#define MAXN 1000007

int n , k ;
int a[ MAXN ] ;
int br[ 10 * MAXN ] ;
int pref[ 10 * MAXN ] ;


int calc ( int x , int y ) {
    if ( x < y ) { return 0 ; }
    int p , q ;
    p = 1 ;
    q = 0 ;
    while ( ( x / 2 ) >= y ) {
        if ( ( x % 2 ) == 1 ) {
            q = 2 * q + p ;
        }
        else {
            p = 2 * p + q ;
        }
        x /= 2 ;
    }
    if ( ( x + 1 ) / 2 >= y ) {
        q = 2 * q ;
    }
    return ( p + q ) ;
}

long long f ( int x ) {
    long long ret = 0 ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        ret += calc ( a[ i ] , x ) ;
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        br[ a[ i ] ] ++ ;
    }
    for ( i = 1 ; i < 10 * MAXN ; i ++ ) {
        pref[ i ] = ( pref[ i - 1 ] + br[ i ] ) ;
    }
}

void solve ( ) {
    int l , r , mid ;
    l = 1 ;
    r = 10000000 ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) >= k ) { l = mid ; }
        else { r = mid ; }
    }
    while ( r >= 1 && f ( r ) < k ) { r -- ; }
    if ( r == 0 ) { r -- ; }
    printf ( "%d\n" , r ) ;
}

int main ( ) {
    ///ios::sync_with_stdio ( false ) ;
    ///cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}