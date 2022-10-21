#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int n ;

void input ( ) {
	cin >> n ;
}

void solve ( ) {
	int ans = 0 ;
	while ( n != 0 ) {
		n -- ;
		string s ;
		cin >> s ;
		if ( s == "Tetrahedron" ) { ans += 4 ; }
		else if ( s == "Cube" ) { ans += 6 ; }
		else if ( s == "Octahedron" ) { ans += 8 ; }
		else if ( s == "Dodecahedron" ) { ans += 12 ; }
		else { ans += 20 ; }
    }
	printf ( "%d\n" , ans ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}