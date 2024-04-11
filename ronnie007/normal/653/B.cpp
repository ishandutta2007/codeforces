#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std ;

int n , k ;
string a[ 57 ] ;
string b[ 57 ] ;

string h ; 
string p ;
int ans = 0 ;

void check ( ) {
	int i , j ;
	p = h ;
	for ( i = 0 ; i < n - 1 ; i ++ ) {
		for ( j = 0 ; j < k ; j ++ ) {
			if ( a[ j ][ 0 ] == p[ i ] && a[ j ][ 1 ] == p[ i + 1 ] ) { break ; }
		}
		if ( j == k ) { return ; }
		p[ i + 1 ] = b[ j ][ 0 ] ;
	}
	if ( p[ n - 1 ] != 'a' ) { return ; }
	ans ++ ;
}

void f ( int pos ) {
	if ( pos == n ) {
		check ( ) ;
		return ;
	}
	int i ;
	for ( i = 0 ; i < 6 ; i ++ ) {
		h[ pos ] = char ( ( i + 'a' ) ) ;
		f ( pos + 1 ) ;
	}
}

void input ( ) {
	cin >> n >> k ;
	int i ;
	for ( i = 0 ; i < k ; i ++ ) {
		cin >> a[ i ] >> b[ i ] ;
	}
}

void solve ( ) {
	h.resize ( n ) ;
	f ( 0 ) ;
	cout << ans << "\n" ; 
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}