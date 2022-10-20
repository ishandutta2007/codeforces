#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


int n ; 


void input ( ) ;
void solve ( ) ;


int main ( ) {
    //	ios::sync_with_stdio ( false ) ;
    //	cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d" , &n ) ;
}

void solve ( )  {
	if ( n < 4 ) { printf ( "NO\n" ) ; return ; }
	int i ;
	if ( n % 2 == 0 ) {
		printf ( "YES\n" ) ;
		printf ( "1 * 2 = 2\n" ) ;
		printf ( "2 * 3 = 6\n" ) ;
		printf ( "6 * 4 = 24\n" ) ;
		for ( i = 6 ; i <= n ; i += 2 ) {
			printf ( "%d - %d = 1\n" , i , i - 1 ) ;
			printf ( "24 * 1 = 24\n" ) ;
		}
	}
	else {
		printf ( "YES\n" ) ;
		printf ( "5 * 3 = 15\n" ) ;
		printf ( "2 * 4 = 8\n" ) ;
		printf ( "15 + 8 = 23\n" ) ;
		printf ( "23 + 1 = 24\n" ) ;
		for ( i = 7 ; i <= n ; i += 2 ) {
			printf ( "%d - %d = 1\n" , i , i - 1 ) ;
			printf ( "24 * 1 = 24\n" ) ;
		}
	}
}