#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n , x ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &x ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    if ( a[ n ] > x ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( a[ i ] == x ) { printf ( "1\n" ) ; return ; }
        }
        printf ( "2\n" ) ; return ;
    }
    int ans = ( x / a[ n ] ) ;
    if ( ( x % a[ n ] ) != 0 ) { ++ ans ; }
    printf ( "%d\n" , ans ) ;
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