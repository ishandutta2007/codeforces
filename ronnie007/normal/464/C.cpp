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

#define MOD 1000000007

#define MAXN 100007

int n , q ;
string a ;
string s[ MAXN ] ;

int val[ 17 ] ;
long long len[ 17 ] ;

long long fastpow ( long long u , long long x ) {
	long long ret = 1 ;
	while ( x != 0 ) {
		if ( x % 2 == 0 ) {
			x /= 2 ;
			u = u * u ;
			u %= MOD ;
		}
		else {
			x -- ;
			ret *= u ;
			ret %= MOD ;
		}
	}
	return ret ;
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
	cin >> a ;
	n = a.size ( ) ;
	cin >> q ;
	int i ;
	for ( i = 1 ; i <= q ; i ++ ) {
		cin >> s[ i ] ; 
	}
}

void solve ( ) {
	int i , j ; 
	for ( i = 0 ; i <= 9 ; i ++ ) {
		val[ i ] = i ;
		len[ i ] = 1 ;
	}
	for ( i = q ; i >= 1 ; i -- ) {
		int id = ( s[ i ][ 0 ] - '0' ) ; 
		int sz = s[ i ].size ( ) ;
		int tot = 0 ;
		//len[ id ] = val[ id ] = 0 ;
		long long sm = 0 ;
		for ( j = sz - 1 ; j >= 3 ; j -- ) {
			sm += ( fastpow ( 10 , tot ) * val[ ( s[ i ][ j ] - '0' ) ] ) % MOD ;
			sm %= MOD ; 
			tot += ( len[ ( s[ i ][ j ] - '0' ) ] ) ;
			tot %= ( MOD - 1 ) ; // MOD is a prime number.
		}
		val[ id ] = sm ;
		len[ id ] = tot ;
		//printf ( "%d %d\n" , val[ id ] , len[ id ] ) ;
	}
	long long tot = 0 ;
	long long sm = 0 ;
	for ( i = n - 1 ; i >= 0 ; i -- ) {
		sm += ( fastpow ( 10 , tot ) * val[ ( a[ i ] - '0' ) ] ) % MOD ;
		sm %= MOD ;
		tot += len[ ( a[ i ] - '0' ) ] ;
		tot %= ( MOD - 1 ) ; // MOD is a prime number.
	}
	cout << sm << "\n" ;
}