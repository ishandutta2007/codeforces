#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
using namespace std ;

#define MOD 1000000007

#define MAXN 2007

int m , u ;
int n ;
string st , en ;

long long dp[ 2 ][ MAXN ][ 2 ] ;

bool g ( string x ) {
	int i ;
	for ( i = 0 ; i < n ; i += 2 ) {
		if ( ( x[ i ] - '0' ) == u ) { return false ; }
	}
	for ( i = 1 ; i < n ; i += 2 ) {
		if ( ( x[ i ] - '0' ) != u ) { return false ; }
	}
	int p = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		p = p * 10 + ( x[ i ] - '0' ) ;
		p %= m ;
	}
	if ( p != 0 ) { return false ; } 
	return true ;
}

long long get ( string x ) {
	int i , j , t , k ;
	for ( i = 0 ; i < 2 ; i ++ ) {
		for ( j = 0 ; j <= m ; j ++ ) {
			for ( t = 0 ; t < 2 ; t ++ ) {
				dp[ i ][ j ][ t ] = 0 ;
			}
		}
	}
	int prv = 0 ;
	int cur = 1 ;
	for ( i = 1 ; i < 10 ; i ++ ) {
		if ( i > ( x[ 0 ] - '0' ) ) { break ; }
		if ( i == u ) { continue ; }
		if ( i == ( x[ 0 ] - '0' ) ) {
			dp[ prv ][ ( i % m ) ][ 1 ] ++ ;
			break ;
		}
		dp[ prv ][ ( i % m ) ][ 0 ] ++ ;
	}
	for ( i = 1 ; i < n ; i ++ ) {
		for ( j = 0 ; j < m ; j ++ ) {
			for ( t = 0 ; t < 2 ; t ++ ) {
				if ( dp[ prv ][ j ][ t ] == 0 ) { continue ; }
				if ( i % 2 == 1 ) {
					int val = 10 * j + u ;
					val %= m ;
					if ( t == 0 ) {
						dp[ cur ][ val ][ 0 ] += dp[ prv ][ j ][ t ] ; 
						dp[ cur ][ val ][ 0 ] %= MOD ;
					}
					else {
						if ( u < ( x[ i ] - '0' ) ) {
							dp[ cur ][ val ][ 0 ] += dp[ prv ][ j ][ t ] ;
							dp[ cur ][ val ][ 0 ] %= MOD ;
						}
						if ( u == ( x[ i ] - '0' ) ) {
							dp[ cur ][ val ][ 1 ] += dp[ prv ][ j ][ t ] ;
							dp[ cur ][ val ][ 1 ] %= MOD ;
						}
					}
				}
				else {
					for ( k = 0 ; k < 10 ; k ++ ) {
						if ( k == u ) { continue ; }
						int val = 10 * j + k ;
						val %= m ;
						if ( t == 0 ) {
							dp[ cur ][ val ][ 0 ] += dp[ prv ][ j ][ t ] ; 
							dp[ cur ][ val ][ 0 ] %= MOD ;
						}
						else {
							if ( k < ( x[ i ] - '0' ) ) {
								dp[ cur ][ val ][ 0 ] += dp[ prv ][ j ][ t ] ;
								dp[ cur ][ val ][ 0 ] %= MOD ;
							}
							if ( k == ( x[ i ] - '0' ) ) {
								dp[ cur ][ val ][ 1 ] += dp[ prv ][ j ][ t ] ;
								dp[ cur ][ val ][ 1 ] %= MOD ;
							}
						}
					}
				}
			}
		}
		for ( j = 0 ; j < m ; j ++ ) {
			for ( t = 0 ; t < 2 ; t ++ ) {
				dp[ prv ][ j ][ t ] = 0 ;
			}
		}
		cur ^= 1 ;
		prv ^= 1 ; 
	}
	return ( ( dp[ prv ][ 0 ][ 0 ] + dp[ prv ][ 0 ][ 1 ] ) % MOD ) ;
}


void input ( ) {
	cin >> m >> u ;
	cin >> st ;
	cin >> en ;
	n = st.size ( ) ;
}

void solve ( ) {
	long long ans = get ( en ) - get ( st ) ;
	if ( g ( st ) == true ) { ans ++ ; }
	if ( ans < 0 ) { ans += MOD ; }
	if ( ans >= MOD ) { ans -= MOD ; }
	cout << ans << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}