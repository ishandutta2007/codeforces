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
pair < int , int > a[ 107 ] ;

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
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ].first ) ;
		a[ i ].second = i + 1 ; 
    }
	sort ( a , a + n ) ;
}

void solve ( )  {
	int i ;
	vector < int > v ;
	v.clear ( ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		k -= a[ i ].first ;
		if ( k >= 0 ) { v.push_back ( a[ i ].second ) ; } 
		else { break ; } 
    }
	printf ( "%d\n" , v.size ( ) ) ;
	for ( i = 0 ; i < v.size ( ) ; i ++ ) {
		printf ( "%d" , v[ i ] ) ;
		if ( i == v.size ( ) - 1 ) { printf ( "\n" ) ; } 
		else { printf ( " " ) ; }
    }
}