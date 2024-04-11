#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MAXN 100007

int n , m ;
int init[ MAXN ] ;
vector < int > u[ MAXN ] ;

vector < int > v[ 2 * MAXN ] ;
vector < int > rv[ 2 * MAXN ] ;
int used[ 2 * MAXN ] ;

int COMP[ 2 * MAXN ] ;

stack < int > s ;

void dfs ( int vertex ) {
	used[ vertex ] = 1 ; 
	s.push ( vertex ) ;
	int i , sz ;
	sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( used[ v[ vertex ][ i ] ] == 0 ) { dfs ( v[ vertex ][ i ] ) ; }
	}
}

void rev_dfs ( int vertex , int id ) {
	used[ vertex ] = 1 ; 
	COMP[ vertex ] = id ;
	int i , sz ;
	sz = rv[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( used[ rv[ vertex ][ i ] ] == 0 ) { rev_dfs ( rv[ vertex ][ i ] , id ) ; }
	}
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &init[ i ] ) ;
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		int sz ;
		int x ;
		scanf ( "%d" , &sz ) ;
		while ( sz != 0 ) {
			sz -- ;
			scanf ( "%d" , &x ) ;
			u[ x ].push_back ( i ) ;
		}
	}
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int x = u[ i ][ 0 ] ;
		int y = u[ i ][ 1 ] ;
		if ( init[ i ] == 0 ) {
			v[ x ].push_back ( m + y ) ;
			v[ m + y ].push_back ( x ) ;
			v[ y ].push_back ( m + x ) ;
			v[ m + x ].push_back ( y ) ;			
		}
		else {
			v[ x ].push_back ( y ) ;
			v[ y ].push_back ( x ) ;
			v[ m + x ].push_back ( m + y ) ;
			v[ m + y ].push_back ( m + x ) ;
		}
	}
	for ( i = 1 ; i <= 2 * m ; i ++ ) {
		int sz = v[ i ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			rv[ v[ i ][ j ] ].push_back ( i ) ;
		}
	}
	for ( i = 1 ; i <= 2 * m ; i ++ ) {
		if ( used[ i ] == 0 ) {
			dfs ( i ) ;
		}
	}
	for ( i = 1 ; i <= 2 * m ; i ++ ) { used[ i ] = 0 ; }
	int id = 1 ;
	while ( s.empty ( ) == false ) {
		int x = s.top ( ) ;
		s.pop ( ) ;
		if ( COMP[ x ] != 0 ) { continue ; }
		rev_dfs ( x , id ) ;
		id ++ ;
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		if ( COMP[ i ] == COMP[ m + i ] ) { printf ( "NO\n" ) ; return ; }
	}
	printf ( "YES\n" ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}