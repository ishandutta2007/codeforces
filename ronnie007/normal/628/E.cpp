#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 3007

#define OFFSET 3000

int n , m ;
char a[ MAXN ][ MAXN ] ;
short zl[ MAXN ][ MAXN ] ;
short zr[ MAXN ][ MAXN ] ;
short zld[ MAXN ][ MAXN ] ;

short pos_in_tree[ MAXN ][ MAXN ] ;
bool used[ MAXN ][ MAXN ] ;

struct Tree {
	short tr[ 3 * MAXN ] ;
	void init ( int where , int IL , int IR ) {
		tr[ where ] = 0 ;
		if ( IL == IR ) { return ; }
		int mid = ( IL + IR ) / 2 ;
		init ( 2 * where , IL , mid ) ;
		init ( 2 * where + 1 , mid + 1 , IR ) ;
	}
	void update ( int where , int IL , int IR , int pos ) {
		if ( IL > IR ) { return ; }
		if ( IR < pos || pos < IL ) { return ; }
		if ( IL == IR && IL == pos ) {
			tr[ where ] ++ ;
			return ;
		}
		int mid = ( IL + IR ) / 2 ;
		update ( 2 * where , IL , mid , pos ) ;
		update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
		tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
	}
	int query ( int where , int IL , int IR , int CURL , int CURR ) {
		if ( CURL > CURR ) { return 0 ; }
		if ( IL > IR ) { return 0 ; }
		if ( IR < CURL || CURR < IL ) { return 0 ; }
		if ( CURL <= IL && IR <= CURR ) {
			return tr[ where ] ;
		}
		int mid = ( IL + IR ) / 2 ;
		return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
	}
};

Tree w[ 2 * MAXN ] ;

vector < pair < int , int > > v[ 2 * MAXN ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i , j ;
	char foo[ MAXN ] ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "\n%s" , &foo ) ;
		for ( j = 1 ; j <= m ; j ++ ) {
			a[ i ][ j ] = foo[ j - 1 ] ;
		}
	}
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= m ; j ++ ) {
			if ( a[ i ][ j ] == 'z' ) { zl[ i ][ j ] = zl[ i ][ j - 1 ] + 1 ; }
			else { zl[ i ][ j ] = 0 ; }
		}
	}
	for ( i = n ; i >= 1 ; i -- ) {
		for ( j = m ; j >= 1 ; j -- ) {
			if ( a[ i ][ j ] == 'z' ) {
				zr[ i ][ j ] = zr[ i ][ j + 1 ] + 1 ;
				zld[ i ][ j ] = zld[ i + 1 ][ j - 1 ] + 1 ;
			}
			else {
				zr[ i ][ j ] = zld[ i ][ j ] = 0 ;
			}
		}
	}
	for ( i = 1 ; i <= n + m ; i ++ ) {
		w[ i ].init ( 1 , 1 , 3000 ) ;
	}
	int id = 1 ;
	int x , y ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= m ; j ++ ) {
			if ( used[ i ][ j ] == false ) {
				x = i ;
				y = j ;
				id = 1 ;
				while ( 1 ) {
					if ( a[ x ][ y ] == 'z' ) {
						v[ zr[ x ][ y ] + y - 1 ].push_back ( make_pair ( x , y ) ) ;
					}
					pos_in_tree[ x ][ y ] = id ;
					id ++ ;
					used[ x ][ y ] = true ;
					x ++ ;
					y -- ;
					if ( x > n ) { break ; }
					if ( y < 1 ) { break ; }
				}
			}
		}
	}
	long long ans = 0 ;
	for ( j = m ; j >= 1 ; j -- ) {
		int sz = v[ j ].size ( ) ;
		for ( i = 0 ; i < sz ; i ++ ) {
			int id = v[ j ][ i ].first + v[ j ][ i ].second ;
			int st = pos_in_tree[ v[ j ][ i ].first ][ v[ j ][ i ].second ] ;
			w[ id ].update ( 1 , 1 , 3000 , st ) ;
		}
		for ( i = 1 ; i <= n ; i ++ ) {
			if ( a[ i ][ j ] == '.' ) { continue ; }
			int len = min ( zl[ i ][ j ] , zld[ i ][ j ] ) ;
			int id = i + j ;
			int st = pos_in_tree[ i ][ j ] ;
			int en = pos_in_tree[ i ][ j ] + len - 1 ;
			ans += w[ id ].query ( 1 , 1 , 3000 , st , en ) ;
		}
	}
	printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}