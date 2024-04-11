
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
#define MAXN 200007

int n ;
vector < int > v[ MAXN ] ;
int par[ MAXN ] ;

long long dp1[ MAXN ] ;
long long dp2[ MAXN ] ;
long long calc[ MAXN ] ;

void input ( ) ;
void solve ( ) ;

long long fastmul ( long long a , long long x ) {
	long long r = 1 ;
	while ( x != 0 ) {
		if ( x % 2 == 0 ) { a = a * a ; a %= MOD ; x /= 2 ; }
		else { r = r * a ; r %= MOD ; x -- ; }
    }
	return r ;
}

long long invmod ( long long x , long long y ) {
	return ( ( ( x % MOD ) * ( fastmul ( y , MOD - 2 ) % MOD ) ) % MOD ) ;
}

long long dfs1 ( int vertex ) {
	int sz = v[ vertex ].size ( ) ;
	int i ;
	if ( sz == 0 ) { 
		dp1[ vertex ] = 1 ;
	}
	dp1[ vertex ] = 1 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		long long x = dfs1 ( v[ vertex ][ i ] ) ;
		dp1[ vertex ] = ( dp1[ vertex ] * ( x + 1 ) ) % MOD ;
    }
	return dp1[ vertex ] ;
}

void dfs2 ( int vertex ) {
	int sz ;
	int i ;
	if ( vertex != 1 ) {
		int u = par[ vertex ] ;
		long long cur = dp2[ u ] ; 
		if ( dp1[ vertex ] + 1 == MOD ) {
			sz = v[ u ].size ( ) ;
			for ( i = 0 ; i < sz ; i ++ ) {
				if ( v[ u ][ i ] == vertex ) { continue ; }
				cur = ( cur * ( dp1[ v[ u ][ i ] ] + 1 ) ) % MOD ;
	        }
		}
		else {
			long long h = invmod ( dp1[ u ] , ( dp1[ vertex ] + 1 ) ) ;
			h %= MOD ;
			if ( v[ u ].size ( ) == 1 ) { h = 1 ; }
			cur *= h ;
			cur %= MOD ;
		}
		dp2[ vertex ] = ( cur + 1 ) % MOD ;
    }
	sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		dfs2 ( v[ vertex ][ i ] ) ;
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d" , &n ) ;	
	int i ;
	int x ;
	for ( i = 2 ; i <= n ; i ++ ) {
		scanf ( "%d" , &x ) ;
		v[ x ].push_back ( i ) ;
		par[ i ] = x ;
    }
}
 
void solve ( )  {
	dfs1 ( 1 ) ;
	dp2[ 1 ] = 1 ;
	dfs2 ( 1 ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		dp1[ i ] *= dp2[ i ] ;
		dp1[ i ] %= MOD ;
		printf ( "%I64d" , dp1[ i ] ) ;
		if ( i == n ) { printf ( "\n" ) ; }
		else { printf ( " " ) ; }
    }
}