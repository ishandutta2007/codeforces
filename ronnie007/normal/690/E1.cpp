#include<iostream>
#include<stdio.h>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std ;

#define MAXN 607

int n , m ;
int a[ MAXN ][ MAXN ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			scanf ( "%d" , &a[ i ][ j ] ) ;
		}
	}
}

void solve ( ) {
	long long br1 = 0 ;
	long long br2 = 0 ;
	int i , j ;
	for ( j = 0 ; j < m ; j ++ ) {
		if ( abs ( ( a[ ( n / 2 ) ][ j ] - a[ ( n / 2 ) - 1 ][ j ] ) ) > 125 ) { printf ( "YES\n" ) ; return ; }
		//br1 += a[ 0 ][ j ] ;
		//br2 += a[ ( n / 2 ) ][ j ] ;
	}
	printf ( "NO\n" ) ; return ;
	//printf ( "printf ( \"" ) ;
	if ( br1 >= br2 ) { printf ( "NO\n" ) ; }
	else { printf ( "YES\n" ) ; }
	//printf ( "\\n\" ) ;\n" ) ;
}

int main ( ) {
	int q ;
	scanf ( "%d" , &q ) ;
	while ( q != 0 ) {
		q -- ;
		input ( ) ;
		solve ( ) ;
	}
	return 0 ;
}