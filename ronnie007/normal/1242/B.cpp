#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 100007
#define MAGIC 400


int n ;
vector < int > v[ MAXN ] ;

int prv[ MAXN ] ;

int ans = 0 ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        -- ans ;
        prv[ k1 ] = k2 ;
    }
}

void input ( ) {
    int m ;
    scanf ( "%d%d" , &n , &m ) ;
    ans = n - 1 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        sort ( v[ i ].begin ( ) , v[ i ].end ( ) ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) { prv[ i ] = -1 ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int id = 0 ;
        int sz = v[ i ].size ( ) ;
        while ( id < sz && v[ i ][ id ] < i ) { ++ id ; }
        -- id ;
        int lft = MAGIC ;
        int aux = id ;
        int val = i - 1 ;
        while ( lft > 0 && val > 0 ) {
            if ( aux >= 0 && v[ i ][ aux ] == val ) { -- val ; -- aux ; }
            else { UNITE ( i , val ) ; -- lft ; -- val ; }
        }
        lft = MAGIC ;
        aux = id + 1 ;
        val = i + 1 ;
        while ( lft > 0 && val <= n ) {
            if ( aux < sz && v[ i ][ aux ] == val ) { ++ val ; ++ aux ; }
            else { UNITE ( i , val ) ; -- lft ; ++ val ; }
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}