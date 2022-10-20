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

#define MAXN 300007
#define MOD 1000000007

int n ;
vector < int > v[ MAXN ] ;

int st[ MAXN ] ;
int en[ MAXN ] ;

int lvl[ MAXN ] ;

vector < int > ord ;

int LEAVES ;

struct Tree {
	int tr[ 4 * MAXN ] ;
	void init ( int where , int IL , int IR ) {
		tr[ where ] = 0 ;
		if ( IL == IR ) { return ; }
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
	}
	void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
		if ( IL > IR ) { return ; }
		if ( CURL > CURR ) { return ; }
		if ( IR < CURL || CURR < IL ) { return ; }
		if ( CURL <= IL && IR <= CURR ) {
			tr[ where ] = ( tr[ where ] + val ) % MOD ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		update ( 2 * where , IL , mid , CURL , CURR , val ) ;
		update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
	}
	int query ( int where ) {
		int ans = 0 ;
		while ( where != 0 ) {
			ans = ( ans + tr[ where ] ) % MOD ;
			where /= 2 ; 
		}
		return ans ;
	}
};
Tree w1 , w2 ;
void dfs ( int vertex , int lst ) {
	ord.push_back ( vertex ) ;
	st[ vertex ] = ord.size ( ) ;
	int sz = v[ vertex ].size ( ) ;
	int i ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == lst ) { continue ; }
		lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
		dfs ( v[ vertex ][ i ] , vertex ) ;
	}
	en[ vertex ] = ord.size ( ) ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 2 ; i <= n ; i ++ ) {
		int x ;
		scanf ( "%d" , &x ) ;
		v[ i ].push_back ( x ) ;
		v[ x ].push_back ( i ) ;
	}
}

void solve ( ) {
	dfs ( 1 , -1 ) ;
	LEAVES = 1 ;
	while ( LEAVES < n ) { LEAVES *= 2 ; }
	w1.init ( 1 , 1 , LEAVES ) ;
	w2.init ( 1 , 1 , LEAVES ) ;
	int q ;
	int type , x , y , z ;
	scanf ( "%d" , &q ) ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d" , &type ) ;
		if ( type == 1 ) {
			scanf ( "%d%d%d" , &x , &y , &z ) ;
			int val = ( 1LL * z * lvl[ x ] + y ) % MOD ;
			w1.update ( 1 , 1 , LEAVES , st[ x ] , en[ x ] , val ) ;
			w2.update ( 1 , 1 , LEAVES , st[ x ] , en[ x ] , z ) ;
		}
		else {
			scanf ( "%d" , &x ) ;
			int u1 , u2 ;
			u1 = w1.query ( LEAVES + st[ x ] - 1 ) ;
			u2 = w2.query ( LEAVES + st[ x ] - 1 ) ;
			u2 = ( 1LL * u2 * lvl[ x ] ) % MOD ;
			printf ( "%d\n" , ( ( u1 - u2 + MOD ) % MOD ) ) ;
		}
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}