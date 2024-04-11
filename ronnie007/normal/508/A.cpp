#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n , m , k ;
int a[ 1007 ][ 1007 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	//input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	
}

void solve ( )  {
	scanf ( "%d%d%d" , &n , &m , &k ) ;
	int i ;
	int ans = 0 ;
	int x , y ; 
	for ( i = 1 ; i <= k ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		a[ x ][ y ] = 1 ;
		if ( a[ x - 1 ][ y - 1 ] == 1 && a[ x ][ y - 1 ] == 1 && a[ x - 1 ][ y ] == 1 ) { 
			if ( ans == 0 ) { ans = i ; } 
		}
		if ( a[ x + 1 ][ y + 1 ] == 1 && a[ x ][ y + 1 ] == 1 && a[ x + 1 ][ y ] == 1 ) {
			if ( ans == 0 ) { ans = i ; } 
        }
		if ( a[ x - 1 ][ y + 1 ] == 1 && a[ x ][ y + 1 ] == 1 && a[ x - 1 ][ y ] == 1 ) {
			if ( ans == 0 ) { ans = i ; } 
        }
		if ( a[ x + 1 ][ y - 1 ] == 1 && a[ x ][ y - 1 ] == 1 && a[ x + 1 ][ y ] == 1 ) {
			if ( ans == 0 ) { ans = i ; } 
        }
    }
	printf ( "%d\n" , ans ) ;
}