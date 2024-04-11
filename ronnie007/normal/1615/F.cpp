#include<iostream>
#include<stdio.h>
using namespace std ;

#define MAXN 2007
#define MOD 1000000007

int n ;
string a , b ;
long long ways[ MAXN ][ 2 * MAXN ] ;
long long dp[ MAXN ][ 2 * MAXN ] ;

void input ( ) {
	cin >> n >> a >> b ;
	for ( int i = 1 ; i < n ; i += 2 ) {
		if ( a[ i ] == '0' ) { a[ i ] = '1' ; }
		else if ( a[ i ] == '1' ) { a[ i ] = '0' ; }

		if ( b[ i ] == '0' ) { b[ i ] = '1' ; }
		else if ( b[ i ] == '1' ) { b[ i ] = '0' ; }
	}
	for ( int i = 0 ; i <= n ; ++ i ) {
		for ( int j = 0 ; j < 2 * MAXN ; ++ j ) {
			ways[ i ][ j ] = dp[ i ][ j ] = 0 ;
		}
	}
}

void solve ( ) {
	ways[ 0 ][ MAXN ] = 1 ;
	dp[ 0 ][ MAXN ] = 0 ;
	for ( int i = 0 ; i < n ; ++ i ) {
		int st1 = 0 , en1 = 1 ;
		int st2 = -1 , en2 = 0;
		if ( a[ i ] == '0' ) { en1 = 0 ; }
		if ( a[ i ] == '1' ) { st1 = 1 ; }
		if ( b[ i ] == '0' ) { st2 = 0 ; }
		if ( b[ i ] == '1' ) { en2 = -1 ; }
		for ( int prv = 0 ; prv < 2 * MAXN ; ++ prv ) {
			if ( ways[ i ][ prv ] == 0 ) { continue ; }
			for ( int j = st1 ; j <= en1 ; ++ j ) {
				for ( int t = st2 ; t <= en2 ; ++ t ) {
					ways[ i + 1 ][ prv + j + t ] += ways[ i ][ prv ] ;
					if ( ways[ i + 1 ][ prv + j + t ] >= MOD ) {
						ways[ i + 1 ][ prv + j + t ] -= MOD ;
					}
					dp[ i + 1 ][ prv + j + t ] += ( dp[ i ][ prv ] + 1LL * abs ( MAXN - ( prv + j + t ) ) * ways[ i ][ prv ] ) % MOD ;
					if ( dp[ i + 1 ][ prv + j + t ] >= MOD ) {
						dp[ i + 1 ][ prv + j + t ] -= MOD ;
					}
				}
			}
		}
	}
	cout << dp[ n ][ MAXN ] << "\n" ;
}

int main ( ) {
	ios_base :: sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	int t ;
	cin >> t ;
	while ( t -- ) { 
		input ( ) ;
		solve ( ) ;
	}
	return 0 ;
}