#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;

#define UP 1
#define DOWN -1
#define LEFT -2
#define RIGHT 2


int n , m ;
int used[ 27 ][ 27 ] ; 
int hr[ 27 ] ; 
int vr[ 27 ] ;


void input ( ) ;
void solve ( ) ;


bool bfs ( int x , int y ) {
	int i , j ;
	for ( i = 0 ; i <= n ; i ++ ) {
		for ( j = 0 ; j <= m ; j ++ ) {
			used[ i ][ j ] = 0 ; 
		}
	}
	queue < pair < int , int > > q ;
	while ( q.empty ( ) == false ) q.pop ( ) ;
	pair < int , int > p ;
	pair < int , int > e ;
	p.first = x ;
	p.second = y ;
	used[ x ][ y ] = 1 ; 
	q.push ( p ) ; 
	while ( q.empty ( ) == false ) {
		p = q.front ( ) ;
		q.pop ( ) ;
        //	printf ( "extracting from queue %d %d\n" , p.first , p.second ) ;
		if ( hr[ p.first ] == LEFT ) {

			for ( i = p.second - 1 ; i >= 0 ; i -- ) {
				if ( used[ p.first ][ i ] == 0 ) {
					e.first = p.first ;
					e.second = i ;
					q.push ( e ) ;
					used[ p.first ][ i ] = 1 ;
				}
			}
		}
		else {
			for ( i = p.second + 1 ; i < m ; i ++ ) {
				if ( used[ p.first ][ i ] == 0 ) {
					e.first = p.first ;
					e.second = i ;
					q.push ( e ) ;
					used[ p.first ][ i ] = 1 ; 
				}
			}

		}
		if ( vr[ p.second ] == UP ) {
			for ( i = p.first - 1 ; i >= 0 ; i -- ) {
				if ( used[ i ][ p.second ] == 0 ) {
					e.first = i ;
					e.second = p.second ;
					q.push ( e ) ;
					used[ i ][ p.second ] = 1 ; 
				}
			}
		}
		else {
			for ( i = p.first + 1 ; i < n ; i ++ ) {
				if ( used[ i ][ p.second ] == 0 ) {
					e.first = i ;
					e.second = p.second ;
					q.push ( e ) ;
					used[ i ][ p.second ] = 1 ; 
				}
			}
		}

	}
    //	printf ( "--%d %d\n" , x , y ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( used[ i ][ j ] == 0 )  return false ;
		}
	}
	return true ;
}

int main ( )  {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> n >> m ;
	int i ;
	string b ;
	cin >> b ;
	for ( i = 0 ; i < n ; i ++ ) {
		//hr[ i ] = 
		if ( b[ i ] == '<' ) hr[ i ] = LEFT ;
		else hr[ i ] = RIGHT ; 
	}
	cin >> b ;
	for ( i = 0 ; i < m ; i ++ ) {
		if ( b[ i ] == '^' ) vr[ i ] = UP ;
		else vr[ i ] = DOWN ;
	}
}

void solve ( )  {
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( bfs ( i , j ) == false ) break ;
		}
		if ( j != m ) break ;
	}
	if ( i == n ) cout << "YES\n" ;
	else cout << "NO\n" ;
}