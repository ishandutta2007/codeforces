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

int n , m ; 

struct tuhla {
	int to ;
	int c ;
};
int used[ 107 ] ;
vector < struct tuhla > v[ 107 ] ; 

void dfs ( int vertex , int p ) {
	used[ vertex ] = 1 ;
	int sz = v[ vertex ].size ( ) ;
	int i ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ].c != p ) { continue ; } 
		if ( used[ v[ vertex ][ i ].to ] == 1 ) { continue ; } 
		dfs ( v[ vertex ][ i ].to , p ) ;
    }
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


void input ( )  {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	int x , y , z ;
	struct tuhla u ;
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d%d%d" , &x , &y , &z ) ;
		u.c = z ;
		u.to = y ;
		v[ x ].push_back ( u ) ;
		u.to = x ;
		v[ y ].push_back ( u ) ;
    }
}

void solve ( )  {
	int q ;
	int x , y ;
	scanf ( "%d" , &q ) ;
	int i , j ;
	int ans = 0 ; 
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d%d" , &x , &y ) ;
		ans = 0 ; 
		for ( i = 1 ; i <= m ; i ++ ) {
			for ( j = 1 ; j <= n ; j ++ ) { used[ j ] = 0 ; } 
			dfs ( x , i ) ;
			if ( used[ y ] == 1 ) { ans ++ ; } 
        }
		printf ( "%d\n" , ans ) ;
    }
}