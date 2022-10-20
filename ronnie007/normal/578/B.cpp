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
#include<stack>
using namespace std ;

#define MAXN 200007

int n , k , x ;
long long a[ MAXN ] ;
long long pref[ MAXN ] ;
long long suff[ MAXN ] ;

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
	scanf ( "%d%d%d" , &n , &k , &x ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		pref[ i ] = ( pref[ i - 1 ] | a[ i ] ) ;
	}
	for ( i = n ; i >= 1 ; i -- ) {
		suff[ i ] = ( suff[ i + 1 ] | a[ i ] ) ;
	}
	long long g = 1 ;
	for ( i = 1 ; i <= k ; i ++ ) { g *= x ; }
	long long ans = pref[ n ] ;
	for ( i = 1 ; i <= n ; i ++ ) {
		long long u = pref[ i - 1 ] ;
		u |= suff[ i + 1 ] ;
		long long h = g * a[ i ] ;
		u |= h ;
		ans = max ( ans , u ) ;
	}
	printf ( "%I64d\n" , ans ) ;
}