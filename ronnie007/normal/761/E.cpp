#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 67

int n ;
vector < int > v[ MAXN ] ;

int deg[ MAXN ] ;

long long st[ MAXN ] ;

pair < long long , long long > ans[ MAXN ] ;

int dx[ 4 ] = { 0 , 0 , 1 , -1 } ;
int dy[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dir[ MAXN ] ;

int eq ( int dir ) {
    if ( dir == 0 ) { return 1 ; }
    if ( dir == 1 ) { return 0 ; }
    if ( dir == 2 ) { return 3 ; }
    if ( dir == 3 ) { return 2 ; }
    return 99 ;
}

void dfs ( int vertex , int prv , long long x , long long y , long long dist ) {
    ans[ vertex ] = make_pair ( x , y ) ;
    int i , sz ;
    sz = v[ vertex ].size ( ) ;
    int br = 0 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        while ( br == eq ( dir[ vertex ] ) ) { br ++ ; }
        dir[ v[ vertex ][ i ] ] = br ;
        dfs ( v[ vertex ][ i ] , vertex , x + dx[ br ] * dist , y + dy[ br ] * dist , dist / 2 ) ;
        br ++ ;

    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
        deg[ x ] ++ ; deg[ y ] ++ ;
    }
    st[ 0 ] = 1 ;
    for ( i = 1 ; i <= n + 20 ; i ++ ) {
        st[ i ] = ( 2 * st[ i - 1 ] ) ;
    }
}

void solve ( ) {
    int i ;
    int mx = 0 ;
    int id = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( deg[ i ] > 4 ) { printf ( "NO\n" ) ; return ; }
        if ( mx < deg[ i ] ) { mx = deg[ i ] ; id = i ; }
    }
    dir[ id ] = -1 ;
    dfs ( id , -1 , 0 , 0 , st[ n + 20 ] ) ;
    printf ( "YES\n" ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%I64d %I64d\n" , ans[ i ].first , ans[ i ].second ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}