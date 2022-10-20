#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std ;

#define MAXN 57

int n ;
string a[ MAXN ] ;
int ret[ 2 * MAXN ][ 2 * MAXN ] ;

vector < pair < int , int > > v ;
void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> n ;
	int i ;
	int j ; 
	for ( i = 0 ; i < n ; i ++ ) {
		cin >> a[ i ] ;
		for ( j = 0 ; j < n ; j ++ ) {
			if ( a[ i ][ j ] == 'o' ) { v.push_back ( make_pair ( i , j ) ) ; }
        }
    }
}
 
void solve ( )  {
	int dx , dy ;
	int i , j , t ;
	int sz = v.size ( ) ;
	for ( dx = -n ; dx <= n ; dx ++ ) {
		for ( dy = -n ; dy <= n ; dy ++ ) {
			for ( i = 0 ; i < sz ; i ++ ) {
				int nx = v[ i ].first + dx ;
				int ny = v[ i ].second + dy ; 
				if ( nx < 0 || nx >= n ) { continue ; }
				if ( ny < 0 || ny >= n ) { continue ; }
				if ( a[ nx ][ ny ] == '.' ) { break ; }
            }
			if ( i == sz ) { ret[ dx + n ][ dy + n ] = 1 ; }
        }
    }
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < n ; j ++ ) {
			if ( a[ i ][ j ] != 'x' ) { continue ; }
			for ( t = 0 ; t < sz ; t ++ ) {
				dx = - ( v[ t ].first - i ) ;
				dy = - ( v[ t ].second - j ) ;
				if ( ret[ dx + n ][ dy + n ] == 1 ) { break ; }
            }
			if ( t == sz ) { printf ( "NO\n" ) ; return ; }
        }
    }
	printf ( "YES\n" ) ;
	for ( i = 1 ; i <= 2 * n - 1 ; i ++ ) {
		for ( j = 1 ; j <= 2 * n - 1 ; j ++ ) {
			if ( i == n && j == n ) { printf ( "o" ) ; }
			else if ( ret[ i ][ j ] == 1 ) { printf ( "x" ) ; }
			else { printf ( "." ) ; }
        }
		printf ( "\n" ) ;
    }
}