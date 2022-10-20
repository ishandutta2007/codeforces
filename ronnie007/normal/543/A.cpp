#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 507

int n , m ;
int b , MOD ;
int a[ MAXN ] ;
int dp[ 2 ][ MAXN ][ MAXN ] ;

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
	scanf ( "%d%d%d%d" , &m , &n , &b , &MOD ) ;
	int i ;
	a[ 0 ] = 507 ;
	a[ m + 1 ] = 507 ;
	for ( i = 1 ; i <= m ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( )  {
	int i , j , t ;
	int prev = 0 ;
	int cur = 1 ; 
	for ( i = 1 ; i <= m ; i ++ ) {
		dp[ 0 ][ i ][ a[ i ] ] = 1 ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 0 ; j <= m ; j ++ ) {
			for ( t = 0 ; t <= b ; t ++ ) {
				if ( dp[ prev ][ j ][ t ] == 0 ) { continue ; }
				//printf ( "dp[ %d ][ %d ][ %d ] = %d\n" , i , j , t , dp[ prev ][ j ][ t ] ) ;
				if ( t + a[ j ] <= b ) {
					dp[ cur ][ j ][ t + a[ j ] ] += dp[ prev ][ j ][ t ] ;
					dp[ cur ][ j ][ t + a[ j ] ] %= MOD ;
                }
				/**
				if ( t + a[ j + 1 ] <= b ) {
					dp[ cur ][ j + 1 ][ t + a[ j + 1 ] ] += dp[ prev ][ j ][ t ] ;
					dp[ cur ][ j + 1 ][ t + a[ j + 1 ] ] %= MOD ;
                }
				**/
				dp[ prev ][ j + 1 ][ t ] += dp[ prev ][ j ][ t ] ;
				dp[ prev ][ j + 1 ][ t ] %= MOD ;
            }
        }
		if ( i == n ) { break ; }
		prev ^= 1 ;
		cur ^= 1 ;
		for ( j = 0 ; j <= m ; j ++ ) {
			for ( t = 0 ; t <= b ; t ++ ) {
				dp[ cur ][ j ][ t ] = 0 ;
            }
        }
    }
	int ans = 0 ;
	for ( i = 0 ; i <= b ; i ++ ) {
		ans += dp[ prev ][ m ][ i ] ;
		ans %= MOD ;
    }
	printf ( "%d\n" , ans ) ;
}