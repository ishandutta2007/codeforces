#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

int n ;
bool dp[ 17 ][ 5507 ] ;

int precalc[ 11 ] = { 4 , 10 , 20 , 35 , 56 , 83 , 116 , 155 , 198 , 244 , 292 } ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    /**
    int i , j ;
    dp[ 0 ][ 0 ] = true ;
    for ( i = 0 ; i < n ; i ++ ) {
        for ( j = 5000 ; j >= 0 ; j -- ) {
            if ( dp[ i ][ j ] == true ) {
                dp[ i + 1 ][ j + 1 ] = true ;
                dp[ i + 1 ][ j + 5 ] = true ;
                dp[ i + 1 ][ j + 10 ] = true ;
                dp[ i + 1 ][ j + 50 ] = true ;
            }
        }
    }
    int ans = 0 ;
    for ( i = 0 ; i <= 5500 ; i ++ ) {
        ans += dp[ n ][ i ] ;
    }
    **/
    if ( n <= 11 ) { printf ( "%d\n" , precalc[ n - 1 ] ) ; }
    else { printf ( "%I64d\n" , 49LL * ( n - 11 ) + 292 ) ; }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}