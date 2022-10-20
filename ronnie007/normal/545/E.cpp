#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<ctime>
using namespace std ;

#define MAXN 300007
#define inf 1000000007

int n ;
int root ;

struct tuhla {
	int vertex ;
	long long cost ;
	int id ;
};

int init[ MAXN ] ;
long long dist[ MAXN ] ;

vector < struct tuhla > v[ MAXN ] ;

bool cmp ( struct tuhla p1 , struct tuhla p2 ) {
	return ( p1.cost < p2.cost ) ;
}

bool operator < ( struct tuhla p1 , struct tuhla p2 ) {
	if ( p1.cost != p2.cost ) { return ( p1.cost > p2.cost ) ; }
	return ( init[ p1.id ] > init[ p2.id ] ) ;
}
priority_queue < struct tuhla > q ;

vector < int > ret ;

long long SM = 0 ;

void dijkstra ( int st ) {
	struct tuhla u , r ;
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		dist[ i ] = inf ;
		dist[ i ] *= dist[ i ] ;
    }
	u.vertex = st ;
	u.cost = 0 ;
	u.id = 0 ;
	q.push ( u ) ;
	while ( q.empty ( ) == false ) {
		u = q.top ( ) ;
		q.pop ( ) ;
		if ( dist[ u.vertex ] <= u.cost ) { continue ; }
		dist[ u.vertex ] = u.cost ;
		if ( u.id != 0 ) { ret.push_back ( u.id ) ; SM += init[ u.id ] ; }
		int sz = v[ u.vertex ].size ( ) ;
		for ( i = 0 ; i < sz ; i ++ ) {
			int h = v[ u.vertex ][ i ].vertex ;
			int c = v[ u.vertex ][ i ].cost ;
			if ( dist[ h ] > u.cost + c ) {
				//dist[ h ] = u.cost + c ;
				r.vertex = h ;
				r.cost = u.cost + c ;
				r.id = v[ u.vertex ][ i ].id ;
				q.push ( r ) ;
            }
        }
    }
}

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	int m ;
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	int x , y , z ;
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d%d" , &x , &y , &z ) ;
		init[ i ] = z ;
		struct tuhla u ;
		u.id = i ;
		u.cost = z ; 
		u.vertex = y ;
		v[ x ].push_back ( u ) ;
		u.vertex = x ;
		v[ y ].push_back ( u ) ;
    }
	for ( i = 1 ; i <= n ; i ++ ) {
		//sort ( v[ i ].begin ( ) , v[ i ].end ( ) , cmp ) ;
    }
	scanf ( "%d" , &root ) ;
}

void solve ( )  {
	dijkstra ( root ) ;
	int sz = ret.size ( ) ;
	printf ( "%I64d\n" , SM ) ;
	int i ;
	for ( i = 0 ; i < sz ; i ++ ) {
		printf ( "%d" , ret[ i ] ) ;
		if ( i == sz - 1 ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
    }
}