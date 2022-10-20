#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

#define MAXN 100007

int n , m , k ;
bool a[ MAXN ] ;

int s , t ;

int pr[ MAXN ] ;
pair < int , int > d[ MAXN ] ;

vector < int > v[ MAXN ] ;

int mark[ MAXN ] ;

int find ( int x ) {
	if ( pr[ x ] == -1 ) { return x ; }
	int y = find ( pr[ x ] ) ;
	pr[ x ] = y ;
	return y ;
}

void UNITE ( int x , int y ) {
	int k1 = find ( x ) ;
	int k2 = find ( y ) ;
	if ( k1 != k2 ) {
		pr[ k1 ] = k2 ;
	}
}

void bfs ( int x ) {
	queue < pair < int , int > > q ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( a[ i ] == true ) {
			q.push ( make_pair ( i , i ) ) ;
			d[ i ] = make_pair ( 0 , i ) ;
		}
	}
	pair < int , int > u , e ;
	while ( q.empty ( ) == false ) {
		u = q.front ( ) ;
		q.pop ( ) ;
		int sz = v[ u.first ].size ( ) ;
		for ( i = 0 ; i < sz ; i ++ ) {
			int h = v[ u.first ][ i ] ;
			if ( d[ h ].first > n ) {
				d[ h ].first = d[ u.first ].first + 1 ;
				d[ h ].second = u.second ;
				q.push ( make_pair ( h , u.second ) ) ;
			}
			else {
				if ( d[ h ].second != u.second ) {
					if ( d[ h ].first + d[ u.first ].first + 1 <= x ) {
						UNITE ( d[ h ].second , u.second ) ;
					}
				}
			}
		}
	}
}

void precalc ( ) {
	queue < int > q ;
	q.push ( t ) ;
	int i , sz ; 
	for ( i = 1 ; i <= n ; i ++ ) {
		mark[ i ] = n + 27 ;
	}
	mark[ t ] = 1 ;
	while ( q.empty ( ) == false ) {
		int vertex = q.front ( ) ;
		q.pop ( ) ;
		sz = v[ vertex ].size ( ) ;
		for ( i = 0 ; i < sz ; i ++ ) {
			if ( mark[ v[ vertex ][ i ] ] > n ) {
				mark[ v[ vertex ][ i ] ] = mark[ vertex ] + 1 ;
				q.push ( v[ vertex ][ i ] ) ;
			}
		}
	}
}

bool f ( int x ) {
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		pr[ i ] = -1 ;
		d[ i ] = make_pair ( n + 27 , 0 ) ;
	}
	bfs ( x ) ;
	int k1 = find ( s ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int k2 = find ( i ) ;
		if ( k1 == k2 && mark[ i ] <= ( x + 1 ) ) { return true ; }
	}
	return false ;
}

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &k ) ;
	int i ;
	int x , y ;
	for ( i = 1 ; i <= k ; i ++ ) {
		scanf ( "%d" , &x ) ;
		a[ x ] = true ;
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
	scanf ( "%d%d" , &s , &t ) ;
}

void solve ( ) {
	mark[ t ] = 1 ;
	precalc ( ) ;
	int l , r , mid ;
	l = 1 ;
	r = n ;
	while ( r - l > 3 ) {
		int mid = ( l + r ) / 2 ;
		if ( f ( mid ) == false ) { l = mid ; }
		else { r = mid ; }
	}
	while ( f ( l ) == false ) { l ++ ; }
	if ( l > n ) { printf ( "-1\n" ) ; return ; }
	printf ( "%d\n" , l ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}