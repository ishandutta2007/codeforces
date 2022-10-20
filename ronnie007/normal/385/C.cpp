#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n , m ;
int a[ 1000007 ] ;
int ans[ 10000007 ] ; 
int used[ 10000007 ] ;
int isone[ 10000007 ] ; 
int br[ 10000007 ] ; 
int mx = 0 ;
vector < int > v[ 1000007 ] ; 


void input ( ) ;
void solve ( ) ;



int main ( )  {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		isone[ a[ i ] ] = i + 1 ; 
		if ( mx < a[ i ] ) mx = a[ i ] ; 
	}
	sort ( a , a + n ) ;
}

void solve ( ) {
	int i ;
	int j ;
	int ind = 0 ; 
 	for ( i = 2 ; i * i <= mx ; i ++ ) {
		if ( used[ i ] != 0 ) continue ;
		ind = 0 ;
		while ( a[ ind ] < i & ind < n ) ind ++ ;
		for ( j = i ; j <= 10000000 ; j += i ) {
			used[ j ] = 1 ;
			while ( a[ ind ] < j && ind < n ) ind ++ ;
			while ( a[ ind ] == j ) {
				if ( a[ ind ] == j ) {
					br[ i ] ++ ;
					v[ ind ] .push_back ( i ) ;
				}
				ind ++ ;
			}
		}
	}
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < v[ i ].size ( ) ; j ++ ) {
			while ( a[ i ] % v[ i ][ j ] == 0 ) a[ i ] /= v[ i ][ j ] ; 
		}
		if ( a[ i ] != 0 && a[ i ] != 1  ) br[ a[ i ] ] ++ ;
	}
	int ad = 0 ; 
	for ( i = 0 ; i <= 10000000 ; i ++ ) {
		ad += br[ i ] ;
		ans[ i ] = ad ;
	}
	scanf ( "%d" , &m ) ;
	int l , r ;
	for ( i = 0 ; i < m ; i ++ ) {
		///printf ( "$ m = %d\n" , m ) ;
		scanf ( "%d%d" , &l , &r ) ;
		if ( r > mx ) r = mx ;
		if ( l > mx ) {
			printf ( "0\n" ) ;
		}
		else {
			printf ( "%d\n" , ans[ r ] - ans[ l - 1 ] ) ;
		}

	}
}