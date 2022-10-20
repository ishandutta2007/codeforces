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

int n , k ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;
int ans = 0 ;

void dfs ( int vertex , int lst , int br ) {
	if ( a[ vertex ] == 1 ) { br ++ ; }
	else { br = 0 ; }
	int i ;
	int sz = v[ vertex ].size ( ) ;
	if ( sz == 1 && lst != -1 ) {
		if ( br <= k ) { ans ++ ; }
		return ;
	}
	if ( br > k ) { return ; }
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( v[ vertex ][ i ] != lst ) {
			dfs ( v[ vertex ][ i ] , vertex , br ) ;
		}
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

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
	int x , y ;
	for ( i = 1 ; i <= n - 1 ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
}

void solve ( ) {
	dfs ( 1 , -1 , 0 ) ;
	printf ( "%d\n" , ans ) ;
}