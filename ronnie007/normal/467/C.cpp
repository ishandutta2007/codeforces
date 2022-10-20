#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std ;


int n , m , k ;
long long a[ 5007 ] ;
long long pr[ 5007 ] ; 
long long dp[ 5007 ][ 5007 ] ; 

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
	cin >> n >> m >> k ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ] ; 
	}
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		pr[ i ] = pr[ i - 1 ] + a[ i ] ; 
	}
	//dp[ 0 ][ 0 ] = 1 ;
	for ( i = m ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= k ; j ++ ) {
			dp[ i ][ j ] = dp[ i - 1 ][ j ] ;
			if ( dp[ i ][ j ] < dp[ i - m ][ j - 1 ] + ( pr[ i ] - pr[ i - m ] ) ) {
				dp[ i ][ j ] = dp[ i - m ][ j - 1 ] + ( pr[ i ] - pr[ i - m ] ) ;
			}
		}
	}
	cout << dp[ n ][ k ] << "\n" ; 
}