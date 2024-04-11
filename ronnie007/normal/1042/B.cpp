#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

#define MAXN 1007
#define inf 1000000007

int n ;
pair < int , int > a[ MAXN ] ;

int dp[ 8 ] ;

int get ( string s ) {
    int ret = 0 ;
    int sz = s.size ( ) ;
    int i ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( s[ i ] == 'A' ) { ret ++ ; break ; }
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( s[ i ] == 'B' ) { ret += 2 ; break ; }
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( s[ i ] == 'C' ) { ret += 4 ; break ; }
    }
    return ret ;
}

void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        string aux ;
        cin >> a[ i ].first >> aux ;
        a[ i ].second = get ( aux ) ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i < 8 ; i ++ ) {
        dp[ i ] = inf ;
    }
    dp[ 0 ] = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 7 ; j >= 0 ; j -- ) {
            if ( dp[ j ] == inf ) { continue ; }
            dp[ (j|a[ i ].second) ] = min ( dp[ (j|a[ i ].second) ] , dp[ j ] + a[ i ].first ) ;
        }
    }
    if ( dp[ 7 ] == inf ) { printf ( "-1\n" ) ; return ; }
    printf ( "%d\n" , dp[ 7 ] ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}