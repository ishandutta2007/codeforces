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

#define MAXN 1000007
int n , k ;
vector < int > v[ MAXN ] ;

int dp[ MAXN ] ;

int cl[ MAXN ] ;

vector < int > aux[ MAXN ] ;

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    dp[ vertex ] = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex ) ;
        dp[ vertex ] += dp[ v[ vertex ][ i ] ] ;
        aux[ vertex ].push_back ( cl[ v[ vertex ][ i ] ] + 1 ) ;

    }
    if ( sz == 1 && prv != -1 ) {
        dp[ vertex ] = 1 ;
        cl[ vertex ] = 0 ;
        return ;
    }
    sort ( aux[ vertex ].begin ( ) , aux[ vertex ].end ( ) ) ;
    sz = aux[ vertex ].size ( ) ;
    cl[ vertex ] = aux[ vertex ][ 0 ] ;
    for ( int i = 0 ; i < sz - 1 ; ++ i ) {
        if ( aux[ vertex ][ i ] + aux[ vertex ][ i + 1 ] <= k ) {
            cl[ vertex ] = aux[ vertex ][ i + 1 ] ;
            -- dp[ vertex ] ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    int root ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( v[ i ].size ( ) > 1 ) { root = i ; }
    }
    dfs ( root , -1 ) ;
    printf ( "%d\n" , dp[ root ] ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}