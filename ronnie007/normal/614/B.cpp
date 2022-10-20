#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std ;

#define MAXN 100007

int n ;
vector < int > v ;

vector < int > u ;
string str[ MAXN ] ;

void input ( ) {
	cin >> n ;
	int i , j ;
	string a ;
	int sz ;
	v.clear ( ) ;
	v.push_back ( 1 ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> str[ i ] ;
		a = str[ i ] ;
		sz = a.size ( ) ;
		int br1 = 0 ;
		int br2 = 0 ;
		for ( j = 0 ; j < sz ; j ++ ) {
			if ( a[ j ] == '0' ) { br1 ++ ; }
			else if ( a[ j ] == '1' ) { br2 ++ ; }
			else { break ; }
		}
		if ( j == sz && br2 == 1 ) {
			// spaam
		}
		else {
			for ( j = 0 ; j < sz ; j ++ ) {
				u.push_back ( ( a[ j ] - '0' ) ) ;
			}
			v = u ;
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		a = str[ i ] ;
		if ( a == "0" ) { v.clear ( ) ; v.push_back ( 0 ) ; continue ; }
		if ( v.size ( ) == 1 && v[ 0 ] == 0 ) { continue ; }
		sz = a.size ( ) ;
		int br1 = 0 ;
		int br2 = 0 ;
		for ( j = 0 ; j < sz ; j ++ ) {
			if ( a[ j ] == '0' ) { br1 ++ ; }
			else if ( a[ j ] == '1' ) { br2 ++ ; }
			else { break ; }
		}
		if ( j == sz && br2 == 1 ) {
			while ( br1 != 0 ) { v.push_back ( 0 ) ; br1 -- ; }
		}
	}
	sz = v.size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		cout << v[ i ] ;
	}
	cout << "\n" ;
}

void solve ( ) {
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	//solve ( ) ;
	return 0 ;
}