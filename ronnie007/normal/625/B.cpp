#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
using namespace std ;

#define MAXN 100007
#define MAXK 37


int n , m ;
string a , b ;

void input ( ) {
	cin >> a >> b ;
	n = a.size ( ) ;
	m = b.size ( ) ;
}

void solve ( ) {
	int i , j ;
	int ans = 0 ;
	for ( i = 0 ; i + j <= n ; i ++ ) {
		j = 0 ;
		for ( j = 0 ; j < m ; j ++ ) {
			if ( a[ i + j ] != b[ j ] ) { break ; }
		}
		if ( j == m ) { a[ i + m - 1 ] = '#' ; ans ++ ; }
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