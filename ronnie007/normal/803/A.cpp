#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

#define MAXN 107

int n , k ;
int a[ MAXN ][ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;

}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= n ; j ++ ) {
            if ( k == 0 ) { break ; }
            if ( a[ i ][ j ] == 1 ) { continue ; }
            if ( i == j ) {
                k -- ;
                a[ i ][ j ] = 1 ;
            }
            else {
                if ( k >= 2 ) {
                    k -= 2 ;
                    a[ i ][ j ] = a[ j ][ i ] = 1 ;
                }
            }
        }
    }
    if ( k > 0 ) { printf ( "-1\n" ) ; return ; }
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= n ; j ++ ) {
            printf ( "%d " , a[ i ][ j ] ) ;
        }
        printf ( "\n" ) ;
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}