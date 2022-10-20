#include<iostream>
#include<stdio.h>
using namespace std ;

#define MOD 998244353
#define MAGIC 12252240

int n , k ;
int a[ MAGIC ] ;

long long fastpow ( long long x , long long pw ) {
	long long ret = 1 ;
	while ( pw > 0 ) {
		if ( ( pw % 2 ) == 0 ) {
			x = ( x * x ) % MOD ;
			pw /= 2 ;
		}
		else {
			ret = ( ret * x ) % MOD ;
			-- pw ; 
		}
	}
	return ret ;
}

long long dp[ 2 ][ MAGIC ] ;

void input ( ) {
	cin >> n >> a[ 0 ] ;
	long long x , y , m ;
	cin >> x >> y >> k >> m ;
	for ( int i = 1 ; i < n ; ++ i ) {
		a[ i ] = ( a[ i - 1 ] * x + y ) % m ;
	}
}

void solve ( ) {
	long long aux = fastpow ( n , k - 1 ) ;
	long long ans = 0 ; 
	int prv = 0 , nxt = 1 ;
	for ( int i = 0 ; i < n ; ++ i ) {
		int coef = ( a[ i ] / MAGIC ) ;
		long long hh = ( aux * coef * k ) % MOD ;
		ans = ( ans + hh * MAGIC ) % MOD ;
		a[ i ] %= MAGIC ;
		++ dp[ prv ][ a[ i ] ] ;
	}
	for ( int t = 1 ; t <= k ; ++ t ) {
		long long lft = fastpow ( n , k - t ) ;
		for ( int i = MAGIC - 1 ; i >= 0 ; -- i ) {
			aux = ( dp[ prv ][ i ] * i ) % MOD ;
			ans = ( ans + aux * lft ) % MOD ;
			dp[ nxt ][ i ] = ( dp[ nxt ][ i ] + dp[ prv ][ i ] * ( n - 1 ) ) % MOD ;
			int nw = i - ( i % t ) ;
			dp[ nxt ][ nw ] = ( dp[ nxt ][ nw ] + dp[ prv ][ i ] ) % MOD ;
			dp[ prv ][ i ] = 0 ;
		}
		prv ^= 1 , nxt ^= 1 ;
	}
	cout << ans << "\n" ;
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}