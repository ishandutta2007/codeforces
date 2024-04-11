#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
#include<cstdlib>
using namespace std ;

#define MAXN 100007

int n ;

int br[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
}

void solve ( ) {
	int i , j ;
	int u = 0 ;
	for ( i = 2 ; i <= ( n + 1 ) ; i ++ ) {
		if ( br[ i ] != 0 ) { continue ; }
		u ++ ;
		for ( j = 2 * i ; j <= ( n + 1 ) ; j += i ) {
			br[ j ] ++ ;
		}
	}
	if ( u == n ) {
		printf ( "1\n" ) ;
		for ( i = 1 ; i <= n ; i ++ ) {
			printf ( "1" ) ;
			if ( i == n ) { printf ( "\n" ) ; }
			else { printf ( " " ) ; }
		}
	}
	else {
		printf ( "2\n" ) ;
		for ( i = 2 ; i <= ( n + 1 ) ; i ++ ) {
			if ( br[ i ] == 0 ) { printf ( "1" ) ; }
			else { printf ( "2" ) ; }
			if ( i == ( n + 1 ) ) { printf ( "\n" ) ; }
			else { printf ( " " ) ; }			
		}
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}