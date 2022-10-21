#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std ;

int n ;
string a ;

int br1[ 37 ] ;
int br2[ 37 ] ;

void input ( ) {
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( ) {
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] >= 'a' && a[ i ] <= 'z' ) {
			br1[ ( a[ i ] - 'a' ) ] ++ ;
		}
		else {
			br2[ ( a[ i ] - 'A' ) ] ++ ;
		}
	}
	int mn = n ;
	int val = br2[ ( 'B' - 'A' ) ] ;
	if ( mn > val ) { mn = val ; }
	
	val = br1[ ( 'u' - 'a' ) ] / 2 ;
	if ( mn > val ) { mn = val ; }
	
	val = br1[ ( 'a' - 'a' ) ] / 2 ;
	if ( mn > val ) { mn = val ; }

	val = br1[ ( 'l' - 'a' ) ] ;
	if ( mn > val ) { mn = val ; }

	val = br1[ ( 'b' - 'a' ) ] ;
	if ( mn > val ) { mn = val ; }

	val = br1[ ( 's' - 'a' ) ] ;
	if ( mn > val ) { mn = val ; }
	
	val = br1[ ( 's' - 'a' ) ] ;
	if ( mn > val ) { mn = val ; }

	val = br1[ ( 'r' - 'a' ) ] ;
	if ( mn > val ) { mn = val ; }
	cout << mn << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}