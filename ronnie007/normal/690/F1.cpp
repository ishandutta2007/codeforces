#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std ;

#define MAXN 10007

int n ;
vector < int > v[ MAXN ] ;
int len[ MAXN ] ;
long long ans = 0 ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	int x , y ; 
	for ( i = 1 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		len[ i ] = v[ i ].size ( ) ;
	}
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 0 ; j < len[ i ] ; j ++ ) {
			ans += ( len[ v[ i ][ j ] ] - 1 ) ;
		}
	}
	ans /= 2 ;
	cout << ans << "\n" ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}