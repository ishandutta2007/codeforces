#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 1007

int n ;
int init ;
int a[ MAXN ] ;
int b[ MAXN ] ;


bool f ( double cur ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        double aux = ( cur + init ) / a[ i ] ;
        cur -= aux ;
        if ( cur < 0 ) { return false ; }
        aux = ( cur + init ) / b[ i + 1 ] ;
        cur -= aux ;
        if ( cur < 0 ) { return false ; }
    }
    if ( cur < 0 ) { return false ; }
    return true ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    scanf ( "%d" , &init ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
    a[ n + 1 ] = a[ 1 ] ;
    b[ n + 1 ] = b[ 1 ] ;
}

void solve ( ) {
    double l , r , mid ;
    l = 0 ;
    r = 2 ;
    int i ;
    for ( i = 1 ; i <= 9 ; i ++ ) {
        r *= 10 ;
    }
    if ( f ( r ) == false ) { printf ( "-1\n" ) ; return ; }
    for ( i = 1 ; i <= 300 ; i ++ ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    printf ( "%.12f\n" , r ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}