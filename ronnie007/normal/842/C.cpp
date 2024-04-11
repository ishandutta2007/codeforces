#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
vector < int > v[ MAXN ] ;
int a[ MAXN ] ;
vector < int > divs[ MAXN ] ;

int ans[ MAXN ] ;

int br[ MAXN ] ;

void dfs ( int vertex , int prv , int lvl ) {
    int i ;
    int sz = v[ vertex ].size ( ) ;
    int h = divs[ a[ vertex ] ].size ( ) ;
    int mn = lvl - 1 ;
    if ( mn == 0 ) { mn ++ ; }
    for ( i = 0 ; i < h ; i ++ ) {
        br[ divs[ a[ vertex ] ][ i ] ] ++ ;
        if ( br[ divs[ a[ vertex ] ][ i ] ] >= mn ) {
            ans[ vertex ] = divs[ a[ vertex ] ][ i ] ;
        }
    }
    if ( prv != -1 ) {
        int g = divs[ a[ prv ] ].size ( ) ;
        for ( i = 0 ; i < g ; i ++ ) {
            if ( br[ divs[ a[ prv ] ][ i ] ] >= mn ) {
                if ( ans[ vertex ] < divs[ a[ prv ] ][ i ] ) {
                    ans[ vertex ] = divs[ a[ prv ] ][ i ] ;
                }
            }
        }
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex , lvl + 1 ) ;
    }
    for ( i = 0 ; i < h ; i ++ ) {
        br[ divs[ a[ vertex ] ][ i ] ] -- ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= 200000 ; i ++ ) {
        for ( j = i ; j <= 200000 ; j += i ) {
            divs[ j ].push_back ( i ) ;
        }
    }
    dfs ( 1 , -1 , 1 ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d" , ans[ i ] ) ;
        if ( i == n ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}