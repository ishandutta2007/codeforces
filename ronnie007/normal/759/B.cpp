#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

int dp[ MAXN ] ;

int f ( int sr ) {
    int l , r , mid ;
    l = 0 ;
    r = n ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( a[ mid ] <= sr ) { l = mid ; }
        else { r = mid - 1 ; }
    }
    while ( a[ r ] > sr ) { -- r ; }
    return r ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    a[ 0 ] = - MAXN ;
    dp[ 0 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ i ] = 20 + dp[ i - 1 ] ;
        int id = f ( a[ i ] - 90 ) ;
        dp[ i ] = min ( dp[ i ] , dp[ id ] + 50 ) ;
        id = f ( a[ i ] - 1440 ) ;
        dp[ i ] = min ( dp[ i ] , dp[ id ] + 120 ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d\n" , dp[ i ] - dp[ i - 1 ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}