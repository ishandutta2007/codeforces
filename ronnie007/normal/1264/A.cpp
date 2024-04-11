#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 400007

int n ;
int a[ MAXN ] ;
vector < int > v ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    v.clear ( ) ;
    int curr = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        if ( a[ i ] == a[ i - 1 ] ) { ++ curr ; }
        else {
            if ( i != 1 ) { v.push_back ( curr ) ; }
            curr = 1 ;
        }
    }
    v.push_back ( curr ) ;
}

void solve ( ) {
    int sz = v.size ( ) ;
    int x , y ;
    x = y = 0 ;
    for ( int i = 1 ; i < sz ; ++ i ) {
        if ( x <= v[ 0 ] ) { x += v[ i ] ; }
        else if ( y <= v[ 0 ] ) { y += v[ i ] ; }
        else {
            if ( 2 * ( v[ 0 ] + x + y + v[ i ] ) <= n ) { y += v[ i ] ; }
            else { break ; }
        }
    }
    if ( 2 * ( v[ 0 ] + x + y ) > n ) { printf ( "0 0 0\n" ) ; return ; }
    if ( x <= v[ 0 ] ) { printf ( "0 0 0\n" ) ; return ; }
    if ( y <= v[ 0 ] ) { printf ( "0 0 0\n" ) ; return ; }
    printf ( "%d %d %d\n" , v[ 0 ] , x , y ) ;
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