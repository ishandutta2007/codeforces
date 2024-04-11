#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std ;

#define MAXN 200007

int n , m ;
struct tuhla {
	int x , y , len , id ;
};

vector < struct tuhla > edg ;

vector < pair < int , int > > v[ MAXN ] ;

int prv[ MAXN ][ 27 ] ;
int mx[ MAXN ][ 27 ] ;

int g[ MAXN ] ;

long long ans[ MAXN ] ;
int lvl[ MAXN ] ;

long long init ;

int find ( int x ) {
	if ( g[ x ] == -1 ) { return x ; }
    int y = find ( g[ x ] ) ;
    g[ x ] = y ;
    return y ;
}

void UNITE ( struct tuhla u ) {
	int k1 = find ( u.x ) ;
    int k2 = find ( u.y ) ;
    if ( k1 == k2 ) { return ; }
    else {
    	v[ u.x ].push_back ( make_pair ( u.y , u.len ) ) ;
        v[ u.y ].push_back ( make_pair ( u.x , u.len ) ) ;
        init += u.len ;
        g[ k1 ] = k2 ;
    }
}

void dfs ( int vertex , int par ) {
	int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 1 ; i <= 20 ; i ++ ) {
    	prv[ vertex ][ i ] = prv[ prv[ vertex ][ i - 1 ] ][ i - 1 ] ;
        mx[ vertex ][ i ] = max ( mx[ vertex ][ i - 1 ] , mx[ prv[ vertex ][ i - 1 ] ][ i - 1 ] ) ;
    }
    for ( i = 0 ; i < sz ; i ++ ) {
    	if ( v[ vertex ][ i ].first != par ) {
        	lvl[ v[ vertex ][ i ].first ] = lvl[ vertex ] + 1 ; 
        	prv[ v[ vertex ][ i ].first ][ 0 ] = vertex ;
            mx[ v[ vertex ][ i ].first ][ 0 ] = v[ vertex ][ i ].second ;
            dfs ( v[ vertex ][ i ].first , vertex ) ;
        }
    }
}

int LCA ( int x , int y ) {
	int i ;
    int ret = 0 ;
    for ( i = 20 ; i >= 0 ; i -- ) {
    	if ( lvl[ x ] - (1<<i) >= lvl[ y ] ) {
        	ret = max ( ret , mx[ x ][ i ] ) ;
            x = prv[ x ][ i ] ;
        }
        if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
        	ret = max ( ret , mx[ y ][ i ] ) ;
            y = prv[ y ][ i ] ;
        }
    }
    for ( i = 20 ; i >= 0 ; i -- ) {
    	if ( prv[ x ][ i ] != prv[ y ][ i ] ) {
        	ret = max ( ret , mx[ x ][ i ] ) ;
            ret = max ( ret , mx[ y ][ i ] ) ;
            x = prv[ x ][ i ] ;
            y = prv[ y ][ i ] ;
        }
    }
    if ( x != y ) {
    	ret = max ( ret , mx[ x ][ 0 ] ) ;
        ret = max ( ret , mx[ y ][ 0 ] ) ;
    }
    return ret ;
}

bool cmp ( struct tuhla p1 , struct tuhla p2 ) {
	return ( p1.len < p2.len ) ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    int i ;
    edg.resize ( m ) ;
    for ( i = 0 ; i < m ; i ++ ) {
    	scanf ( "%d%d%d" , &edg[ i ].x , &edg[ i ].y , &edg[ i ].len ) ;
        edg[ i ].id = ( i + 1 ) ;
    }
    sort ( edg.begin ( ) , edg.end ( ) , cmp ) ;
}

void solve ( ) {
	int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	g[ i ] = -1 ;
    }
    for ( i = 0 ; i < m ; i ++ ) {
    	UNITE ( edg[ i ] ) ;
    }
    dfs ( 1 , -1 ) ;
    for ( i = 0 ; i < m ; i ++ ) {
    	ans[ edg[ i ].id ] = init - LCA ( edg[ i ].x , edg[ i ].y ) + edg[ i ].len ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
    	cout << ans[ i ] << "\n" ;
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}