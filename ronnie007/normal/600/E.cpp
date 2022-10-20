#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;
long long ans[ MAXN ] ;
int subtree[ MAXN ] ;
int mx_child[ MAXN ] ;

int cnt[ MAXN ] ;
long long sm , sr ;

void init ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    subtree[ vertex ] = 1 ;
    mx_child[ vertex ] = 0 ;
    int curr = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        init ( v[ vertex ][ i ] , vertex ) ;
        subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
        if ( curr < subtree[ v[ vertex ][ i ] ] ) {
            curr = subtree[ v[ vertex ][ i ] ] ;
            mx_child[ vertex ] = v[ vertex ][ i ] ;
        }
    }
}

void upd ( int vertex , int prv , int add ) {
    int sz = v[ vertex ].size ( ) ;
    cnt[ a[ vertex ] ] += add ;
    if ( add == 1 ) {
        if ( sr < cnt[ a[ vertex ] ] ) {
            sr = cnt[ a[ vertex ] ] , sm = 0 ;
        }
        if ( sr == cnt[ a[ vertex ] ] ) {
            sm += a[ vertex ] ;
        }
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        upd ( v[ vertex ][ i ] , vertex , add ) ;
    }
}

void dfs ( int vertex , int prv , bool fl ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( v[ vertex ][ i ] == mx_child[ vertex ] ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex , false ) ;
    }
    if ( mx_child[ vertex ] > 0 ) {
        dfs ( mx_child[ vertex ] , vertex , true ) ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        if ( v[ vertex ][ i ] == mx_child[ vertex ] ) { continue ; }
        upd ( v[ vertex ][ i ] , vertex , 1 ) ;
    }
    ++ cnt[ a[ vertex ] ] ;
    if ( sr < cnt[ a[ vertex ] ] ) {
        sr = cnt[ a[ vertex ] ] , sm = 0 ;
    }
    if ( sr == cnt[ a[ vertex ] ] ) {
        sm += a[ vertex ] ;
    }
    ans[ vertex ] = sm ;
    if ( fl == false ) {
        sm = sr = 0 ;
        upd ( vertex , prv , -1 ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    init ( 1 , -1 ) ;
    dfs ( 1 , -1 , true ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%I64d " , ans[ i ] ) ;
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