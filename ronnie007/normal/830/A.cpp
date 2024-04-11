#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std ;

#define MAXN 2007

int n , m , p ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int dp[ MAXN ][ MAXN ] ;

int f ( int x , int y ) {
    return ( abs ( a[ x ] - b[ y ] ) + abs ( b[ y ] - p ) ) ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &p ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    sort ( b + 1 , b + m + 1 ) ;
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i <= n ; i ++ ) {
        for ( j = 0 ; j <= m ; j ++ ) {
            dp[ i ][ j ] = -1 ;
        }
    }
    dp[ 0 ][ 0 ] = 0 ;
    for ( i = 0 ; i <= n ; i ++ ) {
        for ( j = 0 ; j <= m ; j ++ ) {
            if ( dp[ i ][ j ] == -1 ) { continue ; }
            if ( dp[ i ][ j + 1 ] == -1 || dp[ i ][ j + 1 ] > dp[ i ][ j ] ) {
                dp[ i ][ j + 1 ] = dp[ i ][ j ] ;
            }
            int val = max ( dp[ i ][ j ] , f ( i + 1 , j + 1 ) ) ;
            if ( dp[ i + 1 ][ j + 1 ] == -1 || dp[ i + 1 ][ j + 1 ] > val ) {
                dp[ i + 1 ][ j + 1 ] = val ;
            }
        }
    }
    printf ( "%d\n" , dp[ n ][ m ] ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}