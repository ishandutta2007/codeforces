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
set < string > s ;

void input ( ) {
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( ) {
	s.insert ( a ) ;
	string b ;
	int br = n ;
	while ( br != 0 ) {
		br -- ;
		int i ;
		b.clear ( ) ;
		b += a[ n - 1 ] ;
		for ( i = 0 ; i < n - 1 ; i ++ ) { b += a[ i ] ; }
		s.insert ( b ) ;
		a = b ;
	}
	cout << s.size ( ) << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}