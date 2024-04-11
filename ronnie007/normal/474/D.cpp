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
using namespace std ;

#define MOD 1000000007

int n , k ; 

long long dp[ 200007 ] ; 
long long pr[ 200007 ] ;

void input ( ) ;
void solve ( ) ;



int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> n >> k ;
	
}
 
void solve ( )  {
	dp[ 0 ] = 1 ;
	int i ;
	for ( i = 1 ; i <= 100700 ; i ++ ) {
		dp[ i ] = dp[ i - 1 ] ;
		if ( i - k >= 0 ) dp[ i ] += dp[ i - k ] ; 
		dp[ i ] %= MOD ;
	}
	pr[ 0 ] = 0 ; 
	for ( i = 1 ; i <= 100700 ; i ++ ) {
		pr[ i ] = pr[ i - 1 ] + dp[ i ] ;
		pr[ i ] %= MOD ;
	}
	int x , y ; 
	long long p ;
	while ( n > 0 ) {
		cin >> x >> y ; 
		p = pr[ y ] - pr[ x - 1 ] ;
		while ( p < 0 ) p += MOD ;
		cout << p << "\n" ;
		n -- ;
	}
}