#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

#define MAXN 100007

int n ;
vector < pair < int , int > > v[ MAXN ] ;

int subtree[ MAXN ] ;

vector < int > ret ;

void dfs ( int vertex , int prv ) {
	int i ;
	int sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ].first == prv ) { continue ; }
		dfs ( v[ vertex ][ i ].first , vertex ) ;
		subtree[ vertex ] += subtree[ v[ vertex ][ i ].first ] ;
		if ( v[ vertex ][ i ].second == 2 ) { subtree[ vertex ] ++ ; }
		if ( subtree[ v[ vertex ][ i ].first ] == 0 && v[ vertex ][ i ].second == 2 ) {
			ret.push_back ( v[ vertex ][ i ].first ) ;
		}
	}
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i < n ; i ++ ) {
		int x , y , z ;
		scanf ( "%d%d%d" , &x , &y , &z ) ;
		v[ x ].push_back ( make_pair ( y , z ) ) ;
		v[ y ].push_back ( make_pair ( x , z ) ) ;
	}
}

void solve ( ) {
	dfs ( 1 , -1 ) ;
	int sz = ret.size ( ) ;
	int i ;
	printf ( "%d\n" , sz ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		printf ( "%d" , ret[ i ] ) ;
		if ( i == ( sz - 1 ) ) { printf ( "\n" ) ; }
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