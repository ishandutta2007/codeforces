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
int a[ MAXN ][ 4 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= 4 ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    int sr = 0 ;
    int i , j ;
    for ( i = 1 ; i <= 4 ; i ++ ) {
        sr += a[ 1 ][ i ] ;
    }
    int ans = 1 ;
    for ( i = 2 ; i <= n ; i ++ ) {
        int cur = 0 ;
        for ( j = 1 ; j <= 4 ; j ++ ) {
            cur += a[ i ][ j ] ;
        }
        if ( cur > sr ) { ans ++ ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}