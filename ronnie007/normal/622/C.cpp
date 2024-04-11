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

#define MAXN 200007

int n , q ;
int a[ MAXN ] ;

int LEAVES ;

struct Tree {
	int tr[ 3 * MAXN ] ;
	void init ( int where , int IL , int IR ) {
		if ( IL > IR ) { return ; }
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
			tr[ where ] = val ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		update ( 2 * where , IL , mid , CURL , CURR , val ) ;
		update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
	}
	int query ( int where ) {
		while ( where != 0 ) {
			if ( tr[ where ] != 0 ) { return tr[ where ] ; }
			where /= 2 ;
		}
		return n + 1 ; 
	}
};
Tree w ;

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	LEAVES = 1 ;
	while ( LEAVES < n ) { LEAVES *= 2 ; }
	w.init ( 1 , 1 , LEAVES ) ;
}

void solve ( ) {
	int i ;
	int br = 1 ;
	for ( i = 2 ; i <= n ; i ++ ) {
		if ( a[ i ] == a[ i - 1 ] ) { br ++ ; }
		else {
			w.update ( 1 , 1 , LEAVES , i - br , i - 1 , i ) ;
			br = 1 ; 
		}
	}
	if ( br != 0 ) {
		w.update ( 1 , 1 , LEAVES , n - br + 1 , n , n + 1 ) ;
	}
	int x , y , z ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d%d%d" , &x , &y , &z ) ;
		if ( a[ x ] != z ) { printf ( "%d\n" , x ) ; }
		else {
			int id = w.query ( LEAVES + x - 1 ) ;
			if ( id <= y ) { printf ( "%d\n" , id ) ; }
			else { printf ( "-1\n" ) ; }
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