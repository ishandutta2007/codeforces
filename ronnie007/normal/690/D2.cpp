#include<iostream>
#include<stdio.h>
using namespace std ;

#define MOD 1000003
#define MAXN 1000007

long long n , k ;
long long fac[ MAXN ] ;
long long inv[ MAXN ] ;


long long fastpow ( long long a , long long x ) {
	long long r = 1 ;
	while ( x != 0 ) {
		if ( x % 2 == 0 ) {
			a = ( a * a ) % MOD ;
			x /= 2 ;
		}
		else {
			r = ( r * a ) % MOD ;
			x -- ; 
		}
	}
	return r ;
}

void input ( ) {
	cin >> n >> k ;
}

void solve ( ) {
	fac[ 0 ] = 1 ;
	int i ;
	for ( i = 1 ; i <= 1000000 ; i ++ ) {
		fac[ i ] = ( i * fac[ i - 1 ] ) % MOD ;
    }
	long long ans = 0 ;
	for ( i = 1 ; i <= k ; i ++ ) {
		long long cur = 1 ;
		cur *= fac[ n + i - 1 ] ;
		cur %= MOD ;
		long long inv = ( fac[ i ] * fac[ ( n - 1 ) ] ) % MOD ;
		cur *= fastpow ( inv , MOD - 2 ) ;
		cur %= MOD ;
		ans += cur ;
		ans %= MOD ;
	}
	cout << ans << "\n" ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}