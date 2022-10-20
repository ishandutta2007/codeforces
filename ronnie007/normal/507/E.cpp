#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

int n , m ;

map < pair < int , int > , int > ZX ;

vector < pair < int , int > > v[ 100007 ] ;
int st[ 100007 ] ;
int en[ 100007 ] ;
int type[ 100007 ] ;
int d[ 100007 ] ;
int b[ 100007 ] ;
int prev[ 100007 ] ;
int used[ 100007 ] ;

priority_queue < pair < pair < int , int > , int > > q ;
// pair < pair < dist , br > , vertex > 

void bfs ( ) {
	int i ;
	for ( i = 0 ; i <= n ; i ++ ) {
		d[ i ] = n + 27 ;
		b[ i ] = 0 ;
		prev[ i ] = -1 ;
    }
	d[ 1 ] = 0 ;
	b[ 1 ] = 0 ;
	q.push ( make_pair ( make_pair ( 0 , 0 ) , 1 ) ) ;
	pair < pair < int , int > , int > p , e ; 
	while ( q.empty ( ) == false ) {
		p = q.top ( ) ;
		q.pop ( ) ;

		p.first.first = -p.first.first ;
		p.first.second = -p.first.second ;
		if ( d[ p.second ] != p.first.first || b[ p.second ] != p.first.second ) { continue ; } 
		//printf ( "dist = %d b = %d vertex = %d prev = %d\n" , p.first.first , p.first.second , p.second , prev[ p.second ] ) ;
		int sz = v[ p.second ].size ( ) ;
		for ( i = 0 ; i < sz ; i ++ ) {
			if ( d[ v[ p.second ][ i ].first ] < p.first.first + 1  || ( d[ v[ p.second ][ i ].first ] == p.first.first + 1 && b[ v[ p.second ][ i ].first ] >=  ( p.first.second + ( v[ p.second ][ i ].second ) ) ) ) { continue ; } 
			e.first.first = - ( p.first.first + 1 ) ;
			d[ v[ p.second ][ i ].first ] = -e.first.first ;
			e.first.second = - ( p.first.second + ( v[ p.second ][ i ].second ) ) ;
			b[ v[ p.second ][ i ].first ] =	-e.first.second ;
			e.second = v[ p.second ][ i ].first ;
			q.push ( e ) ;
			prev[ e.second ] = p.second ;
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


void input ( )  {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d%d%d" , &st[ i ] , &en[ i ] , &type[ i ] ) ;
		v[ st[ i ] ].push_back ( make_pair ( en[ i ] , type[ i ] ) ) ;
		v[ en[ i ] ].push_back ( make_pair ( st[ i ] , type[ i ] ) ) ;
    }
}

void solve ( )  {
	bfs ( ) ;
	//f ( ) ;
	//printf ( "%d\n" , prev[ n ] ) ;
	int x = n ;
	while ( prev[ x ] != -1 ) {
		ZX[ make_pair ( x , prev[ x ] ) ] = 1 ; 
		x = prev[ x ] ;
    }
	//used[ 1 ] = 1 ;
	int i ;
	int ans = 0 ;
	for ( i = 0 ; i < m ; i ++ ) {
		if ( ZX[ make_pair ( st[ i ] , en[ i ] ) ] == 1 || ZX[ make_pair ( en[ i ] , st[ i ] ) ] == 1 ) { used[ i ] = 1 ;  }
		if ( used[ i ] == 0 && type[ i ] == 1 ) {
			ans ++ ;
		}
		if ( used[ i ] == 1 && type[ i ] == 0 ) {
			ans ++ ;
        }
    }
	printf ( "%d\n" , ans ) ;
	for ( i = 0 ; i < m ; i ++ ) {
		if ( used[ i ] == 0 && type[ i ] == 1 ) {
			printf ( "%d %d 0\n" , st[ i ] , en[ i ] ) ;
		}
		if ( used[ i ] == 1 && type[ i ] == 0 ) {
			printf ( "%d %d 1\n" , st[ i ] , en[ i ] ) ;			
        }
    }
}