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

int n , k ;
long long MOD ;

long long dp[ 1007 ][ 107 ][ 2 ] ; 
long long p[ 1007 ] ; 

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
	scanf ( "%d%d%I64d" , &n , &k , &MOD ) ;
}
 
void solve ( )  {
	int i , j , t , e , z ;
	p[ 0 ] = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		p[ i ] = p[ i - 1 ] * 10 ;
		p[ i ] %= k ;
    }
	dp[ 0 ][ 0 ][ 0 ] = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( t = 0 ; t < 10 ; t ++ ) {
			if ( i == n && t == 0 ) { continue ; } 
			for ( j = 0 ; j < k ; j ++ ) {
				int nx = ( j + p[ i - 1 ] * t ) % k ;
				dp[ i ][ nx ][ 1 ] += dp[ i - 1 ][ j ][ 1 ] ;
				if ( nx == 0 && t != 0 ) {
					dp[ i ][ nx ][ 1 ] += dp[ i - 1 ][ j ][ 0 ] ; 
                }
				else {
					dp[ i ][ nx ][ 0 ] += dp[ i - 1 ][ j ][ 0 ] ;
                }
				dp[ i ][ nx ][ 0 ] %= MOD ;
				dp[ i ][ nx ][ 1 ] %= MOD ;
            }
        }
    }
	long long ans = 0 ; 
	for ( i = 0 ; i < k ; i ++ ) {
		ans += dp[ n ][ i ][ 1 ] ;
		ans %= MOD ;
    }
	printf ( "%I64d\n" , ans  ) ;
}