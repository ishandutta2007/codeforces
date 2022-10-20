#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
using namespace std ;

#define MAXN 200007

int n ;
vector < int > v[ MAXN ] ;
int a[ MAXN ] ;

int st[ MAXN ] ;
int en[ MAXN ] ;
int lvl[ MAXN ] ;

int prv[ MAXN ][ 22 ] ;

vector < int > ord ;

vector < int > h[ MAXN ] ;

void dfs ( int vertex , int lst ) {
	ord.push_back ( vertex ) ;
	st[ vertex ] = ord.size ( ) - 1 ;
	h[ lvl[ vertex ] ].push_back ( ord.size ( ) - 1 ) ;
	int i ;
	for ( i = 1 ; i <= 20 ; i ++ ) {
		prv[ vertex ][ i ] = prv[ prv[ vertex ][ i - 1 ] ][ i - 1 ] ;
	}
	int sz ;
	sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == lst ) { continue ; }
		lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
		prv[ v[ vertex ][ i ] ][ 0 ] = vertex ;
		dfs ( v[ vertex ][ i ] , vertex ) ;
	}
	ord.push_back ( vertex ) ;
	en[ vertex ] = ord.size ( ) - 1 ; 
}

int get ( int vertex , int x ) {
	if ( lvl[ vertex ] < x ) { return 0 ; }
	int i ;
	for ( i = 20 ; i >= 0 ; i -- ) {
		int dist = (1<<i) ;
		if ( x >= dist ) {
			vertex = prv[ vertex ][ i ] ;
			x -= dist ;
		}
	}
	return vertex ;
}

int below ( int id , int val ) {
	if ( val < 0 ) { return 0 ; }
	int l , r , mid ;
	l = 0 ;
	r = h[ id ].size ( ) - 1 ;
	if ( h[ id ][ r ] <= val ) { return ( r + 1 ) ; }
	if ( h[ id ][ l ] > val ) { return 0 ; }
	while ( r - l > 3 ) {
		mid = ( l + r ) / 2 ;
		if ( h[ id ][ mid ] <= val ) { l = mid ; }
		else { r = mid ; }
	}
	while ( h[ id ][ r ] > val ) { r -- ; }
	return ( r + 1 ) ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		if ( a[ i ] != 0 ) {
			v[ a[ i ] ].push_back ( i ) ;
			v[ i ].push_back ( a[ i ] ) ;
		}
	}
}

void solve ( ) {
	int i , j ;
	for ( i = 0 ; i <= n ; i ++ ) {
		for ( j = 0 ; j <= 20 ; j ++ ) {
			prv[ i ][ j ] = 0 ;
		}
		h[ i ].clear ( ) ;
		lvl[ i ] = 0 ;
	}
	ord.clear ( ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( a[ i ] == 0 ) { dfs ( i , -1 ) ; }
	}
	int q ;
	int x , y ;
	scanf ( "%d" , &q ) ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d%d" , &x , &y ) ;
		int u = get ( x , y ) ;
		int g = get ( x , ( y - 1 ) ) ;
		if ( u == 0 || g == 0 ) {
			printf ( "0 " ) ;
		}
		else {
			int ans = below ( lvl[ x ] , en[ u ] ) - below ( lvl[ x ] , st[ u ] - 1 ) ;
			//ans -= ( below ( lvl[ x ] , en[ g ] ) - below ( lvl[ x ] , st[ g ] - 1 ) ) ;
			ans -- ;
			printf ( "%d " , ans ) ;
		}
	}
	printf ( "\n" ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}