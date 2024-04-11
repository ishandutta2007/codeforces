#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

#define inf 10000000

int n ;
int p , q ;
int a[ 15 ] ;
int b[ 15 ] ;

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	scanf ( "%d" , &p ) ;
	for ( i = 0 ; i < p ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
	scanf ( "%d" , &q ) ;
	for ( i = 0 ; i < q ; i ++ ) {
		scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
	queue < int > x , y ;
	int i ;
	for ( i = 0 ; i < p ; i ++ ) { x.push ( a[ i ] ) ; }
	for ( i = 0 ; i < q ; i ++ ) { y.push ( b[ i ] ) ; }

	int br = 0 ; 
	int val1 , val2 ;
	while ( 1 ) {
		if ( br == inf ) { break ; }
		if ( x.empty ( ) == true || y.empty ( ) == true ) { break ; }
		br ++ ;
		val1 = x.front ( ) ;
		x.pop ( ) ;
		val2 = y.front ( ) ;
		y.pop ( ) ;
		if ( val1 > val2 ) {
			x.push ( val2 ) ;
			x.push ( val1 ) ;
        }
		else {
			y.push ( val1 ) ;
			y.push ( val2 ) ;
        }
    }
	if ( br == inf ) { printf ( "-1\n" ) ; }
	else {
		printf ( "%d " , br ) ;
		if ( x.empty ( ) == true ) { printf ( "2\n" ) ; }
		else { printf ( "1\n" ) ; }
	}
}