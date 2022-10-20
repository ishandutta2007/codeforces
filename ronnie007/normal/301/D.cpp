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

#define MAXN 200007

int n , q ;
int a[ MAXN ] ;
int pos[ MAXN ] ;

vector < pair < int , int > > tosolve[ MAXN ] ;

vector < int > toadd[ MAXN ] ;

int ans[ MAXN ] ;

int LEAVES ;

struct Tree {
	int tr[ 3 * MAXN ] ;
	void init ( int where , int IL , int IR ) {
		if ( IL == IR ) {
			tr[ where ] = 0 ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
	}
	void update ( int where ) {
		while ( where != 0 ) {
			tr[ where ] ++ ;
			where /= 2 ;
		}
	}
	int query ( int where ) {
		int ret = 0 ;
		while ( where != 0 ) {
			if ( (where&(where-1)) == 0 ) {
				ret += tr[ where ] ;
				break ;
			}
			if ( ( where % 2 ) == 1 ) {
				where /= 2 ;
			}
			else {
				ret += tr[ where ] ;
				where -- ;
			}
		}
		return ret ;
	}
};
Tree w ;

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		pos[ a[ i ] ] = i ;
	}
	for ( i = 1 ; i <= q ; i ++ ) {
		int x , y ;
		scanf ( "%d%d" , &x , &y ) ;
		tosolve[ x ] .push_back ( make_pair ( y , i ) ) ;
	}
	LEAVES = 1 ;
	while ( LEAVES < n ) { LEAVES *= 2 ; }
	w.init ( 1 , 1 , LEAVES ) ;
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = i ; j <= n ; j += i ) {
			toadd[ min ( pos[ i ] , pos[ j ] ) ].push_back ( max ( pos[ i ] , pos[ j ] ) ) ;
		}
	}
	for ( i = n ; i >= 1 ; i -- ) {
		int sz = toadd[ i ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			w.update ( LEAVES + toadd[ i ][ j ] - 1 ) ;
		}
		sz = tosolve[ i ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			ans[ tosolve[ i ][ j ].second ] = w.query ( LEAVES + tosolve[ i ][ j ].first - 1 ) ;
		}
	}
	for ( i = 1 ; i <= q ; i ++ ) {
		printf ( "%d\n" , ans[ i ] ) ;
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}