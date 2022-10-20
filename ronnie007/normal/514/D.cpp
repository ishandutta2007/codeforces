#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std ;

int n , m , k ;
int a[ 100007 ][ 7 ] ;
int rmq[ 100007 ][ 20 ][ 5 ] ;
int st[ 100007 ] ;
int g[ 100007 ] ;
int outp[ 100007 ] ;

void input ( ) ;
void solve ( ) ;

bool f ( int l , int r ) {
	int i ;
	int id ;
	int len = ( r - l + 1 ) ;
	id = r - st[ len ] + 1 ;
	int sm = 0 ;
	for ( i = 0 ; i < m ; i ++ ) {
		sm += max ( rmq[ l ][ g[ len ] ][ i ] , rmq[ id ][ g[ len ] ][ i ] ) ;
    }
	return ( sm <= k ) ;
}

void getans ( int l , int r ) {
	int i ;
	int id ;
	int len = ( r - l + 1 ) ;
	id = r - st[ len ] + 1 ;
	for ( i = 0 ; i < m ; i ++ ) {
		printf ( "%d" , max ( rmq[ l ][ g[ len ] ][ i ] , rmq[ id ][ g[ len ] ][ i ] ) ) ;
		if ( i == m - 1 ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d%d" , &n , &m , &k ) ;
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}
 
void solve ( )  {
	int i , j , t ;
	for ( t = 0 ; t < m ; t ++ ) {
		for ( i = 0 ; i < n ; i ++ ) {
			rmq[ i ][ 0 ][ t ] = a[ i ][ t ] ;
        }
		for ( j = 1 ; j < 20 ; j ++ ) {
			int u = (1<<j) ;
			int z = (1<<(j-1)) ;
			for ( i = 0 ; i + u <= n ; i ++ ) {
				int id = i + z ;
				rmq[ i ][ j ][ t ] = max ( rmq[ i ][ j - 1 ][ t ] , rmq[ id ][ j - 1 ][ t ] ) ; 
            }
        }
    }
	j = 1 ;
	int h = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( 2 * j <= i ) { h ++ ; j *= 2 ; }
		st[ i ] = j ;
		g[ i ] = h ;
    }
	int l , r ;
	int mid ;
	int ans = -1 ;
	int ansl = -1 , ansr = -1 ;
	for ( i = 0 ; i < n ; i ++ ) {
		l = i ; 
		r = n - 1 ; 
		while ( r - l > 2 ) {
			mid = ( l + r ) / 2 ;
			if ( f ( i , mid ) == true ) { l = mid ; }
			else { r = mid ; }
        }
		while ( r >= i ) {
			if ( f ( i , r ) == true ) { break ; }
			r -- ;
        }
		if ( r >= i ) { 
			if ( ans < ( r - i + 1 ) ) { ans = ( r - i + 1 ) ; ansl = i ; ansr = r ; } 
		}
    }
	if ( ansl == -1 && ansr == -1 ) {
		for ( i = 0 ; i < m ; i ++ ) {
			printf ( "0" ) ;
			if ( i == m - 1 ) { printf ( "\n" ) ; }
			else { printf ( " " ) ; } 
        }
    }
	else { getans ( ansl , ansr ) ; }
}