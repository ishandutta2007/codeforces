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
using namespace std ;

int n ;
int a[ 2000007 ] ;
int b[ 2000007 ] ;
int l[ 200007 ] ;
int r[ 200007 ] ;
int used1[ 1000007 ] ;
int used2[ 1000007 ] ;

int ans[ 200007 ] ;

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
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &l[ i ] , &r[ i ] ) ;
		a[ l[ i ] ] = i ;
		b[ r[ i ] ] = i ;
    }
}

void solve ( )  {
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		used1[ l[ i ] ] = 1 ;
		used2[ r[ i ] ] = 1 ;
    }
	for ( i = 1 ; i <= 1000000 ; i ++ ) {
		if ( used1[ i ] == 1 && used2[ i ] == 0 ) break ;
    }
	ans[ 0 ] = i ;
	int x ;
	int val ;
	val = i ; 
	for ( i = 0 ; i < n ; i ++ ) {
		if ( l[ i ] == 0 ) break ;
    }
	x = i ; 

	for ( i = 1 ; i < n ; i ++ ) {
		ans[ i ] = r[ x ] ;
		x = a[ val ] ;
		val = ans[ i ] ;

    }
	for ( i = 0 ; i < n ; i ++ ) {
		printf ( "%d" , ans[ i ] ) ;
		if ( i == n - 1 ) printf ( "\n" ) ;
		else printf ( " " ) ;
    }
}