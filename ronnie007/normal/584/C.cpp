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

int n , t ;
string a ;
string b ;

int f ( int pos ) {
	int i ;
	char u ;
	for ( i = 0 ; i < 26 ; i ++ ) {
		u = char ( i + 'a' ) ;
		if ( u != a[ pos ] && u != b[ pos ] ) { return i ; }
	}
	return 26 ;
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
	cin >> n >> t ;
	t = n - t ;
	cin >> a ;
	cin >> b ;
}

void solve ( ) {
	int i ;
	int br = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == b[ i ] ) { br ++ ; }
	}
	int razl = ( n - br ) ;
	if ( br > t ) { br = t ; }
	t -= br ;
	if ( razl < 2 * t ) { printf ( "-1\n" ) ; return ; }
	int h1 = t ;
	int h2 = t ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == b[ i ] ) {
			if ( br > 0 ) { br -- ; cout << a[ i ] ; }
			else { cout << char ( f ( i ) + 'a' ) ; }
		}
		else {
			if ( h1 > 0 ) { h1 -- ; cout << a[ i ] ; }
			else if ( h2 > 0 ) { h2 -- ; cout << b[ i ] ; }
			else { cout << char ( f ( i ) + 'a' ) ; }
		}
	}
	cout << "\n" ;
}