#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 100007

int n ;
vector < int > v[ MAXN ] ;
int a[ MAXN ] ;
int f[ MAXN ] ;

int br[ MAXN ][ 21 ][ 2 ] ;

long long ans = 0 ;

void init ( int vertex , int prv ) {
	if ( prv != -1 ) {
		f[ vertex ] = ( f[ prv ] ^ a[ vertex ] ) ;
	}
	else { f[ vertex ] = a[ vertex ] ; }
	int i , j ;
	int sz = v[ vertex ].size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		init ( v[ vertex ][ i ] , vertex ) ;
		for ( j = 0 ; j < 20 ; j ++ ) {
			br[ vertex ][ j ][ 0 ] += br[ v[ vertex ][ i ] ][ j ][ 0 ] ;
			br[ vertex ][ j ][ 1 ] += br[ v[ vertex ][ i ] ][ j ][ 1 ] ;			
		}
	}
	for ( j = 0 ; j < 20 ; j ++ ) {
		if ( ( f[ vertex ] & ((1<<j)) ) == 0 ) {
			br[ vertex ][ j ][ 0 ] ++ ;
		}
		else { br[ vertex ][ j ][ 1 ] ++ ; }
	}
}

void dfs ( int vertex , int prv ) {
	int i , j ;
	int sz = v[ vertex ].size ( ) ;
	for ( j = 0 ; j < 20 ; j ++ ) {
		if ( ( f[ vertex ] & ((1<<j)) ) == 0 ) { br[ vertex ][ j ][ 0 ] -- ; }
		else { br[ vertex ][ j ][ 1 ] -- ; }
	}	
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] == prv ) { continue ; }
		for ( j = 0 ; j < 20 ; j ++ ) {
			if ( ( a[ vertex ] & ((1<<j)) ) == 0 ) {
				ans += ( 1LL * ((1<<j)) * ( br[ vertex ][ j ][ 1 ] - br[ v[ vertex ][ i ] ][ j ][ 1 ] ) * br[ v[ vertex ][ i ] ][ j ][ 0 ] ) ;
				ans += ( 1LL * ((1<<j)) * ( br[ vertex ][ j ][ 0 ] - br[ v[ vertex ][ i ] ][ j ][ 0 ] ) * br[ v[ vertex ][ i ] ][ j ][ 1 ] ) ;				
			}
			else {
				ans += ( 1LL * ((1<<j)) * ( br[ vertex ][ j ][ 1 ] - br[ v[ vertex ][ i ] ][ j ][ 1 ] ) * br[ v[ vertex ][ i ] ][ j ][ 1 ] ) ;
				ans += ( 1LL * ((1<<j)) * ( br[ vertex ][ j ][ 0 ] - br[ v[ vertex ][ i ] ][ j ][ 0 ] ) * br[ v[ vertex ][ i ] ][ j ][ 0 ] ) ;
			}
		}		
		dfs ( v[ vertex ][ i ] , vertex ) ;
	}
	for ( j = 0 ; j < 20 ; j ++ ) {
		if ( ( f[ vertex ] & ((1<<j)) ) == 0 ) { br[ vertex ][ j ][ 0 ] ++ ; }
		else { br[ vertex ][ j ][ 1 ] ++ ; }
	}		
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	for ( i = 1 ; i < n ; i ++ ) {
		int x , y ;
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
}

void solve ( ) {
	init ( 1 , -1 ) ;
	int i , j ;
	dfs ( 1 , -1 ) ;
	ans /= 2 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 0 ; j < 20 ; j ++ ) {
			if ( ( f[ i ] & ((1<<j)) ) == 0 ) {
				if ( ( a[ i ] & ((1<<j)) ) == 0 ) {
					ans += ( 1LL * ((1<<j)) * br[ i ][ j ][ 1 ] ) ;
				}
				else {
					ans += ( 1LL * ((1<<j)) * br[ i ][ j ][ 0 ] ) ;			
				}
			}
			else {
				if ( ( a[ i ] & ((1<<j)) ) == 0 ) {
					ans += ( 1LL * ((1<<j)) * br[ i ][ j ][ 0 ] ) ;
				}
				else {
					ans += ( 1LL * ((1<<j)) * br[ i ][ j ][ 1 ] ) ;
				}
			}		
		}
	}
	cout << ans << "\n" ;	
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}