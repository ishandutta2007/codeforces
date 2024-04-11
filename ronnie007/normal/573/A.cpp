#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

int nod ;

int f ( int x , int y ) {
	if ( x < y ) { swap ( x , y ) ; }
	if ( y == 0 ) { return x ; }
	return f ( y , x % y ) ;
}

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
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		if ( i == 1 ) { nod = a[ i ] ; }
		else { nod = f ( nod , a[ i ] ) ; }
    }
}

void solve ( ) {
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		a[ i ] /= nod ;
		while ( a[ i ] % 2 == 0 ) { a[ i ] /= 2 ; }
		while ( a[ i ] % 3 == 0 ) { a[ i ] /= 3 ; }
		if ( a[ i ] != 1 ) { printf ( "No\n" ) ; return ; }
    }
	printf ( "Yes\n" ) ;
}