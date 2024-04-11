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
vector < pair < int , long long > > v[ MAXN ] ;
long long val[ MAXN ] ;

int prv[ MAXN ] ;

int lca[ MAXN ][ 22 ] ;
int lvl[ MAXN ] ;

pair < int , int > edges[ MAXN ] ;

int find ( int x ) {
	if ( x == 0 || val[ x ] > 1 ) { return x ; }
	int ans = find ( prv[ x ] ) ;
	prv[ x ] = ans ;
	return ans ;
}

void dfs ( int vertex , int lst , int w ) {
	int i ;
	for ( i = 1 ; i <= 20 ; i ++ ) {
		lca[ vertex ][ i ] = lca[ lca[ vertex ][ i - 1 ] ][ i - 1 ] ;
	}
	int sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ].first == lst ) { continue ; }
		lca[ v[ vertex ][ i ].first ][ 0 ] = vertex ;
		lvl[ v[ vertex ][ i ].first ] = lvl[ vertex ] + 1 ;
		val[ v[ vertex ][ i ].first ] = v[ vertex ][ i ].second ;
		if ( val[ v[ vertex ][ i ].first ] > 1 ) {
			prv[ v[ vertex ][ i ].first ] = v[ vertex ][ i ].first ;
		}
		else {
			prv[ v[ vertex ][ i ].first ] = w ;
		}
		if ( val[ v[ vertex ][ i ].first ] > 1 ) {
			dfs ( v[ vertex ][ i ].first , vertex , v[ vertex ][ i ].first ) ;
		}
		else {
			dfs ( v[ vertex ][ i ].first , vertex , w ) ;
		}
	}
}

int LCA ( int x , int y ) {
	int i ;
	for ( i = 20 ; i >= 0 ; i -- ) {
		int u = (1<<i) ;
		if ( lvl[ x ] - u >= lvl[ y ] ) {
			x = lca[ x ][ i ] ;
		}
		if ( lvl[ y ] - u >= lvl[ x ]  ) {
			y = lca[ y ][ i ] ;
		}
	}
	for ( i = 20 ; i >= 0 ; i -- ) {
		if ( lca[ x ][ i ] != lca[ y ][ i ] ) {
			x = lca[ x ][ i ] ;
			y = lca[ y ][ i ] ;
		}
	}
	if ( x != y ) { x = lca[ x ][ 0 ] ; }
	return x ;
}

void input ( ) {
	cin >> n >> q ;
	int i ;
	for ( i = 1 ; i < n ; i ++ ) {
		int x , y ;
		long long z ;
		cin >> x >> y >> z ;
		edges[ i ] = make_pair ( x , y ) ;
		v[ x ].push_back ( make_pair ( y , z ) ) ;
		v[ y ].push_back ( make_pair ( x , z ) ) ;
	}
}

void solve ( ) {
	lvl[ 1 ] = 1 ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) { val[ i ] = 0 ; }
	dfs ( 1 , -1 , 0 ) ;
	int type ;
	int x , y ;
	long long z ;
	int br = 0 ;
	while ( q != 0 ) {
		q -- ;
		cin >> type ;
		if ( type == 1 ) {
			cin >> x >> y >> z ;
			br ++ ;
			int en = LCA ( x , y ) ;
			while ( z > 0 ) {
				int u1 , u2 ;
				u1 = find ( x ) ;
				u2 = find ( y ) ;				
				if ( lvl[ u1 ] > lvl[ en ] ) {
					z /= val[ u1 ] ;
					x = lca[ u1 ][ 0 ] ;
				}
				else {
					if ( lvl[ u2 ] > lvl[ en ] ) {
						z /= val[ u2 ] ;
						y = lca[ u2 ][ 0 ] ;
					}
					else { break ; }
				}
			}
			cout << z << "\n" ;
		}
		else {
			cin >> x >> z ;
			int id = edges[ x ].first ;
			if ( lvl[ id ] < lvl[ edges[ x ].second ] ) {
				id = edges[ x ].second ;
			}
			val[ id ] = z ;
			if ( z == 1 ) {
				prv[ id ] = prv[ lca[ id ][ 0 ] ] ;
			}
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