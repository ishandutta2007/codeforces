#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

long long pref[ MAXN ] ;


long long add[ MAXN ] ;

long long tm[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
        pref[ i ] = ( pref[ i - 1 ] + b[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int l , r , mid ;
        l = i ;
        r = n ;
        while ( r - l > 3 ) {
            mid = ( l + r ) / 2 ;
            long long cur = pref[ mid ] - pref[ i - 1 ] ;
            if ( cur <= a[ i ] ) { l = mid ; }
            else { r = mid ; }
        }
        while ( l <= n ) {
            long long cur = pref[ l ] - pref[ i - 1 ] ;
            if ( cur <= a[ i ] ) { l ++ ; }
            else { break ; }
        }
        l -- ;
        if ( i <= l ) {
            tm[ i ] ++ ;
            tm[ l + 1 ] -- ;
        }
        long long cur = ( a[ i ] - ( pref[ l ] - pref[ i - 1 ] ) ) ;
        add[ l + 1 ] += cur ;
    }
    long long aux = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        aux += tm[ i ] ;
        printf ( "%I64d" , aux * b[ i ] + add[ i ] ) ;
        if ( i == n ) { printf ( "\n" ) ; }
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