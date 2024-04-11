#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
using namespace std ;

int n ;
int a , b ; 
vector < pair < int , int > > v ; 

int used[ 100007 ] ;
int ans[ 100007 ] ; 
int e ; 
map < int , int > ZX ; 


void input ( ) ;
void solve ( ) ;


int main ( )  {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d%d" , &n , &a , &b ) ;
	if ( a < b ) { e = 1 ; swap ( a , b ) ; }
	else e = 0 ; 
	v.resize ( n ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &v[ i ].first ) ;
		v[ i ].second = i ;
	}
	sort ( v.begin ( ) , v.end ( ) ) ;
	ZX[ v[ 0 ].first ] = 1 ; 
	for ( i = 1 ; i < n ; i ++ ) {
		//if ( v[ i ].first == v[ i - 1 ].first ) continue ;
		ZX[ v[ i ].first ] = i + 1 ;
	}
}

void solve ( )  {
	int i ;
	int p ; 
	int j ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( used[ i ] == 1 ) continue ;
		p = a - v[ i ].first ; 
		if ( ZX[ p ] != 0 ) {
			j = ZX[ p ] - 1 ;
			used[ i ] = 1 ;
			used[ j ] = 1 ;
			ans[ v[ i ].second ] = -1 ;
			ans[ v[ j ].second ] = -1 ;
			ZX[ p ] = 0 ; 
			ZX[ v[ i ].first ] = 0 ; 
			continue ;
		}
		p = b - v[ i ].first ; 

		if ( ZX[ p ] != 0 ) {
			j = ZX[ p ] - 1 ;
			used[ i ] = 1 ;
			used[ j ] = 1 ;
			ans[ v[ i ].second ] = 1 ;
			ans[ v[ j ].second ] = 1 ;
			ZX[ p ] = 0 ; 
			ZX[ v[ i ].first ] = 0 ; 
			continue ;
		}
		printf ( "NO\n" ) ;
		return ;
	}
	printf ( "YES\n" ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		printf ( "%d" , ( ( ( ans[ i ] + 1 ) / 2 ) ^ e ) ) ;
		if ( i != n - 1 ) printf ( " " ) ;
		else printf ( "\n" ) ; 
	}
}