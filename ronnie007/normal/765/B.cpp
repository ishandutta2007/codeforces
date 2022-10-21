#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
using namespace std ;

int n ;
string a ;

void input ( ) {
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( ) {
	int i ;
	int u = -1 ;
	for ( i = 0 ; i < n ; i ++ ) {
		int x = ( a[ i ] - 'a' ) ;
		if ( u < ( x - 1 ) ) { printf ( "NO\n" ) ; return ; }
		if ( u == ( x - 1 ) ) { u ++ ; }
	}
	printf ( "YES\n" ) ; 
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}