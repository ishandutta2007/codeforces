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

#define MAXN 100007
#define OFFSET 100000


int n ;
pair < int , int > a[ MAXN ] ;
int val[ MAXN ] ;
vector < int > v[ 2 * MAXN ] ;
int pos[ 2 * MAXN ] ;
int mxx[ MAXN ] ;
int mxy[ MAXN ] ;


bool cmp ( int p1 , int p2 ) {
	return ( a[ p1 ].first + a[ p1 ].second < a[ p2 ].first + a[ p2 ].second ) ;
}

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
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
		v[ a[ i ].second - a[ i ].first + OFFSET ].push_back ( i ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &val[ i ] ) ;
	}
	for ( i = 0 ; i <= 2 * OFFSET ; i ++ ) {
		sort ( v[ i ].begin ( ) , v[ i ].end ( ) , cmp ) ;
	}
}

void solve ( ) {
	vector < int > ans ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int id = val[ i ] + OFFSET ;
		if ( pos[ id ] >= v[ id ].size ( ) ) { printf ( "NO\n" ) ; return ; }
		int u = v[ id ][ pos[ id ] ] ;
		pos[ id ] ++ ;
		if ( a[ u ].first < mxx[ a[ u ].second ] ) { printf ( "NO\n" ) ; return ; }
		if ( a[ u ].second < mxy[ a[ u ].first ] ) { printf ( "NO\n" ) ; return ; }
		mxx[ a[ u ].second ] = a[ u ].first ; 
		mxy[ a[ u ].first ] = a[ u ].second ;
		ans.push_back ( u ) ;
	}
	printf ( "YES\n" ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		printf ( "%d %d\n" , a[ ans[ i ] ].first , a[ ans[ i ] ].second ) ;
	}
}