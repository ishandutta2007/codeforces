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
#include<stack>
using namespace std ;

#define MAXN 107 

int n , k ;
string a[ 3 ] ;
bool train[ 3 ][ MAXN ][ MAXN ] ;
bool used[ 3 ][ MAXN ] ;

int dx[ 3 ] = { -1 , 0 , 1 } ;

void input ( ) ;
void solve ( ) ;

void clear ( ) {
	int i , j , t ;
	for ( i = 0 ; i < 3 ; i ++ ) {
		for ( j = 0 ; j <= 103 ; j ++ ) {
			used[ i ][ j ] = false ;
			for ( t = 0 ; t <= 103 ; t ++ ) {
				train[ i ][ j ][ t ] = false ;
			}
		}
	}
}

void bfs ( ) {
	int i ;
	for ( i = 0 ; i < 3 ; i ++ ) {
		if ( a[ i ][ 0 ] == 's' ) { break ; }
	}
	queue < pair < int , int > > q ;
	q.push ( make_pair ( i , 0 ) ) ;
	used[ i ][ 0 ] = true ;
	pair < int , int > p , e ; 
	while ( q.empty ( ) == false ) {
		p = q.front ( ) ;
		q.pop ( ) ;
		int tm = p.second ;
		for ( i = 0 ; i < 3 ; i ++ ) {
			e.first = p.first + dx[ i ] ;
			e.second = p.second + 1 ;
			if ( e.first < 0 || e.first >= 3 ) { continue ; }
			if ( e.second >= n ) { continue ; }
			if ( train[ e.first ][ e.second ][ tm ] == true || train[ e.first ][ e.second + 1 ][ tm ] == true || train[ e.first ][ e.second + 2 ][ tm ] == true ) { continue ; }
			if ( train[ p.first ][ e.second ][ tm ] == true ) { continue ; }
			if ( used[ e.first ][ e.second ] == true ) { continue ; }
			used[ e.first ][ e.second ] = true ;
			q.push ( e ) ;
		}
	}
}

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	int t ;
	cin >> t ;
	while ( t != 0 ) {
		t -- ;
		input ( ) ;
		solve ( ) ;
		clear ( ) ;
	}
	return 0 ;
}


void input ( )  {
	cin >> n >> k ;
	int i ;
	for ( i = 0 ; i < 3 ; i ++ ) {
		cin >> a[ i ] ;
	}
}

void solve ( ) {
	int i , j , t ;
	for ( i = 0 ; i < 3 ; i ++ ) {
		for ( j = 0 ; j < n ; j ++ ) {
			if ( a[ i ][ j ] >= 'A' && a[ i ][ j ] <= 'Z' ) { train[ i ][ j ][ 0 ] = true ; }
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 0 ; j < 3 ; j ++ ) {
			for ( t = 0 ; t + 2 < n ; t ++ ) {
				if ( train[ j ][ t + 2 ][ i - 1 ] == true ) { train[ j ][ t ][ i ] = true ; }
			}
		}
	}
	bfs ( ) ;
	for ( i = 0 ; i < 3 ; i ++ ) {
		if ( used[ i ][ n - 1 ] == true ) { printf ( "YES\n" ) ; return ; }
	}
	printf ( "NO\n" ) ;
}