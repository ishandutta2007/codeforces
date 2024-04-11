#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n ;
string a ;
int used[ 27 ] ;


void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	cin >> n ;
	cin >> a ;
}

void solve ( ) {
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] >= 'A' && a[ i ] <= 'Z' ) { a[ i ] = char ( 'a' + ( a[ i ] - 'A' ) ) ; }
		used[ a[ i ] - 'a' ] = 1 ;
	}
	for ( i = 0 ; i < 26 ; i ++ ) {
		if ( used[ i ] == 0 ) { printf ( "NO\n" ) ; return ; }
	}
	printf ( "YES\n" ) ;
}