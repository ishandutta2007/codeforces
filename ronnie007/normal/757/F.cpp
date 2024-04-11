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

#define MAXN 200007
#define LOG 22 

int n , m , st ;


long long dist[ MAXN ] ;
long long ways[ MAXN ] ;

int prv[ MAXN ][ LOG + 2 ] ;
int lvl[ MAXN ] ;

int ans[ MAXN ] ;

vector < int > g[ MAXN ] ;

struct tuhla {
	int vertex ;
	long long cost ;
	tuhla ( ) { vertex = cost = 0 ; }
	tuhla ( int x , long long y ) {
		vertex = x ;
		cost = y ;
	}
};

vector < tuhla > v[ MAXN ] ;

bool operator < ( tuhla p1 , tuhla p2 ) {
	return ( p1.cost > p2.cost ) ;
}

bool cmp ( tuhla p1 , tuhla p2 ) {
	return ( p1.cost < p2.cost ) ;
}

void dijkstra ( ) {
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		dist[ i ] = -1 ;
	}
	dist[ st ] = 0 ;
	priority_queue < tuhla > q ;
	q.push ( tuhla ( st , 0 ) ) ;
	tuhla u , e ;
	while ( q.empty ( ) == false ) {
		u = q.top ( ) ;
		q.pop ( ) ;
		if ( u.cost > dist[ u.vertex ] ) { continue ; }
		int sz = v[ u.vertex ].size ( ) ;
		for ( i = 0 ; i < sz ; i ++ ) {
			int h = v[ u.vertex ][ i ].vertex ;
			int c = v[ u.vertex ][ i ].cost ;
			if ( dist[ h ] == -1 || dist[ h ] > u.cost + c ) {
				dist[ h ] = u.cost + c ;
				q.push ( tuhla ( h , u.cost + c ) ) ;
			}
		}
	}
}

int LCA ( int x , int y ) {
	int i ;
	for ( i = LOG - 1 ; i >= 0 ; i -- ) {
		if ( lvl[ x ] - (1<<i) >= lvl[ y ] ) {
			x = prv[ x ][ i ] ;
		}
		if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
			y = prv[ y ][ i ] ;
		}
	}
	for ( i = LOG - 1 ; i >= 0 ; i -- ) {
		if ( prv[ x ][ i ] != prv[ y ][ i ] ) {
			x = prv[ x ][ i ] ;
			y = prv[ y ][ i ] ;
		}
	}
	if ( x != y ) { x = prv[ x ][ 0 ] ; }
	return x ;
}


void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &st ) ;
	int i ;
	for ( i = 1 ; i <= m ; i ++ ) {
		int x , y , z ;
		scanf ( "%d%d%d" , &x , &y , &z ) ;
		v[ x ].push_back ( tuhla ( y , z ) ) ;
		v[ y ].push_back ( tuhla ( x , z ) ) ;
	}
}

void solve ( ) {
	dijkstra ( ) ;
	vector < tuhla > srt ;
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( dist[ i ] != -1 ) {
			srt.push_back ( tuhla ( i , dist[ i ] ) ) ;
		}
	}
	sort ( srt.begin ( ) , srt.end ( ) , cmp ) ;
	int k = srt.size ( ) ;
	ways[ st ] = 1 ;
	for ( i = 0 ; i < k ; i ++ ) {
		int sz = v[ srt[ i ].vertex ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			int h = v[ srt[ i ].vertex ][ j ].vertex ;
			int c = v[ srt[ i ].vertex ][ j ].cost ;
			if ( dist[ h ] == srt[ i ].cost + c ) {
				ways[ h ] ++ ;
				g[ h ].push_back ( srt[ i ].vertex ) ;
			}
		}
	}
	/**
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( ways[ i ] == 1 && prv[ i ] == st ) {
			prv[ i ] = -1 ;
		}
	}
	**/
	for ( i = 0 ; i < k ; i ++ ) {
		if ( srt[ i ].vertex == st ) { continue ; }
		int sz = g[ srt[ i ].vertex ].size ( ) ;
		int u = g[ srt[ i ].vertex ][ 0 ] ;
		for ( j = 0 ; j < sz ; j ++ ) {
			u = LCA ( u , g[ srt[ i ].vertex ][ j ] ) ;
		}
		prv[ srt[ i ].vertex ][ 0 ] = u ;
		lvl[ srt[ i ].vertex ] = lvl[ u ] + 1 ;
		for ( j = 1 ; j < LOG ; j ++ ) {
			int aux = prv[ srt[ i ].vertex ][ j - 1 ] ;
			if ( aux != -1 ) {
				prv[ srt[ i ].vertex ][ j ] = prv[ aux ][ j - 1 ] ;
			}
			else { prv[ srt[ i ].vertex ][ j ] = -1 ; }
		}
	}
	for ( i = k - 1 ; i >= 0 ; i -- ) {
		ans[ srt[ i ].vertex ] ++ ;
		if ( prv[ srt[ i ].vertex ][ 0 ] != -1 ) {
			ans[ prv[ srt[ i ].vertex ][ 0 ] ] += ans[ srt[ i ].vertex ] ;
		}
	}
	int ret = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( i == st ) { continue ; }
		if ( ret < ans[ i ] + 1 ) { ret = ans[ i ] ; }
	}
	printf ( "%d\n" , ret ) ;
}

int main ( ) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	input ( ) ;
	solve ( ) ;
	return 0 ;
}