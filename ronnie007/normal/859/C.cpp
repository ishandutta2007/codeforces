#include<bits/stdc++.h>
using namespace std ;

#define MAXN 57

#define inf 1000000007

int n ;
int a[ MAXN ] ;

int dp[ MAXN ][ 2 ] ;

void dfs ( int pos , int id ) {
    if ( pos > n ) { return ; }
    if ( dp[ pos ][ id ] != -inf ) { return ; }
    dfs ( pos + 1 , id ) ;
    dfs ( pos + 1 , id^1 ) ;
    if ( dp[ pos ][ id ] < a[ pos ] - dp[ pos + 1 ][ (id^1) ] ) {
        dp[ pos ][ id ] = a[ pos ] - dp[ pos + 1 ][ (id^1) ] ;
    }
    if ( dp[ pos ][ id ] < dp[ pos + 1 ][ id ] - a[ pos ] ) {
        dp[ pos ][ id ] = dp[ pos + 1 ][ id ] - a[ pos ] ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i <= n ; i ++ ) {
        for ( j = 0 ; j < 2 ; j ++ ) {
            dp[ i ][ j ] = -inf ;
        }
    }
    dfs ( 1 , 0 ) ;
    int sm = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        sm += a[ i ] ;
    }
    int y = ( sm + dp[ 1 ][ 0 ] ) / 2 ;
    printf ( "%d %d\n" , sm - y , y ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}