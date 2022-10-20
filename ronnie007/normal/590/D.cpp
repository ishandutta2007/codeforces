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
#include<set>
using namespace std ;

#define MAXN 157
#define inf 1000000007


int n , k , s ;
int a[ MAXN ] ;
int dp[ 2 ][ MAXN ][ ( MAXN * ( MAXN - 1 ) / 2 ) ] ;

void input ( ) ;
void solve ( ) ;

int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	scanf ( "%d%d%d" , &n , &k , &s ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}
 
void solve ( ) {
	int i , j , t ;
	if ( s >= ( n * ( n - 1 ) / 2 ) ) {
		sort ( a + 1 , a + n + 1 ) ;
		int ans = 0 ;
		for ( i = 1 ; i <= k ; i ++ ) { ans += a[ i ] ; }
		printf ( "%d\n" , ans ) ;
		return ; 
	}
	for ( i = 0 ; i < 2 ; i ++ ) {
		for ( j = 0 ; j <= k + 1 ; j ++ ) {
			for ( t = 0 ; t <= s + 1 ; t ++ ) {
				dp[ i ][ j ][ t ] = inf ;
			}
		}
	}
	int prev = 0 ;
	int cur = 1 ;
	dp[ 0 ][ 0 ][ 0 ] = 0 ;
	int ans = inf ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 0 ; j < k ; j ++ ) {
			if ( j >= i ) { continue ; }
			for ( t = 0 ; t <= s ; t ++ ) {
				if ( dp[ prev ][ j ][ t ] == inf ) { continue ; }
				int val = ( i - j - 1 ) ;
				if ( t + val <= s ) {
					dp[ cur ][ j + 1 ][ t + val ] = min ( dp[ cur ][ j + 1 ][ t + val ] , dp[ prev ][ j ][ t ] + a[ i ] ) ;
					if ( j == k - 1 ) { ans = min ( ans , dp[ cur ][ j + 1 ][ t + val ] ) ; }
				}
				dp[ cur ][ j ][ t ] = min ( dp[ cur ][ j ][ t ] , dp[ prev ][ j ][ t ] ) ;
			}
		}
		for ( j = 0 ; j <= k ; j ++ ) {
			for ( t = 0 ; t <= s ; t ++ ) {
				dp[ prev ][ j ][ t ] = inf ;
			}
		}
		prev ^= 1 ;
		cur ^= 1 ;
	}
	printf ( "%d\n" , ans ) ;
}