#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std ;

#define MAXN 100007

int n , m , q ;
vector < int > v[ MAXN ] ;
vector < int > best[ MAXN ][ 20 ] ;
int prv[ MAXN ][ 20 ] ;
int lvl[ MAXN ] ;

vector < int > ans ;

vector < int > merge ( vector < int > v1 , vector < int > v2 ) {
	int p1 , p2 ;
    int sz1 , sz2 , sz3 ;
    p1 = p2 = 0 ;
    sz1 = v1.size ( ) ;
    sz2 = v2.size ( ) ;
    sz3 = 0 ;
    vector < int > ret ;
    ret.clear ( ) ;
    while ( sz3 < 10 ) {
    	if ( p1 == sz1 && p2 == sz2 ) { return ret ; }
        if ( p1 == sz1 ) { ret.push_back ( v2[ p2 ] ) ; p2 ++ ; sz3 ++ ; }
        else if ( p2 == sz2 ) { ret.push_back ( v1[ p1 ] ) ; p1 ++ ; sz3 ++ ; }
        else {
        	if ( v1[ p1 ] < v2[ p2 ] ) { ret.push_back ( v1[ p1 ] ) ; p1 ++ ; sz3 ++ ; }
            else { ret.push_back ( v2[ p2 ] ) ; p2 ++ ; sz3 ++ ; }
        }
    }
    
}

void LCA ( int x , int y ) {
	int i ;
    for ( i = 19 ; i >= 0 ; i -- ) {
    	int u = (1<<i) ;
    	if ( lvl[ x ] - u >= lvl[ y ] ) {
        	ans = merge ( ans , best[ x ][ i ] ) ;
            x = prv[ x ][ i ] ;
        }
    	if ( lvl[ y ] - u >= lvl[ x ] ) {
        	ans = merge ( ans , best[ y ][ i ] ) ;
            y = prv[ y ][ i ] ;
        }        
    }
    for ( i = 19 ; i >= 0 ; i -- ) {
    	if ( prv[ x ][ i ] != prv[ y ][ i ] ) {
        	ans = merge ( ans , best[ x ][ i ] ) ;
        	ans = merge ( ans , best[ y ][ i ] ) ;
            x = prv[ x ][ i ] ;
            y = prv[ y ][ i ] ;
        }
    }
    if ( x != y ) {
    	ans = merge ( ans , best[ x ][ 0 ] ) ;
        ans = merge ( ans , best[ y ][ 0 ] ) ;
    	x = prv[ x ][ 0 ] ;
        y = prv[ y ][ 0 ] ;
    }
	ans = merge ( ans , best[ x ][ 0 ] ) ;    
}

int dfs ( int vertex , int par ) {
	int sz = v[ vertex ].size ( ) ;
    int i ;
    for ( i = 1 ; i < 20 ; i ++ ) {
    	prv[ vertex ][ i ] = prv[ prv[ vertex ][ i - 1 ] ][ i - 1 ] ;
		best[ vertex ][ i ] = merge ( best[ vertex ][ i - 1 ] , best[ prv[ vertex ][ i - 1 ] ][ i - 1 ] ) ;
    }
   	for ( i = 0 ; i < sz ; i ++ ) {
    	if ( v[ vertex ][ i ] != par ) {
        	lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ; 
        	prv[ v[ vertex ][ i ] ][ 0 ] = vertex ;
            dfs ( v[ vertex ][ i ] , vertex ) ;
        }
    }
}

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &q ) ;
    int i ;
    int x , y ;
    for ( i = 1 ; i < n ; i ++ ) {
    	scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
    	scanf ( "%d" , &x ) ;
        best[ x ][ 0 ].push_back ( i ) ;
        if ( best[ x ][ 0 ].size ( ) > 10 ) { best[ x ][ 0 ].resize ( 10 ) ; }
    }
}

void solve ( ) {
	dfs ( 1 , -1 ) ;
    int i ;
    int x , y , z ;
    while ( q != 0 ) {
    	q -- ;
        scanf ( "%d%d%d" , &x , &y , &z ) ;
        ans.clear ( ) ;
        LCA ( x , y ) ;
        int k = ans.size ( ) ;
        if ( k > z ) { k = z ; }
        printf ( "%d" , k ) ;
        for ( i = 0 ; i < k ; i ++ ) {
        	printf ( " %d" , ans[ i ] ) ;
        }
        printf ( "\n" ) ;
    }
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}