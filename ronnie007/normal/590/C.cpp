#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

#define MAXN 1007
#define inf 1000000007


int n , m ;
string a[ MAXN ] ;
int dist[ 3 ][ MAXN ][ MAXN ] ;

int dx[ 4 ] = { 0 , 0 , 1 , -1 } ;
int dy[ 4 ] = { 1 , -1 , 0 , 0 } ;


void bfs ( int id ) {
	int i , j ;
	queue < pair < int , int > > q ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( ( a[ i ][ j ] - '0' ) == ( id + 1 ) ) {
				dist[ id ][ i ][ j ] = 0 ;
				q.push ( make_pair ( i , j ) ) ;
			}
			else { dist[ id ][ i ][ j ] = inf ; }
		}
	}
	pair < int , int > p , e ;
	while ( q.empty ( ) == false ) {
		p = q.front ( ) ;
		q.pop ( ) ;
		for ( i = 0 ; i < 4 ; i ++ ) {
			e.first = p.first + dx[ i ] ;
			e.second = p.second + dy[ i ] ;
			if ( e.first < 0 || e.first >= n ) { continue ; }
			if ( e.second < 0 || e.second >= m ) { continue ; }
			int val ;
			if ( a[ e.first ][ e.second ] == '.' ) { val = 1 ; }
			else { val = 0 ; }
			if ( dist[ id ][ e.first ][ e.second ] <= dist[ id ][ p.first ][ p.second ] + val ) { continue ; }
			if ( a[ e.first ][ e.second ] == '#' ) { continue ; }

			dist[ id ][ e.first ][ e.second ] = dist[ id ][ p.first ][ p.second ] + val ;
			q.push ( e ) ;
		}
	}
}

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	cin >> n >> m ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		cin >> a[ i ] ;
	}
}

void solve ( ) {
	bfs ( 0 ) ;
	bfs ( 1 ) ;
	bfs ( 2 ) ;
	int i , j , t ;
	int ans = inf ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( dist[ 0 ][ i ][ j ] == inf ) { continue ; }
			if ( dist[ 1 ][ i ][ j ] == inf ) { continue ; }
			if ( dist[ 2 ][ i ][ j ] == inf ) { continue ; }
			int cur = dist[ 0 ][ i ][ j ] + dist[ 1 ][ i ][ j ] + dist[ 2 ][ i ][ j ] ;
			if ( a[ i ][ j ] == '.' ) { cur -= 2 ; }
			if ( cur < ans ) { ans = cur ; }
		}
	}
	if ( ans == inf ) { printf ( "-1\n" ) ; }
	else { printf ( "%d\n" , ans ) ; }
}