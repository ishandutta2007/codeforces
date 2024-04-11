#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

#define MOD 1000000007
#define MAXN 5007


int n ;
string a ;
int dp[ MAXN ][ MAXN ] ;
int f[ MAXN ][ MAXN ] ;
int pref[ MAXN ][ MAXN ] ;

void input ( ) {
	cin >> n ;
	cin >> a ;
	a = '#' + a ;
}

void solve ( ) {
	int i , j ; 
	for ( i = n ; i >= 1 ; i -- ) {
		for ( j = n ; j >= 1 ; j -- ) {
			if ( a[ i ] != a[ j ] ) { f[ i ][ j ] = 0 ; }
			else { f[ i ][ j ] = 1 + f[ i + 1 ][ j + 1 ] ; }
		}
	}
	for ( j = 1 ; j <= n ; j ++ ) {
		for ( i = 1 ; i <= j ; i ++ ) {
			pref[ j ][ i ] = pref[ j ][ i - 1 ] ;
			if ( a[ i ] == '0' ) { dp[ i ][ j ] = 0 ; continue ; }
			if ( i == 1 ) { dp[ i ][ j ] = 1 ; pref[ j ][ i ] ++ ; continue ; }
			int id = i - 1 - ( j - i ) ;
			if ( id > 0 ) {
				int u = f[ id ][ i ] ;
				if ( i + u <= j && a[ i + u ] > a[ id + u ] ) {
					dp[ i ][ j ] += dp[ id ][ i - 1 ] ;
					dp[ i ][ j ] %= MOD ;
				}
			}
			else { id = 0 ; }
			dp[ i ][ j ] += ( MOD + pref[ i - 1 ][ i - 1 ] - pref[ i - 1 ][ id ] ) % MOD ;
			dp[ i ][ j ] %= MOD ;
			//printf ( "dp[ %d ][ %d ] = %d\n" , i , j , dp[ i ][ j ] ) ;
			pref[ j ][ i ] += dp[ i ][ j ] ;
			pref[ j ][ i ] %= MOD ;
			//printf ( "--pref[ %d ][ %d ] = %d\n" , j , i , pref[ j ][ i ] ) ;
		}
	}
	int ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		ans += dp[ i ][ n ] ;
		ans %= MOD ;
	}
	printf ( "%d\n" , ans ) ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}