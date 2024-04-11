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
vector < pair < int , int > > v[ MAXN ] ;
int sz[ MAXN ] ;
int ord[ MAXN ] ;
int tp ;

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    if ( sz == 1 && prv != -1 ) {
        if ( tp < n - 1 ) { ++ tp ; }
        ord[ v[ vertex ][ 0 ].second ] = 2 ;
        return ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( prv != v[ vertex ][ i ].first ) {
            if ( prv != -1 ) {
                ord[ v[ vertex ][ i ].second ] = tp -- ;
            }
            dfs ( v[ vertex ][ i ].first , vertex ) ;
            return ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    tp = n - 1 ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( { y , i } ) ;
        v[ y ].push_back ( { x , i } ) ;
        ++ sz[ x ] , ++ sz[ y ] ;
    }
}

void solve ( ) {
    if ( n == 2 ) {
        printf ( "0\n" ) ;
        return ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( sz[ i ] == 1 ) {
            ord[ v[ i ][ 0 ].second ] = 1 ;
            dfs ( i , -1 ) ;
            break ;
        }
    }
    
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( ord[ i ] == 0 ) { ord[ i ] = tp -- ; }
        printf ( "%d\n" , ord[ i ] - 1 ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}