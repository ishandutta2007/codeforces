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
vector < int > v[ 3 ] ;

void input ( ) ;
void solve ( ) ;



int main ( ) {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d" , &n ) ;
	int i ;
	int x ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &x ) ;
		x -- ;
		v[ x ].push_back ( i + 1 ) ;
    }
}

void solve ( )  {
	int i , j ;
	int p = v[ 0 ].size ( ) ;
	if ( p > v[ 1 ].size ( ) ) p = v[ 1 ].size ( ) ;
	if ( p > v[ 2 ].size ( ) ) p = v[ 2 ].size ( ) ;
	printf ( "%d\n" , p ) ;
	for ( i = 0 ; i < p ; i ++ ) {
		for ( j = 0 ; j < 3 ; j ++  ) {
			printf ( "%d" , v[ j ][ i ] ) ;
			if ( j == 2 ) printf ( "\n" ) ;
			else printf ( " " ) ;
        }
    }
}