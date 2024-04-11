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

#define MAXN 400007

int n ;
vector < int > v[ MAXN ] ;

vector < int > ord ;
int st[ MAXN ] ;
int en[ MAXN ] ;
int subtree[ MAXN ] ;
set < int > s ;

int ans[ MAXN ] ;
int LEAVES ;

struct segment_tree {
	int tr[ 6 * MAXN ] ;
	void init ( int where , int IL , int IR ) {
		if ( IL == IR ) {
			if ( ( IL - 1 ) >= ord.size ( ) ) { tr[ where ] = 0 ; return ; }
			if ( subtree[ ord[ IL - 1 ] ] <= ( n / 2 ) ) { tr[ where ] = subtree[ ord[ IL - 1 ] ] ; }
			else { tr[ where ] = 0 ; }
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
		tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
	}
	void update ( int where , int val ) {
		tr[ where ] = val ;
		where /= 2 ;
		while ( where != 0 ) {
			tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
			where /= 2 ;
		}
	}
	int query ( int where , int IL , int IR , int CURL , int CURR ) {
		if ( CURL > CURR ) { return 0 ; }
		if ( IL > IR ) { return 0 ; }
		if ( IR < CURL || CURR < IL ) { return 0 ; }
		if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
		int mid = ( IL + IR ) / 2 ;
		return max ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
	}
};
segment_tree w ;


void init ( int vertex , int prv ) {
	ord.push_back ( vertex ) ;
	st[ vertex ] = ord.size ( ) - 1 ;
	int i , sz ;
	sz = v[ vertex ].size ( ) ;
	subtree[ vertex ] = 1 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		init ( v[ vertex ][ i ] , vertex ) ;
		subtree[ vertex ] += subtree[ v[ vertex ][ i ] ] ;
	}
	ord.push_back ( vertex ) ;
	en[ vertex ] = ord.size ( ) - 1 ; 
}

void dfs ( int vertex , int prv ) {
	int i , sz ;
	sz = v[ vertex ].size ( ) ;
	bool fl = false ;
	if ( n - subtree[ vertex ] > ( n / 2 ) ) {
		fl = true ;
		int mx = max ( w.query ( 1 , 1 , LEAVES , 1 , st[ vertex ] ) , w.query ( 1 , 1 , LEAVES , en[ vertex ] + 2 , LEAVES ) ) ;
		if ( s.size ( ) != 0 ) {
			set < int > :: iterator it = s.begin ( ) ;
			mx = max ( mx , -(*it) ) ;
		}
		if ( mx <= ( n / 2 ) && ( n - subtree[ vertex ] - mx ) <= ( n / 2 ) ) {
			ans[ vertex ] = 1 ;
		}
	}	
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		w.update ( LEAVES + st[ vertex ] , 0 ) ;
		w.update ( LEAVES + en[ vertex ] , 0 ) ;		
		int val = n - subtree[ v[ vertex ][ i ] ] ;
		if ( val <= ( n / 2 ) ) { s.insert ( -val ) ; }
		if ( subtree[ v[ vertex ][ i ] ] > ( n / 2 ) ) {
			fl = true ;
			int u = w.query ( 1 , 1 , LEAVES , st[ v[ vertex ][ i ] ] + 1 , en[ v[ vertex ][ i ] ] + 1 ) ;
			if ( u <= ( n / 2 ) && ( subtree[ v[ vertex ][ i ] ] - u ) <= ( n / 2 ) ) { ans[ vertex ] = 1 ; }
		}
		dfs ( v[ vertex ][ i ] , vertex ) ;
		if ( val <= ( n / 2 ) ) { s.erase ( -val ) ; }
		if ( subtree[ vertex ] <= ( n / 2 ) ) {
			w.update ( LEAVES + st[ vertex ] , subtree[ vertex ] ) ;
			w.update ( LEAVES + en[ vertex ] , subtree[ vertex ] ) ;
		}
	}
	if ( fl == false ) { ans[ vertex ] = 1 ; }
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i < n ; i ++ ) {
		int x , y ;
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
}

void solve ( ) {
	ord.clear ( ) ;
	s.clear ( ) ;
	init ( 1 , -1 ) ;
	LEAVES = 1 ;
	while ( LEAVES < ord.size ( ) ) { LEAVES *= 2 ; }
	w.init ( 1 , 1 , LEAVES ) ;
	dfs ( 1 , -1 ) ;
	int i ;
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