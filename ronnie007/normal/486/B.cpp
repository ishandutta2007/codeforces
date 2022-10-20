#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;


int n , m ;
int a[ 107 ][ 107 ] ; 
int ans[ 107 ][ 107 ] ;
bool r[ 107 ] ;
bool c[ 107 ] ;


void input ( ) ;
void solve ( ) ;


int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &m ) ;
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) r[ i ] = true ;
	for ( i = 0 ; i < m ; i ++ ) c[ i ] = true ;

	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			scanf ( "%d" , &a[ i ][ j ] ) ;
			if ( a[ i ][ j ] == 0 ) { r[ i ] = false ; c[ j ] = false ; }
        }
    }
}

void solve ( )  {
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( a[ i ][ j ] == 1 ) {
				if ( r[ i ] == false && c[ j ] == false ) { printf ( "NO\n" ) ; return ; }
            }
			if ( r[ i ] == true && c[ j ] == true ) ans[ i ][ j ] = 1 ; 
        }
    }
	for ( i = 0 ; i < n ; i ++ ) r[ i ] = false ;
	for ( i = 0 ; i < m ; i ++ ) c[ i ] = false ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( ans[ i ][ j ] == 1 ) { r[ i ] = true ; c[ j ] = true ; } 
        }
    }	
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			if ( a[ i ][ j ] == 1 ) {
				if ( r[ i ] == 0 && c[ j ] == 0 ) { printf ( "NO\n" ) ; return ; } 
            }
        }
    }
	printf ( "YES\n" ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			printf ( "%d" , ans[ i ][ j ] ) ;
			if ( j == m - 1 ) printf ( "\n" ) ;
			else printf ( " " ) ;
        }
    }
}