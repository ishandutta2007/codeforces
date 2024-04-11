#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 1000007

int n , x , y ;
int a[ MAXN ] ;

int p , q ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &x , &y ) ;
}

void solve ( ) {
    int i ;
    int cur = 0 ;
    p = q = -1 ;
    for ( i = 0 ; i <= n ; i ++ ) {
        if ( cur > n ) { break ; }
        int lft = ( n - cur ) ;
        if ( ( lft % y ) == 0 ) {
            p = i ;
            q = ( lft / y ) ;
            break ;
        }
        cur += x ;
    }
    if ( p < 0 || q < 0 ) { printf ( "-1\n" ) ; return ; }
    int pos = 1 ;
    while ( p != 0 ) {
        p -- ;
        a[ pos ] = pos + x - 1 ;
        for ( i = 0 ; i < x - 1 ; i ++ ) {
            a[ pos + i + 1 ] = pos + i ;
        }
        pos += x ;
    }
    while ( q != 0 ) {
        q -- ;
        a[ pos ] = pos + y - 1 ;
        for ( i = 0 ; i < y - 1 ; i ++ ) {
            a[ pos + i + 1 ] = pos + i ;
        }
        pos += y ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d" , a[ i ] ) ;
        if ( i == n ) { printf ( "\n" ) ; }
        else { printf( " " ) ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}