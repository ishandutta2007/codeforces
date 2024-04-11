#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
int l[ MAXN ] ;
int r[ MAXN ] ;
int ans[ MAXN ] ;

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
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( )  {
	stack < int > s ;
	int i ;
	s.push ( 0 ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		//printf ( "%d\n" , s.top ( ) ) ;
		while ( s.top ( ) > 0 && a[ i ] <= a[ s.top ( ) ] ) {
			s.pop ( ) ;
        }
		l[ i ] = s.top ( ) ;
		s.push ( i ) ;
    }
	while ( s.empty ( ) == false ) { s.pop ( ) ; }
	s.push ( n + 1 ) ;
	for ( i = n ; i >= 1 ; i -- ) {
		//printf ( "%d\n" , s.top ( ) ) ;
		while ( s.top ( ) <= n && a[ i ] < a[ s.top ( ) ] ) {
			s.pop ( ) ;
        }
		r[ i ] = s.top ( ) ;
		s.push ( i ) ;
    }
	for ( i = 1 ; i <= n ; i ++ ) {
		//printf ( "%d %d\n" , l[ i ] , r[ i ] ) ;
		int len = ( i - l[ i ] - 1 ) + ( r[ i ] - i - 1 ) + 1 ;
		if ( ans[ len ] < a[ i ] ) { ans[ len ] = a[ i ] ; }
    }
	for ( i = n ; i >= 1 ; i -- ) {
		if ( ans[ i ] < ans[ i + 1 ] ) { ans[ i ] = ans[ i + 1 ] ; }
    }
	for ( i = 1 ; i <= n ; i ++ ) {
		printf ( "%d" , ans[ i ] ) ;
		if ( i == n ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
    }
}