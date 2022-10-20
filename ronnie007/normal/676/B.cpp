#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;


int n , t ;
int a[ 17 ][ 17 ] ;


void input ( ) {
    scanf ( "%d%d" , &n , &t ) ;
}

void solve ( ) {
    int i , j ;
    a[ 1 ][ 1 ] = t * 2048 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= i ; j ++ ) {
            int lft = ( a[ i ][ j ] - 2048 ) ;
            if ( lft <= 0 ) { continue ; }
            a[ i ][ j ] -= lft ;
            a[ i + 1 ][ j ] += ( lft / 2 ) ;
            a[ i + 1 ][ j + 1 ] += ( lft / 2 ) ;
        }
    }
    int ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= i ; j ++ ) {
            ans += ( a[ i ][ j ] == 2048 ) ;
        }
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