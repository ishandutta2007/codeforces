#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
using namespace std ;

#define MAXN 1007

int n , m , w ;
int a[ MAXN ] ;
int val[ MAXN ] ;
vector < int > v[ MAXN ] ;

int used[ MAXN ] ;

vector < int > g ;

int dp[ MAXN ] ;
int f[ MAXN ] ;

void dfs ( int vertex ) {
	g.push_back ( vertex ) ;
	used[ vertex ] = 1 ; 
	int i ;
	int sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( used[ v[ vertex ][ i ] ] != 0 ) { continue ; }
		dfs ( v[ vertex ][ i ] ) ;
	}
}

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &w ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &val[ i ] ) ;
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		int x , y ;
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
}

void solve ( ) {
	int sz ;
	int i , j , t ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( used[ i ] == 0 ) {
			g.clear ( ) ;
			dfs ( i ) ;
			sz = g.size ( ) ;
			for ( j = 0 ; j <= w ; j ++ ) { f[ j ] = 0 ; }
			int totw = 0 ;
			int totval = 0 ;
			for ( j = 0 ; j < sz ; j ++ ) {
				int id = g[ j ] ;
				totw += a[ id ] ;
				totval += val[ id ] ;
				for ( t = 0 ; t + a[ id ] <= w ; t ++ ) {
					f[ t + a[ id ] ] = max ( f[ t + a[ id ] ] , dp[ t ] + val[ id ] ) ;
				}
			}
			for ( t = 0 ; t + totw <= w ; t ++ ) {
				f[ t + totw ] = max ( f[ t + totw ] , dp[ t ] + totval ) ;
			}
			for ( j = 0 ; j <= w ; j ++ ) {
				dp[ j ] = max ( dp[ j ] , f[ j ] ) ;
			}
		}
	}
	int ans = 0 ;
	for ( i = 0 ; i <= w ; i ++ ) {
		if ( ans < dp[ i ] ) { ans = dp[ i ] ; }
	}
	printf ( "%d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}