#include<iostream>
#include<stdio.h>
#include<queue>
using namespace std ;

#define MAXN 1007

int n ;
int a[ MAXN ][ MAXN ] ;

int dx[ 8 ] = { -1 , -1 , 0 , 1 , 1 , 1 , 0 , -1 } ;
int dy[ 8 ] = { 0 , 1 , 1 , 1 , 0 , -1 , -1 , -1 } ;

int qx , qy ;
int stx , sty ;
int enx , eny ;

void dfs ( int x , int y ) {
    a[ x ][ y ] = 1 ;
    int i ;
    for ( i = 0 ; i < 8 ; i ++ ) {
        int nx = ( x + dx[ i ] ) ;
        int ny = ( y + dy[ i ] ) ;
        if ( nx <= 0 || nx > n ) { continue ; }
        if ( ny <= 0 || ny > n ) { continue ; }
        if ( a[ nx ][ ny ] == 1 ) { continue ; }
        dfs ( nx , ny ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    scanf ( "%d%d" , &qx , &qy ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        a[ qx ][ i ] = a[ i ][ qy ] = 1 ;
    }
    for ( i = -n ; i <= n ; i ++ ) {
        int nx = qx + i ;
        int ny = qy + i ;
        if ( 1 <= nx && nx <= n ) {
            if ( 1 <= ny && ny <= n ) {
                a[ nx ][ ny ] = 1 ;
            }
        }
    }
    for ( i = -n ; i <= n ; i ++ ) {
        int nx = qx - i ;
        int ny = qy + i ;
        if ( 1 <= nx && nx <= n ) {
            if ( 1 <= ny && ny <= n ) {
                a[ nx ][ ny ] = 1 ;
            }
        }
    }
    scanf ( "%d%d" , &stx , &sty ) ;
    scanf ( "%d%d" , &enx , &eny ) ;
}

void solve ( ) {
    dfs ( stx , sty ) ;
    if ( a[ enx ][ eny ] == 1 ) { printf ( "YES\n" ) ; }
    else { printf ( "NO\n" ) ; }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}