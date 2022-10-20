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

#define inf 1000000007

int n ;
int a[ 307 ] ;
int c[ 307 ] ;
vector < int > v ;
int dp[ 700007 ] ;

int w ( int x , int y ) {
	if ( x < y ) { swap ( x , y ) ; } 
	if ( y == 0 ) { return x ; } 
	return ( w ( y , x % y ) ) ;
}

void input ( ) ;
void solve ( ) ;

int get ( int x ) {
	int l , r , mid ;
	l = 0 ;
	r = v.size ( ) - 1 ;
	while ( r - l > 7 ) {
		mid = ( l + r ) / 2 ; 
		if ( v[ mid ] < x ) { l = mid ; } 
		else { r = mid ; } 
    }
	int i ;
	for ( i = l ; i <= r ; i ++ ) {
		if ( v[ i ] == x ) { return i ; } 
    }
}

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
		scanf ( "%d" , &a[ i ] ) ;
    }
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &c[ i ] ) ;
    }
}

void solve ( )  {
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 1 ; j * j <= a[ i ] ; j ++ ) {
			if ( a[ i ] % j != 0 ) { continue ; } 
			v.push_back ( j ) ;
			if ( j * j != a[ i ] ) { v.push_back ( a[ i ] / j ) ; } 
        }
    }
	sort ( v.begin ( ) , v.end ( ) ) ;
	v.erase ( unique ( v.begin ( ) , v.end ( ) ) , v.end ( ) ) ;
	for ( i = 0 ; i < v.size ( ) ; i ++ ) {
		//printf ( "%d\n" , v[ i ] ) ;
		dp[ i ] = inf ;
    }
	for ( i = 0 ; i < n ; i ++ ) {
		dp[ get ( a[ i ] ) ] = min ( dp[ get ( a[ i ] ) ] , c[ i ] ) ; 
    }
	for ( i = v.size ( ) - 1 ; i >= 0 ; i -- ) {
		if ( dp[ i ] == inf ) { continue ; }
		for ( j = 0 ; j < n ; j ++ ) {
			int u = w ( a[ j ] , v[ i ] ) ;
			if ( u == v[ i ] ) { continue ; }
			int id = get ( u ) ;
			dp[ id ] = min ( dp[ id ] , dp[ i ] + c[ j ] ) ;
        }
    }
	if ( dp[ 0 ] == inf ) { printf ( "-1\n" ) ; return ; } 
	printf ( "%d\n" , dp[ 0 ] ) ;
}