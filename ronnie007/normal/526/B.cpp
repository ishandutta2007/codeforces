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

int n ;
int sz ;
int len[ 3007 ] ;
int dist[ 3007 ] ;
int lft[ 3007 ] ;

int LEAVES = 1 ;

int ans = 0 ;

void f ( int l , int r ) {
	if ( l > r ) { return ; }
	int mn = lft[ l ] ;
	int i ;
	for ( i = l ; i <= r ; i ++ ) {
		if ( mn > lft[ i ] ) { mn = lft[ i ] ; }
    }
	ans += mn ;
	for ( i = l ; i <= r ; i ++ ) { lft[ i ] -= mn ; }
	if ( l == r ) { return ; }
	int mid = ( l + r ) / 2 ;
	f ( l , mid ) ;
	f ( mid + 1 , r ) ;
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
	scanf ( "%d" , &n ) ;
	int i ;
	LEAVES = 1 ;
	for ( i = 0 ; i < n ; i ++ ) { LEAVES *= 2 ; }
	sz = 1 ;
	for ( i = 0 ; i < n + 1 ; i ++ ) {
		sz *= 2 ;
    }
	sz -= 2 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		scanf ( "%d" , &len[ i ] ) ;
		dist[ 2 + i ] = dist[ ( 2 + i ) / 2 ] + len[ i ] ;
    }
	int mx = 0 ;
	for ( i = 1 ; i <= LEAVES ; i ++ ) {
		if ( mx < dist[ LEAVES + i - 1 ] ) { mx = dist[ LEAVES + i - 1 ] ; }
    }
	for ( i = 1 ; i <= LEAVES ; i ++ ) {
		lft[ i ] = mx - dist[ LEAVES + i - 1 ] ;
    }
}

void solve ( )  {
	f ( 1 , LEAVES ) ;
	printf ( "%d\n" , ans ) ;
}