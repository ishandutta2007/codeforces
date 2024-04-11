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


int n ;
int a , b ;
int k ;

int dp[ 2 ][ 5007 ] ;

int pref[ 5007 ] ;

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
	scanf ( "%d%d%d%d" , &n , &a , &b , &k ) ;
}


void solve ( ) {
	int sz ;
	int st ;
	if ( a > b ) {
		sz = n - b ;
		st = a - b ;
    }
	else {
		sz = b - 1 ;
		st = b - a ; 
    }
	n = sz ;
	int prev = 0 ;
	int cur = 1 ;
	dp[ prev ][ st ] = 1 ;
	int i , j ; 
	for ( i = 1 ; i <= n ; i ++ ) {
		pref[ i ] = pref[ i - 1 ] + dp[ prev ][ i ] ; 
	}
	//printf ( "%d %d\n" , n , st ) ;
	for ( i = 1 ; i <= k ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			int d = j / 2 + 1 ;
			
			int sm = ( MOD + pref[ n ] - pref[ d - 1 ] ) % MOD ;
			sm = ( sm + MOD - dp[ prev ][ j ] ) % MOD ;
			dp[ cur ][ j ] = sm ;
			//printf ( "dp[ %d ][ %d ] = %d\n" , i , j , dp[ cur ][ j ] ) ;
        }
		for ( j = 1 ; j <= n ; j ++ ) {
			pref[ j ] = ( pref[ j - 1 ] + dp[ cur ][ j ] ) % MOD ;
        }
		cur ^= 1 ;
		prev ^= 1 ;
    }
	int ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		ans = ( ans + dp[ prev ][ i ] ) % MOD ;
    }
	printf ( "%d\n" , ans ) ;
}