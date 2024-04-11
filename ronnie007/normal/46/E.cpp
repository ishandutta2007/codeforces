#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std ;

#define MAXN 1507
#define inf 1000000007

int n , m ;
int a[ MAXN ][ MAXN ] ;
int pref[ MAXN ][ MAXN ] ;

int LEAVES = 1 ;
long long tr[ 6 * MAXN ] ;
long long dp[ MAXN ] ;

long long query ( int where , int IL , int IR , int CURL , int CURR ) {
	if ( IL > IR ) { return -inf ; }
    if ( IR < CURL || CURR < IL ) { return -inf ; }
    if ( CURL <= IL && IR <= CURR ) {
    	return tr[ where ] ;
    }
    int mid = ( IL + IR ) / 2;
    long long ret = query ( 2 * where , IL , mid , CURL , CURR ) ;
    ret = max ( ret , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    return ret ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= m ; j ++ ) {
        	scanf ( "%d" , &a[ i ][ j ] ) ;
            pref[ i ][ j ] = ( pref[ i ][ j - 1 ] + a[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
	int i , j ;
   	while ( LEAVES < m ) { LEAVES *= 2 ; }
    long long ans ;
    for ( i = 1 ; i <= 2 * LEAVES ; i ++ ) { tr[ i ] = -inf ; }
    for ( i = 1 ; i <= m ; i ++ ) {
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= m ; j ++ ) {
        	if ( i != 1 ) {
	        	if ( ( i % 2 ) == 1 ) {
    	        	dp[ j ] = query ( 1 , 1 , LEAVES , 1 , j - 1 ) ;
        	    }
            	else {
            		dp[ j ] = query ( 1 , 1 , LEAVES , j + 1 , m ) ;
	            }
			}
            dp[ j ] += pref[ i ][ j ] ;
            if ( i == n ) {
            	if ( j == 1 || ans < dp[ j ] ) { ans = dp[ j ] ; }
            }
        }
        for ( j = 1 ; j <= m ; j ++ ) {
        	tr[ LEAVES + j - 1 ] = dp[ j ] ;
        }
        for ( j = LEAVES - 1 ; j >= 1 ; j -- ) {
        	tr[ j ] = max ( tr[ 2 * j ] , tr[ 2 * j + 1 ] ) ;
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}