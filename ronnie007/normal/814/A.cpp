#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 107

int n , m ;
int a[ MAXN ] ;
int b[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
    sort ( b + 1 , b + m + 1 ) ;
}

void solve ( ) {
    int i ;
    int id = m ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] == 0 ) {
            a[ i ] = b[ id ] ;
            id -- ;
        }
    }
    for ( i = 2 ; i <= n ; i ++ ) {
        if ( a[ i - 1 ] > a[ i ] ) { printf ( "Yes\n" ) ; return ; }
    }
    printf ( "No\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}