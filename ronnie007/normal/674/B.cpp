#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

int n , k ;
int a , b , c , d ;


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    scanf ( "%d%d%d%d" , &a , &b , &c , &d ) ;
}

void solve ( ) {
    vector < int > v ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( i == a ) { continue ; }
        if ( i == b ) { continue ; }
        if ( i == c ) { continue ; }
        if ( i == d ) { continue ; }
        v.push_back ( i ) ;
    }
    if ( n == 4 ) { printf ( "-1\n" ) ; return ; }
    if ( k < ( n - 3 ) + 4 ) { printf ( "-1\n" ) ; return ; }
    printf ( "%d %d" , a , c ) ;
    for ( i = 0 ; i < n - 4 ; i ++ ) {
        printf ( " %d" , v[ i ] ) ;
    }
    printf ( " %d %d\n" , d , b ) ;
    printf ( "%d %d" , c , a ) ;
    for ( i = 0 ; i < n - 4 ; i ++ ) {
        printf ( " %d" , v[ i ] ) ;
    }
    printf ( " %d %d\n" , b , d ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}