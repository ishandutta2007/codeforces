#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 1007

int n , m ;
long long k ;
int a[ MAXN ][ MAXN ] ;
int par[ MAXN * MAXN ] ;
int sz[ MAXN * MAXN ] ;
int used[ MAXN ][ MAXN ] ;

int dx[ 4 ] = { 1 , -1 , 0 , 0 } ;
int dy[ 4 ] = { 0 , 0 , 1 , -1 } ; 

struct tuhla {
	int val ;
	int x , y ;
};

vector < struct tuhla > v ;

bool cmp ( struct tuhla p1 , struct tuhla p2 ) {
	return ( p1.val > p2.val ) ;
}

int code ( int x , int y ) {
	return ( ( x - 1 ) * m + y ) ;
}


int find ( int x ) {
	if ( par[ x ] == -1 ) { return x ; }
	int y = find ( par[ x ] ) ;
	par[ x ] = y ;
	return par[ x ] ;
}

void UNITE ( int x , int y ) {
	int k1 = find ( x ) ;
	int k2 = find ( y ) ;
	if ( k1 != k2 ) {
		sz[ k1 ] += sz[ k2 ] ;
		par[ k2 ] = k1 ;
	}
}

void bfs ( int stx , int sty , int br , int val ) {
	int i ;
	used[ stx ][ sty ] = 1 ;
	br -- ;
	queue < pair < int , int > > q ;
	q.push ( make_pair ( stx , sty ) ) ;
	pair < int , int > u , e ; 
	while ( q.empty ( ) == false ) {
		u = q.front ( ) ;
		q.pop ( ) ;
		for ( i = 0 ; i < 4 ; i ++ ) {
			e.first = u.first + dx[ i ] ;
			e.second = u.second + dy[ i ] ;
			if ( e.first < 1 || e.first > n ) { continue ; }
			if ( e.second < 1 || e.second > m ) { continue ; }
			if ( used[ e.first ][ e.second ] == 1 ) { continue ; }
			if ( a[ e.first ][ e.second ] < val ) { continue ; }
			if ( br == 0 ) { return ; }
			used[ e.first ][ e.second ] = 1 ;
			q.push ( e ) ;
			br -- ;
			if ( br == 0 ) { return ; }
		}
	}
}

void input ( ) {
	scanf ( "%d%d%I64d" , &n , &m , &k ) ;
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= m ; j ++ ) {
			scanf ( "%d" , &a[ i ][ j ] ) ;
			struct tuhla u ;
			u.val = a[ i ][ j ] ;
			u.x = i ;
			u.y = j ;
			v.push_back ( u ) ;
		}
	}
	sort ( v.begin ( ) , v.end ( ) , cmp ) ;
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n * m ; i ++ ) {
		par[ i ] = -1 ;
		sz[ i ] = 1 ;
	}
	for ( i = 0 ; i < n * m ; i ++ ) {
		for ( j = 0 ; j < 4 ; j ++ ) {
			int nx = v[ i ].x + dx[ j ] ;
			int ny = v[ i ].y + dy[ j ] ;
			if ( nx < 1 || nx > n ) { continue ; }
			if ( ny < 1 || ny > m ) { continue ; }
			if ( a[ nx ][ ny ] < a[ v[ i ].x ][ v[ i ].y ] ) { continue ; }
			UNITE ( code ( v[ i ].x , v[ i ].y ) , code ( nx , ny ) ) ;
		}
		if ( ( k % v[ i ].val ) == 0 && sz[ find ( code ( v[ i ].x , v[ i ].y ) ) ] >= ( k / v[ i ].val ) ) { break ; }
	}
	if ( i == n * m ) { printf ( "NO\n" ) ; return ; }
	printf ( "YES\n" ) ;
	bfs ( v[ i ].x , v[ i ].y , ( k / v[ i ].val ) , v[ i ].val ) ;
	int val = v[ i ].val ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= m ; j ++ ) {
			if ( used[ i ][ j ] == 1 ) { printf ( "%d" , val ) ; }
			else { printf ( "0" ) ; }
			if ( j == m ) { printf ( "\n" ) ; }
			else { printf ( " " ) ; }
		}
	}
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}