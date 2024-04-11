#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std ;

#define inf 1000000007
#define MAXN 3007

int n , m ;
vector < int > v[ MAXN ] ;

int s1 , t1 , l1 ;
int s2 , t2 , l2 ;

void input ( ) ;
void solve ( ) ;
int dist[ MAXN ][ MAXN ] ;

void bfs ( int vertex ) {
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		dist[ vertex ][ i ] = inf ;
    }
	dist[ vertex ][ vertex ] = 0 ;
	queue < int > q ;
	q.push ( vertex ) ;
	int x , y ;
	int sz ; 
	while ( q.empty ( ) == false ) {
		x = q.front ( ) ;
		q.pop ( ) ;
		sz = v[ x ].size ( ) ;
		for ( i = 0 ; i < sz ; i ++ ) {
			if ( dist[ vertex ][ v[ x ][ i ] ] == inf ) {
				dist[ vertex ][ v[ x ][ i ] ] = dist[ vertex ][ x ] + 1 ;
				q.push ( v[ x ][ i ] ) ;
            }
        }
    }
}

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	int x , y ;
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
    }
	scanf ( "%d%d%d" , &s1 , &t1 , &l1 ) ;
	scanf ( "%d%d%d" , &s2 , &t2 , &l2 ) ;
}

void solve ( )  {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		bfs ( i ) ;
    }
	int ans = dist[ s1 ][ t1 ] + dist[ s2 ][ t2 ]  ;
	if ( dist[ s1 ][ t1 ] > l1 || dist[ s2 ][ t2 ] > l2 ) { 
		printf ( "-1\n" ) ;
		return ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			//if ( i == j ) { continue ; }
			int tot = dist[ s1 ][ i ] + dist[ i ][ j ] + dist[ j ][ t1 ] ;
			if ( tot > l1 ) { continue ; }
			tot = dist[ s2 ][ i ] + dist[ i ][ j ] + dist[ j ][ t2 ] ;
			if ( tot > l2 ) { continue ; }
			tot += dist[ s1 ][ i ] + dist[ j ][ t1 ] ;
			if ( ans > tot ) { ans = tot ; }
        }
    }
	swap ( s1 , t1 ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			//if ( i == j ) { continue ; }
			int tot = dist[ s1 ][ i ] + dist[ i ][ j ] + dist[ j ][ t1 ] ;
			if ( tot > l1 ) { continue ; }
			tot = dist[ s2 ][ i ] + dist[ i ][ j ] + dist[ j ][ t2 ] ;
			if ( tot > l2 ) { continue ; }
			tot += dist[ s1 ][ i ] + dist[ j ][ t1 ] ;
			if ( ans > tot ) { ans = tot ; }
        }
    }

	printf ( "%d\n" , m - ans ) ;
}