#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
using namespace std ;

#define MAXN 200007

int n , k ;
vector < int > v[ MAXN ] ;
long long subtree[ MAXN ] ;
long long dp[ MAXN ][ 7 ] ;

long long tot[ 7 ] ;

long long sm ;

void init_subtree ( int vertex , int prv ) {
    subtree[ vertex ] = 1 ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        init_subtree ( v[ vertex ][ i ] , vertex ) ;
        subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
    }
}

void dfs ( int vertex , int prv ) {
    int i , j , t ;
    int sz = v[ vertex ].size ( ) ;
    sm += subtree[ vertex ] * ( n - subtree[ vertex ] ) ;
    dp[ vertex ][ 0 ] = 1 ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex ) ;
        for ( j = 0 ; j < k ; j ++ ) {
            dp[ vertex ][ ( j + 1 ) % k ] += dp[ v[ vertex ][ i ] ][ j ] ;
        }
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        for ( j = 0 ; j < k ; j ++ ) {
            dp[ vertex ][ ( j + 1 ) % k ] -= dp[ v[ vertex ][ i ] ][ j ] ;
        }
        for ( j = 0 ; j < k ; j ++ ) {
            for ( t = 0 ; t < k ; t ++ ) {
                int aux = ( j + t + 1 ) % k ;
                tot[ aux ] += dp[ vertex ][ j ] * dp[ v[ vertex ][ i ] ][ t ] ;
            }
        }
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        for ( j = 0 ; j < k ; j ++ ) {
            dp[ vertex ][ ( j + 1 ) % k ] += dp[ v[ vertex ][ i ] ][ j ] ;
        }
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i < n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    init_subtree ( 1 , -1 ) ;
    dfs ( 1 , -1 ) ;
    int i ;
    for ( i = 1 ; i < k ; i ++ ) {
        sm -= i * tot[ i ] ;
    }
    sm /= k ;
    for ( i = 1 ; i < k ; i ++ ) {
        sm += tot[ i ] ;
    }
    printf ( "%I64d\n" , sm ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}