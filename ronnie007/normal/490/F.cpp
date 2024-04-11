#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<set>
#include<map>
using namespace std ;

#define MAXN 6007

int n ;
int a[ MAXN ] ;

map < int , int > ZX ;

vector < int > v[ MAXN ] ;

short ic[ MAXN ] ;
short dc[ MAXN ] ;

int ans = 0 ;

void dfs ( int vertex , int prv ) {
	int i , j , sz ;
	sz = v[ vertex ].size ( ) ;
	short curinc[ MAXN ] ;
	short curdec[ MAXN ] ;
	for ( i = 1 ; i <= 6000 ; i ++ ) {
		curinc[ i ] = curdec[ i ] = 0 ;
	}
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		dfs ( v[ vertex ][ i ] , vertex ) ;
		short mx = 0 ;
		for ( j = 1 ; j <= 6000 ; j ++ ) {
			if ( ans < ( mx + dc[ j ] ) ) {
				ans = ( mx + dc[ j ] ) ;
			}
			if ( mx < curinc[ j ] ) { mx = curinc[ j ] ; }
		}
		mx = 0 ;
		for ( j = 6000 ; j >= 1 ; j -- ) {
			if ( ans < ( mx + ic[ j ] ) ) {
				ans = ( mx + ic[ j ] ) ;
			}
			if ( mx < curdec[ j ] ) { mx = curdec[ j ] ; }
		}
		mx = 0 ;
		for ( j = 1 ; j < a[ vertex ] ; j ++ ) {
			if ( mx < curinc[ j ] ) { mx = curinc[ j ] ; }
		}
		short u = 0 ;
		for ( j = a[ vertex ] + 1 ; j <= 6000 ; j ++ ) {
			if ( u < dc[ j ] ) { u = dc[ j ] ; }
		}
		if ( ans < mx + u + 1 ) { ans = mx + u + 1 ; }		
		mx = u = 0 ;
		for ( j = 1 ; j < a[ vertex ] ; j ++ ) {
			if ( mx < ic[ j ] ) { mx = ic[ j ] ; }
		}
		for ( j = a[ vertex ] + 1 ; j <= 6000 ; j ++ ) {
			if ( u < curdec[ j ] ) { u = curdec[ j ] ; }
		}
		if ( ans < mx + u + 1 ) { ans = mx + u + 1 ; }	
		for ( j = 1 ; j <= 6000 ; j ++ ) {
			curinc[ j ] = max ( curinc[ j ] , ic[ j ] ) ;
			curdec[ j ] = max ( curdec[ j ] , dc[ j ] ) ;			
		}
	}
	short mx = 0 ;
	for ( i = 1 ; i < a[ vertex ] ; i ++ ) {
		if ( mx < curinc[ i ] ) { mx = curinc[ i ] ; }
	}
	mx ++ ;
	curinc[ a[ vertex ] ] = max ( curinc[ a[ vertex ] ] , mx ) ;
	mx = 0 ;
	for ( i = a[ vertex ] + 1 ; i <= 6000 ; i ++ ) {
		if ( mx < curdec[ i ] ) { mx = curdec[ i ] ; }
	}
	mx ++ ;
	curdec[ a[ vertex ] ] = max ( curdec[ a[ vertex ] ] , mx ) ;
	for ( i = 1 ; i <= 6000 ; i ++ ) {
		ic[ i ] = curinc[ i ] ;
		dc[ i ] = curdec[ i ] ;
	}
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	vector < int > g ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		g.push_back ( a[ i ] ) ;
	}
	sort ( g.begin ( ) , g.end ( ) ) ;
	ZX[ g[ 0 ] ] = 1 ;
	int id = 2 ;
	for ( i = 1 ; i < n ; i ++ ) {
		if ( g[ i ] == g[ i - 1 ] ) { continue ; }
		ZX[ g[ i ] ] = id ;
		id ++ ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		a[ i ] = ZX[ a[ i ] ] ;
	}
	int x , y ;
	for ( i = 1 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
}

void solve ( ) {
	dfs ( 1 , -1 ) ;
	int i ;
	for ( i = 1 ; i <= 6000 ; i ++ ) {
		if ( ans < ic[ i ] ) { ans = ic[ i ] ; }
		if ( ans < dc[ i ] ) { ans = dc[ i ] ; }
	}
	printf ( "%d\n" , ans ) ;
}

int main ( ) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input ( ) ;
	solve ( ) ;
	return 0 ;
}