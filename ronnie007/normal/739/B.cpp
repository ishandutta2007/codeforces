#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;

long long dist[ MAXN ] ;

vector < long long > s ;

int prv[ MAXN ][ 22 ] ;
int ans[ MAXN ] ;
int ret[ MAXN ] ;
int toadd[ MAXN ] ;
int torem[ MAXN ] ;

int cur = 0 ;

void dfs ( int vertex ) {
	int i ;
	vector < long long > :: iterator pr = upper_bound ( s.begin ( ) , s.end ( ) , dist[ vertex ] - a[ vertex ] - 1 ) ;
	ans[ vertex ] = ( s.end ( ) - pr ) ;
	s.push_back ( dist[ vertex ] ) ;
	for ( i = 1 ; i <= 20 ; i ++ ) {
		prv[ vertex ][ i ] = prv[ prv[ vertex ][ i - 1 ] ][ i - 1 ] ;
	}
	int sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		int u = v[ vertex ][ i ].first ;
		int c = v[ vertex ][ i ].second ;
		prv[ u ][ 0 ] = vertex ;
		dist[ u ] = dist[ vertex ] + c ;
		dfs ( u ) ;
	}
	s.pop_back ( ) ;
}

int f ( int vertex ) {
	int i ;
	int sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		ret[ vertex ] += f ( v[ vertex ][ i ].first ) ;
	}
	return ( ret[ vertex ] - torem[ vertex ] + toadd[ vertex ] ) ;	
}

int get ( int vertex , int x ) {
	int i ;
	for ( i = 20 ; i >= 0 ; i -- ) {
		int u = (1<<i) ;
		if ( x >= u ) {
			x -= u ;
			vertex = prv[ vertex ][ i ] ;
		}
	}
	return vertex ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	for ( i = 2 ; i <= n ; i ++ ) {
		int x , y ;
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( make_pair ( i , y ) ) ;
	}
}

void solve ( ) {
	dfs ( 1 ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int u = get ( i , ans[ i ] ) ;
		if ( i == u ) { continue ; }
		toadd[ i ] ++ ;
		torem[ u ] ++ ;
	}
	f ( 1 ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%d" , ret[ i ] ) ;
		if ( i == n ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}