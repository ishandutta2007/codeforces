#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , k ;
int a[ MAXN ] ;
int pref[ MAXN ] ;

int cnt ;


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] == k ) { ++ cnt ; }
    }
    if ( cnt == 0 ) {
        printf ( "no\n" ) ;
        return ;
    }
    if ( cnt == n ) {
        printf ( "yes\n" ) ;
        return ;
    }
    pref[ 0 ] = 0 ;
    int mn = 2 * MAXN ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = pref[ i - 1 ] ;
        if ( a[ i ] >= k ) { ++ pref[ i ] ; }
        else { -- pref[ i ] ; }
        if ( pref[ i ] > mn ) {
            printf ( "yes\n" ) ;
            return ;
        }
        if ( mn > pref[ i - 1 ] ) {
            mn = pref[ i - 1 ] ;
        }
    }
    printf ( "no\n" ) ;
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