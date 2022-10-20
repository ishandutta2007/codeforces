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
long long k ;
int f[ MAXN ][ 42 ] ;
long long sm[ MAXN ][ 42 ] ;
long long mn[ MAXN ][ 42 ] ;

long long pw2[ 42 ] ;

void input ( ) {
	cin >> n >> k ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> f[ i ][ 0 ] ;
		f[ i ][ 0 ] ++ ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> sm[ i ][ 0 ] ;
		mn[ i ][ 0 ] = sm[ i ][ 0 ] ;
	}
}

void solve ( ) {
	int i , j ;
	pw2[ 0 ] = 1 ;
	for ( i = 1 ; i <= 40 ; i ++ ) {
		pw2[ i ] = ( 2 * pw2[ i - 1 ] ) ;
	}
	for ( i = 1 ; pw2[ i ] <= k ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			f[ j ][ i ] = f[ f[ j ][ i - 1 ] ][ i - 1 ] ;
			sm[ j ][ i ] = sm[ j ][ i - 1 ] + sm[ f[ j ][ i - 1 ] ][ i - 1 ] ;
			mn[ j ][ i ] = min ( mn[ j ][ i - 1 ] , mn[ f[ j ][ i - 1 ] ][ i - 1 ] ) ;
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		long long ans1 , ans2 ;
		ans1 = 0 ;
		ans2 = mn[ i ][ 0 ] ;
		long long lft = k ;
		int vertex = i ;
		for ( j = 40 ; j >= 0 ; j -- ) {
			if ( lft - pw2[ j ] >= 0 ) {
				lft -= pw2[ j ] ;
				ans1 += sm[ vertex ][ j ] ;
				ans2 = min ( ans2 , mn[ vertex ][ j ] ) ;
				vertex = f[ vertex ][ j ] ;
			}
		}
		cout << ans1 << " " << ans2 << "\n" ;
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}