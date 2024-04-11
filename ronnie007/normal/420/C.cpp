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

int n , p ;
pair < int , int > a[ MAXN ] ;
vector < int > v[ MAXN ] ;
int br[ MAXN ] ;

map < pair < int , int > , int > ZX ;
map < pair < int , int > , bool > g ;
int LEAVES ;

struct segment_tree {
	int tr[ 4 * MAXN ] ;
	void update ( int where , int val ) {
		while ( where != 0 ) {
			tr[ where ] += val ;
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
			if ( ( where % 2 ) == 0 ) {
				ret += tr[ where ] ;
				where -- ;
			}
			else {
				where /= 2 ;			
			}
		}
		return ret ;
	}
};

segment_tree w ;

void input ( ) {
	scanf ( "%d%d" , &n , &p ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
		br[ a[ i ].first ] ++ ;
		br[ a[ i ].second ] ++ ;
		v[ a[ i ].first ].push_back ( a[ i ].second ) ;
		v[ a[ i ].second ].push_back ( a[ i ].first ) ;
		if ( a[ i ].first > a[ i ].second ) { swap ( a[ i ].first , a[ i ].second ) ; }
		ZX[ a[ i ] ] ++ ;
	}
}

void solve ( ) {
	LEAVES = 1 ;
	while ( LEAVES < n ) { LEAVES *= 2 ; }
	int i , j , sz ;
	long long ans = 0 ;
	int init = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		sort ( v[ i ].begin ( ) , v[ i ].end ( ) ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		w.update ( LEAVES + br[ i ] , 1 ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( g[ a[ i ] ] == true ) { continue ; }
		g[ a[ i ] ] = true ;
		int cur = br[ a[ i ].first ] + br[ a[ i ].second ] ;
		cur -= ZX[ a[ i ] ] ;
		if ( cur >= p ) { init ++ ; }
	}
	
	for ( i = 1 ; i <= n ; i ++ ) {
		int lft = ( p - br[ i ] ) ;
		if ( lft < 0 ) { lft = 0 ; }
		int h = w.tr[ 1 ] ;
		if ( lft != 0 ) { h -= w.query ( LEAVES + lft - 1 ) ; }
		if ( 2 * br[ i ] >= p ) { h -- ; }
		sz = v[ i ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			if ( j != 0 && v[ i ][ j ] == v[ i ][ j - 1 ] ) { continue ; }
			if ( br[ i ] + br[ v[ i ][ j ] ] >= p ) { h -- ; }
		}
		ans += h ;
	}
	ans /= 2 ;
	ans += init ;
	printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}