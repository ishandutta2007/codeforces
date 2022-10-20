#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

int n ;
int a[ 100007 ] ;
int l[ 100007 ] ;
int r[ 100007 ] ;
int ans[ 100007 ] ;
int br[ 100007 ] ;

vector < int > v ; 

int f ( int x ) {
	if ( v.size ( ) == 0 ) {
		v.push_back ( x ) ;
		return 1 ;
    }
	int l , r , mid ;
	l = 0 ;
	r = v.size ( ) - 1 ;
	if ( v[ r ] < x ) {
		v.push_back ( x ) ;
		return v.size ( ) ;
    }
	if ( v[ l ] > x ) {
		v[ l ] = x ;
		return 1 ;
    }
	while ( r - l > 7 ) {
		mid = ( l + r ) / 2 ;
		if ( v[ mid ] <= x ) l = mid ;
		else r = mid ;
    }
	int i ;
	for ( i = l ; i <= r ; i ++ ) {
		if ( v[ i ] >= x ) {
			v[ i ] = x ;
			return ( i + 1 ) ;
		}
    }
	return 1337 ;
}

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
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
}

void solve ( )  {
	int i ;
	v.clear ( ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		l[ i ] = f ( a[ i ] ) ;
    }
	v.clear ( ) ;
	for ( i = n - 1 ; i >= 0 ; i -- ) {
		r[ i ] = f ( - a[ i ] ) ;
    }
	int len = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		//printf ( "l[ %d ] = %d , r[ %d ] = %d\n" , i , l[ i ] , i , r[ i ] ) ;
		if ( len < l[ i ] ) len = l[ i ] ; 
    }
	for ( i = 0 ; i < n ; i ++ ) {
		int u = l[ i ] + r[ i ] - 1 ;
		if ( u < len ) ans[ i ] = 1 ; 
		else {
			br[ l[ i ] ] ++ ;
        }
    }
	for ( i = 0 ; i < n ; i ++ ) {
		int u = l[ i ] + r[ i ] - 1 ;
		if ( u == len ) {
			if ( br[ l[ i ] ] == 1 ) ans[ i ] = 3 ;
			else ans[ i ] = 2 ; 
        }
    }
	for ( i = 0 ; i < n ; i ++ ) {
		printf ( "%d" , ans[ i ] ) ;
    }
	printf ( "\n" ) ;
}