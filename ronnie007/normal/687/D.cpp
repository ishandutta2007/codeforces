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

#define MAXN 1007

int n , m , q ; 

int IL , IR ;

struct tuhla {
	int x , y ;
	int cost ;
	int id ; 
};

vector < struct tuhla > v ;
int par[ MAXN ] ;
int flip[ MAXN ] ;
int col[ MAXN ] ;
vector < int > comp[ MAXN ] ;
int ind[ MAXN ] ;

bool operator < ( struct tuhla p1 , struct tuhla p2 ) {
	return ( p1.cost > p2.cost ) ;
}

vector < int > prq ;

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &q ) ;
	int i ;
	struct tuhla u ; 
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d%d" , &u.x , &u.y , &u.cost ) ;
		u.id = i ;
		v.push_back ( u ) ;
	}
	sort ( v.begin ( ) , v.end ( ) ) ;
}

void solve ( ) {
	int i , j ; 
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d%d" , &IL , &IR ) ;
		for ( i = 1 ; i <= n ; i ++ ) {
			par[ i ] = -1 ;
			flip[ i ] = false ;
			col[ i ] = 0 ;
			comp[ i ].clear ( ) ;
			comp[ i ].push_back ( i ) ;
			ind[ i ] = i ;
		}
		for ( i = 0 ; i < m ; i ++ ) {
			if ( v[ i ].id < IL || IR < v[ i ].id ) { continue ; }	
			int k1 = ind[ v[ i ].x ] ;
			int k2 = ind[ v[ i ].y ] ;
			if ( k1 == k2 ) {
				if ( col[ v[ i ].x ] == col[ v[ i ].y ] ) {
					printf ( "%d\n" , v[ i ].cost ) ;
					break ; 
				}
			}
			else {
				if ( comp[ k1 ].size ( ) > comp[ k2 ].size ( ) ) { swap ( k1 , k2 ) ; }
				par[ k1 ] = k2 ;
				int sz = comp[ k1 ].size ( ) ;

				if ( col[ v[ i ].x ] != 0 && col[ v[ i ].x ] == col[ v[ i ].y ] ) {
					for ( j = 0 ; j < sz ; j ++ ) {
						col[ comp[ k1 ][ j ] ] = 3 - col[ comp[ k1 ][ j ] ] ;
					}					
				}
				if ( col[ v[ i ].x ] == 0 && col[ v[ i ].y ] == 0 ) {
					col[ v[ i ].x ] = 1 ;
					col[ v[ i ].y ] = 2 ;
				}
				if ( col[ v[ i ].x ] == 0 ) { col[ v[ i ].x ] = 3 - col[ v[ i ].y ] ; }
				if ( col[ v[ i ].y ] == 0 ) { col[ v[ i ].y ] = 3 - col[ v[ i ].x ] ; }

				for ( j = 0 ; j < sz ; j ++ ) {
					comp[ k2 ].push_back ( comp[ k1 ][ j ] ) ;
					ind[ comp[ k1 ][ j ] ] = k2 ; 
				}
			}
		}
		if ( i == m ) { printf ( "-1\n" ) ; }
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}