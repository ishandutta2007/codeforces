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

#define MAXN 1007

int n , m , k ;
vector < int > c ;
vector < int > v[ MAXN ] ;

int br[ MAXN ] ;

int used[ MAXN ] ;

void dfs ( int vertex , int id ) {
	used[ vertex ] = id ;
	int i , sz ;
	sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( used[ v[ vertex ][ i ] ] == 0 ) {
			dfs ( v[ vertex ][ i ] , id ) ;
		}
	}
}

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &k ) ;
	int i ;
	int x , y ;
	for ( i = 1 ; i <= k ; i ++ ) {
		scanf ( "%d" , &x ) ;
		c.push_back ( x ) ;
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
}

void solve ( ) {
	int i , j ;
	int mx = 0 ;
	int u = -1 ;
	int ans = 0 ;
	for ( i = 0 ; i < k ; i ++ ) {
		dfs ( c[ i ] , i + 1 ) ;
	}
	for ( i = 0 ; i < k ; i ++ ) {
		int cur = 0 ;
		for ( j = 1 ; j <= n ; j ++ ) {
			if ( used[ j ] == ( i + 1 ) ) { cur ++ ; }
		}
		if ( mx < cur ) { mx = cur ; u = ( i + 1 ) ; }
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( used[ i ] == 0 ) { used[ i ] = u ; }
	}
	for ( i = 0 ; i < k ; i ++ ) {
		int cur = 0 ;
		for ( j = 1 ; j <= n ; j ++ ) {
			if ( used[ j ] == ( i + 1 ) ) { cur ++ ; }
		}
		ans += ( cur * ( cur - 1 ) ) / 2 ;
	}
	printf ( "%d\n" , ( ans - m ) ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}