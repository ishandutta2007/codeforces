#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

long long MOD ;

int n , m ;
string a ;
int br[ 507 ] ; 
long long dp[ 2 ][ 507 ][ 507 ] ;


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
	cin >> n >> m >> MOD ;
	int i , j ;
	int r ;
	for ( i = 0 ; i < m ; i ++ ) {
		cin >> a ;
		r = 0 ;
		for ( j = 0 ; j < n ; j ++ ) {
			if ( a[ j ] == '0' ) continue ;
			r ++ ;
			br[ j ] ++ ;
			if ( br[ j ] > 2 ) {
				printf ( "0\n" ) ;
				exit ( 0 ) ;
            }
		}
		if ( r != 2 ) {
			printf ( "0\n" ) ;
			exit ( 0 ) ;
        }
    }
	//printf ( "HERE\n" ) ;
}

void solve ( )  {
	long long p , q ;
	long long i , j , t ;
	p = 0 ;
	q = 0 ;
	int prev = 0 ;
	int cur = 1 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( br[ i ] == 0 ) {
			p ++ ;
		}
		if ( br[ i ] == 1 ) {
			q ++ ;
        }
    }
	//printf ( "%d %d\n" , p , q ) ;
	dp[ prev ][ p ][ q ] = 1 ;
	for ( i = 0 ; i < n - m ; i ++ ) {
		for ( j = 0 ; j <= p ; j ++ ) {
			for ( t = 0 ; t <= n ; t ++ ) {
				//printf ( "dp[ %d ][ %d ][ %d ] = %d\n" , i , j , t , dp[ prev ][ j ][ t ] ) ;
				if ( dp[ prev ][ j ][ t ] == 0 ) continue ;
				if ( j >= 2 ) {
					dp[ cur ][ j - 2 ][ t + 2 ] = ( dp[ cur ][ j - 2 ][ t + 2 ] + ( ( j * ( j - 1 ) ) / 2 ) * dp[ prev ][ j ][ t ] ) % MOD ;
                }
				if ( j >= 1 && t >= 1 ) {
					dp[ cur ][ j - 1 ][ t ] = ( dp[ cur ][ j - 1 ][ t ] + j * t * dp[ prev ][ j ][ t ] ) % MOD ;
                }
				if ( t >= 2 ) {
                    dp[ cur ][ j ][ t - 2 ] = ( dp[ cur ][ j ][ t - 2 ] + ( ( t * ( t - 1 ) ) / 2 ) * dp[ prev ][ j ][ t ] ) % MOD ;
                }
				dp[ prev ][ j ][ t ] = 0 ;
            }
        }
		prev ^= 1 ;
		cur ^= 1 ;
    }
	printf ( "%I64d\n" , dp[ prev ][ 0 ][ 0 ] ) ;
}