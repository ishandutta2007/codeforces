#include<bits/stdc++.h>
using namespace std ;

#define MAXN 30007

int n ;
int a[ MAXN ] ;
int pref[ MAXN ] ;
int suff[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int x = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] < x ) {
            printf ( "NO\n" ) ;
            return ;
        }
        a[ i ] -= x ;
        if ( a[ i ] > a[ i - 1 ] ) {
            x += a[ i ] - a[ i - 1 ] ;
            a[ i ] = a[ i - 1 ] ;
        }
    }
    printf ( "YES\n" ) ;
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