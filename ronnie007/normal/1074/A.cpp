#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int cnt[ MAXN ] ;
int init ;

int f ( int x ) {
    int l , r , mid ;
    l = 1 ;
    r = n ;
    if ( a[ l ] > x ) { return 0 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ mid ] <= x ) { l = mid ; }
        else { r = mid ; }
    }
    while ( a[ r ] > x ) { -- r ; }
    return r ;
}

void input ( ) {
    int m ;
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y , z ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        if ( x != 1 ) { continue ; }
        if ( y == 1000000000 ) { ++ init ; continue ; }
        int id = f ( y ) ;
        if ( id > 0 ) {
            ++ cnt[ id - 1 ] ;
        }
    }
    for ( int i = n - 2 ; i >= 0 ; -- i ) {
        cnt[ i ] += cnt[ i + 1 ] ;
    }
}

void solve ( ) {
    int ans = 2 * MAXN ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        int aux = init + cnt[ i ] + i ;
        ans = min ( ans , aux ) ;
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