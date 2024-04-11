#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std ;

#define MOD 1000000007

int d , n ;
int cost[ 2007 ] ;
vector < int > v[ 2007 ] ; 
int used[ 2007 ] ;

long long ans = 0 ;

//long long cur = 0 ;

int limit ;
int st ;

long long dfs ( int vertex  ) {
	int i ;
	used[ vertex ] = 1 ;
	int sz = v[ vertex ].size ( ) ;
	long long cur = 1 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		int h = v[ vertex ][ i ] ;
		if ( used[ h ] == 1 ) continue ;
		if ( cost[ h ] < cost[ st ] ) continue ;
		if ( cost[ h ] > limit ) continue ;
		//cur = cur 
		cur = cur * ( dfs ( h ) + 1 ) ;
		cur %= MOD ;
    }
	return cur ;
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
	scanf ( "%d%d" , &d , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) scanf ( "%d" , &cost[ i ] ) ;

	int x , y ;
	for ( i = 0 ; i < n - 1 ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
    }
}
 
void solve ( )  {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			used[ j ] = 0 ;
			if ( j <= i && cost[ j ] == cost[ i ] ) used[ j ] = 1 ;
		}
		limit = cost[ i ] + d ;
		st = i ;
		//cur = 1 ;
		ans = ( ans + dfs ( i ) ) % MOD ;
		//ans = ( ans + cur ) % MOD ;
		//printf ( "i = %d, cur = %I64d\n" , i , cur ) ;
    }
	printf ( "%I64d\n" , ans ) ;
}