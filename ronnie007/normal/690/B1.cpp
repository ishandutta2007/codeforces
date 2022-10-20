#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

#define MAXN 57

int n ;
string a[ MAXN ] ;

void input ( ) {
	cin >> n ;
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ] ;
		a[ i ] = '#' + a[ i ] ;
	}
}

void solve ( ) {
	int i , j , t , z , x , y ;
	int br = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			if ( a[ i ][ j ] != '1' ) { continue ; }
			for ( t = i + 1 ; t <= n ; t ++ ) {
				if ( a[ t ][ j ] != '2' ) { break ; }
			}
			if ( t == ( n + 1 ) ) { continue ; }
			for ( z = j + 1 ; z <= n ; z ++ ) {
				if ( a[ i ][ z ] != '2' ) { break ; }
			}
			if ( z == ( n + 1 ) ) { continue ; }
			if ( a[ t ][ j ] != '1' ) { continue ; }
			if ( a[ i ][ z ] != '1' ) { continue ; }
			if ( a[ t ][ z ] != '1' ) { continue ; }
			if ( t == i + 1 && z == j + 1 ) { continue ; }
			for ( x = i + 1 ; x < t ; x ++ ) {
				if ( a[ x ][ z ] != '2' ) { break ; }
			}
			if ( x != t ) { continue ; }
			for ( y = j + 1 ; y < z ; y ++ ) {
                if ( a[ t ][ y ] != '2' ) { break ; }
			}
			if ( y != z ) { continue ; }
			for ( x = i + 1 ; x < t ; x ++ ) {
				for ( y = j + 1 ; y < z ; y ++ ) {
					if ( a[ x ][ y ] != '4' ) { break ; }
				}
				if ( y != z ) { break ; }
			}
			if ( x == t ) { br ++ ; }
			for ( x = 1 ; x <= n ; x ++ ) {
				for ( y = 1 ; y <= n ; y ++ ) {
					if ( x >= i && x <= t && y >= j && y <= z ) { continue ; }
					if ( a[ x ][ y ] != '0' ) { printf ( "No\n" ) ; return ; }
				}
			}
		}
	}
	if ( br != 0 ) { printf ( "Yes\n" ) ; }
	else { printf ( "No\n" ) ; }
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}