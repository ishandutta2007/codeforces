#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n , k ;
vector < int > v ; 

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &k ) ;
}

void solve ( )  {
	int i ;
	int x = 1 ;
	int e = 0 ;
	v.push_back ( 1 ) ;
	for ( i = k ; i >= 1 ; i -- ) {
		if ( e == 0 ) x += i ;
		else x -= i ; 
		v.push_back ( x ) ;
		e ^= 1 ; 
    }
	for ( i = k + 2 ; i <= n ; i ++ ) {
		v.push_back ( i ) ;
    }
	
	for ( i = 0 ; i < n ; i ++ ) {
		printf ( "%d" , v[ i ] ) ;
		if ( i == n - 1 ) printf ( "\n" ) ;
		else printf ( " " ) ;
    }
}