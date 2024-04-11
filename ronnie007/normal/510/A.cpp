#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;


int n , m ;

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( ( i % 2 ) == 1 ) { 
			for ( j = 1 ; j <= m ; j ++ ) {
				printf ( "#" ) ;
			}
			printf ( "\n" ) ;
		}
		else {
			if ( ( i % 4 ) == 0 ) {
				printf ( "#" ) ;
				for ( j = 2 ; j <= m ; j ++ ) {
					printf ( "." ) ;
				}
				printf ( "\n" ) ;
			}
			else {
				for ( j = 1 ; j < m ; j ++ ) {
					printf ( "." ) ;
				}
				printf ( "#" ) ;				
				printf ( "\n" ) ;			
			}
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