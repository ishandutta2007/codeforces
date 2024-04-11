#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
using namespace std ;

#define inf 1000000007
#define MAXN 500007

int n ;
vector < pair < int , int > > v[ MAXN ] ;

int subtree[ MAXN ] ;

int mask[ MAXN ] ;

int lvl[ MAXN ] ;

int f[ 10 * MAXN ] ;
int ans[ MAXN ] ;

int cur ;

void update ( int vertex , int init ) {
	int i , sz ;
	sz = v[ vertex ].size ( ) ;
	int u = f[ mask[ vertex ] ] ;
	cur = max ( cur , u + lvl[ vertex ] - 2 * lvl[ init ] ) ;
	for ( i = 0 ; i < 22 ; i ++ ) {
		u = f[ mask[ vertex ] ^ (1<<i) ] ;
		cur = max ( cur , u + lvl[ vertex ] - 2 * lvl[ init ] ) ;
	}
	sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		update ( v[ vertex ][ i ].first , init ) ;
	}
}

void add ( int vertex , bool fl ) {
	int i , sz ;
	sz = v[ vertex ].size ( ) ;
	if ( fl == true ) {
		if ( f[ mask[ vertex ] ] < lvl[ vertex ] ) { f[ mask[ vertex ] ] = lvl[ vertex ] ; }
	}
	else { f[ mask[ vertex ] ] = -inf ; }	
	for ( i = 0 ; i < sz ; i ++ ) {
		add ( v[ vertex ][ i ].first , fl ) ;
	}
}

void get_init ( int vertex ) {
	int sz = v[ vertex ].size ( ) ;
	int i ;
	subtree[ vertex ] = 1 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		mask[ v[ vertex ][ i ].first ] = mask[ vertex ] ^ (1<<v[ vertex ][ i ].second) ;
		lvl[ v[ vertex ][ i ].first ] = lvl[ vertex ] + 1 ; 
		get_init ( v[ vertex ][ i ].first ) ;
		subtree[ vertex ] += subtree[ v[ vertex ][ i ].first ] ;
	}	
}

void dfs ( int vertex , bool keep ) {
	int sz = v[ vertex ].size ( ) ;
	int i ;
	int mx , id ;
	mx = id = -1 ;
	subtree[ vertex ] = 1 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( mx < subtree[ v[ vertex ][ i ].first ] ) {
			mx = subtree[ v[ vertex ][ i ].first ] ;
			id = v[ vertex ][ i ].first ;
		}
	}
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ].first == id ) { continue ; }
		dfs ( v[ vertex ][ i ].first , false ) ;
	}
	if ( id != -1 ) { dfs ( id , true ) ; }
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ].first == id ) { continue ; }
		update ( v[ vertex ][ i ].first , vertex ) ;
		add ( v[ vertex ][ i ].first , true ) ;
	}
	if ( f[ mask[ vertex ] ] < lvl[ vertex ] ) { f[ mask[ vertex ] ] = lvl[ vertex ] ; }
	cur = max ( cur , f[ mask[ vertex ] ] + lvl[ vertex ] - 2 * lvl[ vertex ] ) ;
	for ( i = 0 ; i < 22 ; i ++ ) {
		cur = max ( cur , f[ mask[ vertex ] ^ (1<<i) ] + lvl[ vertex ] - 2 * lvl[ vertex ] ) ;
	}
	ans[ vertex ] = cur ;
	if ( keep == true ) { return ; }
	cur = 0 ;
	add ( vertex , false ) ;
}

void push ( int vertex ) {
	int i , sz ;
	sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		push ( v[ vertex ][ i ].first ) ;
		ans[ vertex ] = max ( ans[ vertex ] , ans[ v[ vertex ][ i ].first ] ) ;
	}
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	int x ;
	char c ;
	for ( i = 2 ; i <= n ; i ++ ) {
		scanf ( "\n%d %c" , &x , &c ) ;
		int val = ( c - 'a' ) ;
		v[ x ].push_back ( make_pair ( i , val ) ) ;
	}
}

void solve ( ) {
	int i ;
	for ( i = 0 ; i < ( 1<<22) ; i ++ ) {
		f[ i ] = -inf ;
	}
	cur = 0 ;
	get_init ( 1 ) ;
	dfs ( 1 , false ) ;
	push ( 1 ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%d" , ans[ i ] ) ;
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