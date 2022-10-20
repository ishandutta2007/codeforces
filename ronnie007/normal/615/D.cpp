#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std ;

#define MOD 1000000007
#define MAXN 300007

long long used[ MAXN ] ;

long long fpow ( long long a , long long x ) {
	long long r = 1 ;
	while ( x != 0 ) {
		if ( x % 2 == 0 ) {
			a = a * a ;
			a %= MOD ;
			x /= 2 ; 
		}
		else {
			r = r * a ;
			r %= MOD ;
			x -- ;
		}
	}
	return r ;
}

void input ( ) {
	int n ;
	scanf ( "%d" , &n ) ;
	int x ;
	while ( n != 0 ) {
		n -- ;
		scanf ( "%d" , &x ) ;
		used[ x ] ++ ;
	}
}

void solve ( ) {
	int i ;
	int j ;
	long long tot = 1 ;
	long long ans = 1 ;
	for ( i = 2 ; i <= 200000 ; i ++ ) {
		if ( used[ i ] == 0 ) { continue ; }
		long long cur = fpow ( ans , used[ i ] + 1 ) ;
		ans = cur ; 
		for ( j = 0 ; j <= used[ i ] ; j ++ ) {
			long long h = fpow ( i ,  j ) ;
			h = fpow ( h , tot ) ;
			ans *= h ;
			ans %= MOD ;
		}
		tot = ( tot * ( used[ i ] + 1 ) ) % ( MOD - 1 ) ;
	}
	printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}