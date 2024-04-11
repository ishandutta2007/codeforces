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
int br ;

void input ( ) {
	cin >> n ;
	cin >> a ;
	string b ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> b ;
		if ( a[ 0 ] == b[ 0 ] && a[ 1 ] == b[ 1 ] && a[ 2 ] == b[ 2 ] ) { br ++ ; }
		if ( a[ 0 ] == b[ 5 ] && a[ 1 ] == b[ 6 ] && a[ 2 ] == b[ 7 ] ) { br ++ ; }		
	}
}

void solve ( ) {
	if ( ( br % 2 ) == 0 ) { printf ( "home\n" ) ; }
	else { printf ( "contest\n" ) ; }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}