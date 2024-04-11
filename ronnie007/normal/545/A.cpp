#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ][ MAXN ] ;

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
	scanf ( "%d" , &n ) ;
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}

void solve ( )  {
	vector < int > v ;
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			if ( a[ i ][ j ] == 1 || a[ i ][ j ] == 3 ) { break ; }
        }
		if ( j > n ) { v.push_back ( i ) ; }
    }
	int sz = v.size ( ) ;
	printf ( "%d\n" , sz ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		printf ( "%d" , v[ i ] ) ;
		if ( i == sz - 1 ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
    }
}