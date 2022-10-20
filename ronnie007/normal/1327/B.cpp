#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;

int used[ 2 ][ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 , len ; i <= n ; ++ i ) {
        v[ i ].clear ( ) ;
        scanf ( "%d" , &len ) ;
        v[ i ].resize ( len ) ;
        for ( int j = 0 ; j < len ; ++ j ) {
            scanf ( "%d" , &v[ i ][ j ] ) ;
        }
        used[ 0 ][ i ] = used[ 1 ][ i ] = 0 ;
    }
}

void solve ( ) {
    for ( int i = 1 , len ; i <= n ; ++ i ) {
        len = v[ i ].size ( ) ;
        for ( int j = 0 ; j < len ; ++ j ) {
            if ( used[ 1 ][ v[ i ][ j ] ] == 0 ) {
                used[ 1 ][ v[ i ][ j ] ] = 1 ;
                used[ 0 ][ i ] = 1 ;
                break ;
            }
        }
    }
    int x , y ;
    x = y = 0 ;
    for ( int i = n ; i >= 1 ; -- i ) {
        if ( x == 0 && used[ 0 ][ i ] == 0 ) { x = i ; }
        if ( y == 0 && used[ 1 ][ i ] == 0 ) { y = i ; }
    }
    if ( x != 0 && y != 0 ) {
        printf ( "IMPROVE\n%d %d\n" , x , y ) ;
    }
    else { printf ( "OPTIMAL\n" ) ; }
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