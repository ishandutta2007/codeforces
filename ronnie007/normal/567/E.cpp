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

#define MAXN 100007
#define MOD 961748941
int n , m , source , target ;

struct inp_edge {
	long long x , y , z ;
};

struct inp_edge H[ MAXN ] ;

struct edge {
	int to ;
	long long len ;
};

long long Dist[ 2 ][ MAXN ] ;
long long Ways[ 2 ][ MAXN ] ;

vector < struct edge > v[ 2 ][ MAXN ] ;

bool operator < ( struct edge p1 , struct edge p2 ) {
	return ( p1.len > p2.len ) ;
}

priority_queue < struct edge > q ;
pair < long long , int > srt[ MAXN ] ;


void dijkstra ( int vertex , int id ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) { Dist[ id ][ i ] = ( m + 1 ) * ( ( MAXN * 10LL ) )  ; Ways[ id ][ i ] = 0 ; }
	Dist[ id ][ vertex ] = 0 ;
	struct edge e , u ;
	e.to = vertex ;
	e.len = 0 ;
	q.push ( e ) ;
	while ( q.empty ( ) == false ) {
		e = q.top ( ) ;
		q.pop ( ) ;
		int sz = v[ id ][ e.to ].size ( ) ;
		for ( i = 0 ; i < sz ; i ++ ) {
			if ( Dist[ id ][ v[ id ][ e.to ][ i ].to ] > Dist[ id ][ e.to ] + v[ id ][ e.to ][ i ].len ) {
				Dist[ id ][ v[ id ][ e.to ][ i ].to ] = Dist[ id ][ e.to ] + v[ id ][ e.to ][ i ].len ;
				u.to = v[ id ][ e.to ][ i ].to ;
				u.len = Dist[ id ][ v[ id ][ e.to ][ i ].to ] ;
				q.push ( u ) ;
            }
        }
    }
	Ways[ id ][ vertex ] = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		srt[ i ].first = Dist[ id ][ i ] ;
		srt[ i ].second = i ;
    }
	sort ( srt + 1 , srt + n + 1 ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int sz = v[ id ][ srt[ i ].second ].size ( ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			if ( Dist[ id ][ v[ id ][ srt[ i ].second ][ j ].to ] - v[ id ][ srt[ i ].second ][ j ].len == srt[ i ].first ) {
				Ways[ id ][ v[ id ][ srt[ i ].second ][ j ].to ] += Ways[ id ][ srt[ i ].second ] ;
				Ways[ id ][ v[ id ][ srt[ i ].second ][ j ].to ] %= MOD ;
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
	scanf ( "%d%d%d%d" , &n , &m , &source , &target ) ;
	int i ;
	struct edge u ;
	int x , y , z ;
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d%d%d" , &x , &y , &z ) ;
		u.to = y ;
		u.len = z ;
		v[ 0 ][ x ].push_back ( u ) ;
		u.to = x ;
		v[ 1 ][ y ].push_back ( u ) ;
		H[ i ].x = x ;
		H[ i ].y = y ;
		H[ i ].z = z ;
    }
}

void solve ( )  {
	dijkstra ( source , 0 ) ;
	dijkstra ( target , 1 ) ;
	int i , j ;
	for ( i = 0 ; i < m ; i ++ ) {
		if ( Dist[ 0 ][ H[ i ].x ] + H[ i ].z + Dist[ 1 ][ H[ i ].y ] == Dist[ 0 ][ target ] ) {
			if ( ( Ways[ 0 ][ H[ i ].x ] * Ways[ 1 ][ H[ i ].y ] ) % MOD == Ways[ 0 ][ target ] ) {
				printf ( "YES\n" ) ;
           	}
			else {
				if ( H[ i ].z != 1 ) { printf ( "CAN 1\n" ) ; }
				else { printf ( "NO\n" ) ; }
			}
		}
		else {
			if ( H[ i ].z > Dist[ 0 ][ H[ i ].x ] + H[ i ].z + Dist[ 1 ][ H[ i ].y ] - Dist[ 0 ][ target ] + 1 ) {
				printf ( "CAN %d\n" ,  Dist[ 0 ][ H[ i ].x ] + H[ i ].z + Dist[ 1 ][ H[ i ].y ] - Dist[ 0 ][ target ] + 1 ) ;
            }
			else { printf ( "NO\n" ) ; }
        }
    }
}