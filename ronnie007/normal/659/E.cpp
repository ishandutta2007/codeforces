#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
using namespace std ;

#define MAXN 100007
int n , m ;
vector < int > v[ MAXN ] ;
int used[ MAXN ] ;

bool cycle ;

void dfs ( int vertex , int par ) {
	used[ vertex ] = 1 ; 
	int sz = v[ vertex ].size ( ) ;
	int i ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == par ) { continue ; }
		if ( used[ v[ vertex ][ i ] ] == 1 ) { cycle = true ; continue ; }
		dfs ( v[ vertex ][ i ] , vertex ) ;
	}
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	int x , y ;
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
}

void solve ( ) {
	int i ;
	int ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( used[ i ] == 0 ) {
			cycle = false ;
			dfs ( i , -1 ) ;
			ans += (cycle^1) ;
		}
	}
	printf ( "%d\n" , ans ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}