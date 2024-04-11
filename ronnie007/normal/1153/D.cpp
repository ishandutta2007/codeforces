#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 300007

int n ;
vector < int > v[ MAXN ] ;

int a[ MAXN ] ;
int leaves[ MAXN ] ;
int f[ MAXN ] ;

void dfs ( int vertex ) {
    int w = v[ vertex ].size ( ) ;
    int i ;
    leaves[ vertex ] = 0 ;
    for ( i = 0 ; i < w ; i ++ ) {
        dfs ( v[ vertex ][ i ] ) ;
        leaves[ vertex ] += leaves[ v[ vertex ][ i ] ] ;
    }
    if ( w == 0 ) { leaves[ vertex ] = 1 ; }
    if ( a[ vertex ] == 0 ) {
        f[ vertex ] = 1 ;
        for ( i = 0 ; i < w ; i ++ ) {
            f[ vertex ] += f[ v[ vertex ][ i ] ] - 1 ;
        }
    }
    else {
        f[ vertex ] = leaves[ vertex ] ;
        int mn = n + 2 ;
        for ( i = 0 ; i < w ; i ++ ) {
            mn = min ( leaves[ v[ vertex ][ i ] ] - f[ v[ vertex ][ i ] ] , mn ) ;
        }
        if ( mn < ( n + 2 ) ) {
            f[ vertex ] -= mn ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 2 ; i <= n ; i ++ ) {
        int pr ;
        scanf ( "%d" , &pr ) ;
        v[ pr ].push_back ( i ) ;
    }
}

void solve ( ) {
    dfs ( 1 ) ;
    printf ( "%d\n" , f[ 1 ] ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}