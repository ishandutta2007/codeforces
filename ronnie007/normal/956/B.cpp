#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 100007

int n , lim ;
int a[ MAXN ] ;

int get ( int st ) {
    int l , r , mid ;
    l = st + 1 ;
    r = n ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        int diff = a[ mid ] - a[ st - 1 ] ;
        if ( diff <= lim ) { l = mid ; }
        else { r = mid ; }
    }
    while ( r > st && a[ r ] - a[ st - 1 ] > lim ) { r -- ; }
    return r ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &lim ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    double mx = -1.00000000 ;
    for ( i = 2 ; i <= n ; i ++ ) {
        int id = get ( i ) ;
        if ( id <= i ) { continue ; }
        double cur = a[ id ] - a[ i ] ;
        cur /= ( a[ id ] - a[ i - 1 ] ) ;
        if ( mx < cur ) { mx = cur ; }
    }
    printf ( "%.12lf\n" , mx ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}