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

#define MAXN 1000007

int n , m ;
int a[ MAXN ] ;

vector < pair < int , int > > st[ MAXN ] ;

int ans[ MAXN ] ;

map < int , int > ZX ;

int LEAVES ;
int tr[ 5 * MAXN ] ;
int pref[ MAXN ] ;

void update ( int where , int val ) {
	tr[ where ] = val ;
	where /= 2 ;
	while ( where != 0 ) {
		tr[ where ] = ( tr[ 2 * where ] ^ tr[ 2 * where + 1 ] ) ;
		where /= 2 ;
	}
}

int query ( int where ) {
	int ret = 0 ;
	while ( where != 0 ) {
		if ( ((where)&(where-1)) == 0 ) {
			ret ^= tr[ where ] ;
			break ;
		}
		if ( where % 2 == 0 ) {
			ret ^= tr[ where ] ;
			where -- ;
		}
		else {
			where /= 2 ;
		}
	}
	return ret ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		pref[ i ] = ( pref[ i - 1 ] ^ a[ i ] ) ;
	}
	scanf ( "%d" , &m ) ;
	int x , y ;
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		st[ y ].push_back ( make_pair ( x , i ) ) ;
	}
}

void solve ( ) {
	LEAVES = 1 ;
	while ( LEAVES < n ) { LEAVES *= 2 ; }
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( ZX.find ( a[ i ] ) != ZX.end ( ) ) {
			int u = ZX[ a[ i ] ] ;
			update ( LEAVES + u - 1 , 0 ) ;
		}
		update ( LEAVES + i - 1 , a[ i ] ) ;
		ZX[ a[ i ] ] = i ;
		int sz = st[ i ].size ( ) ;
		int init = query ( LEAVES + i - 1 ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			int u1 , u2 ;
			u1 = init ;
			if ( st[ i ][ j ].first != 1 ) { u1 ^=  query ( LEAVES + st[ i ][ j ].first - 2 ) ; }
			u2 = pref[ i ] ;
			if ( st[ i ][ j ].first != 1 ) { u2 ^= pref[ st[ i ][ j ].first - 1 ] ; }
			ans[ st[ i ][ j ].second ] = ( u1 ^ u2 ) ;
		}
	}
	for ( i = 1 ; i <= m ; i ++ ) {
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