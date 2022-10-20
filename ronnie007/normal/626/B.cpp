#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std ;

#define MAXN 203

int n ;
string a ;

int used[ MAXN ][ MAXN ][ MAXN ] ;

void dfs ( int x , int y , int z ) {
	if ( used[ x ][ y ][ z ] == 1 ) { return ; }
	used[ x ][ y ][ z ] = 1 ;
	if ( ( x + y + z ) == 1 ) { return ; }
	if ( x >= 2 ) {
		if ( used[ x - 1 ][ y ][ z ] == 0 ) { dfs ( x - 1 , y , z ) ; }
	}
	if ( y >= 2 ) {
		if ( used[ x ][ y - 1 ][ z ] == 0 ) { dfs ( x , y - 1 , z ) ; }
	}
	if ( z >= 2 ) {
		if ( used[ x ][ y ][ z - 1 ] == 0 ) { dfs ( x , y , z - 1 ) ; }
	}

	if ( x != 0 && y != 0 ) {
		if ( used[ x - 1 ][ y - 1 ][ z + 1 ] == 0 ) { dfs ( x - 1 , y - 1 , z + 1 ) ; }
	}
	if ( x != 0 && z != 0 ) {
		if ( used[ x - 1 ][ y + 1 ][ z - 1 ] == 0 ) { dfs ( x - 1 , y + 1 , z - 1 ) ; }
	}
	if ( y != 0 && z != 0 ) {
		if ( used[ x + 1 ][ y - 1 ][ z - 1 ] == 0 ) { dfs ( x + 1 , y - 1 , z - 1 ) ; }
	}
}

void input ( ) {
	cin >> n ;
	cin >> a ;
}

void solve ( ) {
	int i ;
	int x , y , z ;
	x = y = z = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == 'B' ) { x ++ ; }
		if ( a[ i ] == 'G' ) { y ++ ; }
		if ( a[ i ] == 'R' ) { z ++ ; }
	}
	dfs ( x , y , z ) ;
	if ( used[ 1 ][ 0 ][ 0 ] == 1 ) { cout << "B" ; }
	if ( used[ 0 ][ 1 ][ 0 ] == 1 ) { cout << "G" ; }
	if ( used[ 0 ][ 0 ][ 1 ] == 1 ) { cout << "R" ; }
	cout << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}