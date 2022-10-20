#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

#define MAXN 1007

int n ;
string a[ MAXN ] ;

void input ( ) {
	cin >> n ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ] ; 
	}
}

void solve ( ) {
	int i , j , t ;
	int ans = 7 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = i + 1 ; j <= n ; j ++ ) {
			int p1 = 0 ;
			int p2 = 0 ;
			for ( t = 0 ; t < 6 ; t ++ ) {
				if ( a[ i ][ t ] == a[ j ][ t ] ) { continue ; }
				if ( p1 == p2 ) { p1 ++ ; }
				else { p2 ++ ; }
			}
			if ( ans > p1 ) { ans = p1 ; }
		}
	}
	printf ( "%d\n" , ans - 1 ) ;
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}