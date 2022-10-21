#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 300007

int n , m ;
vector < int > p[ MAXN ] ;

vector < int > v[ MAXN ] ;

int used[ MAXN ] ;
int fr[ MAXN ] ;

int ans[ MAXN ] ;
int ret ;



void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    int i ;
    int g = p[ vertex ].size ( ) ;
    for ( i = 0 ; i < g ; i ++ ) {
        fr[ ans[ p[ vertex ][ i ] ] ] = 1 ;
    }
    int h = 1 ;
    for ( i = 0 ; i < g ; i ++ ) {
        if ( used[ p[ vertex ][ i ] ] == 0 ) {
            used[ p[ vertex ][ i ] ] = 1 ;
            while ( fr[ h ] == 1 ) {
                h ++ ;
            }
            ans[ p[ vertex ][ i ] ] = h ;
            fr[ h ] = 1 ;
        }
    }
    for ( i = 0 ; i < g ; i ++ ) {
        fr[ ans[ p[ vertex ][ i ] ] ] = 0 ;
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i , j ;
    ret = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int sz ;
        scanf ( "%d" , &sz ) ;
        if ( ret < sz ) { ret = sz ; }
        p[ i ].resize ( sz ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            scanf ( "%d" , &p[ i ][ j ] ) ;
        }
    }
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    int i ;
    dfs ( 1 , -1 ) ;
    if ( ret == 0 ) {
        ret = 1 ;
        for ( i = 1 ; i <= m ; i ++ ) {
            ans[ i ] = 1 ;
        }
    }
    printf ( "%d\n" , ret ) ;
    for ( i = 1 ; i <= m ; i ++ ) {
        if ( ans[ i ] == 0 ) { ans[ i ] = 1 ; }
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}