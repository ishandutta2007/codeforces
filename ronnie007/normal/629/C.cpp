#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

#define MOD 1000000007
#define MAXN 2007

int m , n ;
string a ;

int lw , enb ;

int dp[ MAXN ][ MAXN ][ 2 ] ;

void input ( ) {
	cin >> m >> n ;
	cin >> a; 
	int i ;
	lw = enb = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == '(' ) { enb ++ ; }
		else { enb -- ; }
		if ( lw > enb ) { lw = enb ; }
	}
}

void solve ( ) {
	int sz = ( m - n ) ;
	dp[ 0 ][ 0 ][ 0 ] = 1 ;
	int i , j , t ;
	int st , en , diff ;
	if ( abs ( enb ) > 2000 ) { printf ( "0\n" ) ; return ; }
	if ( enb < 0 ) { st = sz ; en = 0 ; diff = -1 ; }
	else { st = 0 ; en = sz ; diff = 1 ; }
	for ( i = 0 ; i <= sz ; i ++ ) {
		for ( j = st ; j != -1337 ; j += diff ) {
			for ( t = 0 ; t < 2 ; t ++ ) {
				if ( dp[ i ][ j ][ t ] == 0 ) { continue ; }
				//printf ( "dp[ %d ][ %d ][ %d ] = %d\n" , i , j , t , dp[ i ][ j ][ t ] ) ;
				if ( t == 0 ) {
					dp[ i + 1 ][ j + 1 ][ t ] += dp[ i ][ j ][ t ] ;
					dp[ i + 1 ][ j + 1 ][ t ] %= MOD ;
					if ( j != 0 ) {
						dp[ i + 1 ][ j - 1 ][ t ] += dp[ i ][ j ][ t ] ;
						dp[ i + 1 ][ j - 1 ][ t ] %= MOD ;
					}
					if ( j + lw >= 0 ) {
						dp[ i ][ j + enb ][ 1 ] += dp[ i ][ j ][ t ] ;
						dp[ i ][ j + enb ][ 1 ] %= MOD ;
					}
				}
				else {
					dp[ i + 1 ][ j + 1 ][ t ] += dp[ i ][ j ][ t ] ;
					dp[ i + 1 ][ j + 1 ][ t ] %= MOD ;
					if ( j != 0 ) {
						dp[ i + 1 ][ j - 1 ][ t ] += dp[ i ][ j ][ t ] ;
						dp[ i + 1 ][ j - 1 ][ t ] %= MOD ;
					}
				}
			}
			if ( j == en ) { break ; }
		}
	}
	printf ( "%d\n" , dp[ sz ][ 0 ][ 1 ] ) ;
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}