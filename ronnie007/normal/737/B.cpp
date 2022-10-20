#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

int n , a , b , k ;
string s ;

vector < int > v ;
string c ;

int f (  ) {
	int len = 0 ;
	int tot = 0 ;
	int i ;
	v.clear ( ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( s[ i ] == '0' ) { len ++ ; }
		else { len = 0 ; }
		if ( len == b ) {
			v.push_back ( i + 1 ) ;
			tot ++ ;
			len = 0 ;
		}
	}
	v.resize ( ( v.size ( ) - a + 1 ) ) ;
	return v.size ( ) ;
}

void input ( ) {
	cin >> n >> a >> b >> k ;
	cin >> s ;
}

void solve ( ) {
	int l = f ( ) ;
	int i ;
	printf ( "%d\n" , l ) ;
	for ( i = 0 ; i < l ; i ++ ) {
		printf ( "%d" , v[ i ] ) ;
		if ( i == ( l - 1 ) ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}