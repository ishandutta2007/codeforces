#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 300007

int n , k ;
int a[ MAXN ] ;
int diff[ MAXN ] ;
int len[ MAXN ] ;
int br1 , br2 ;
int g1 , g2 ;
map < pair < int , int > , long long > ZX ;

long long dp[ 2 ][ 5007 ] ;

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d" , &n , &k ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
	sort ( a + 1 , a + n + 1 ) ;
	for ( i = 1 ; i < n ; i ++ ) {
		diff[ i ] = a[ i + 1 ] - a[ i ] ;
    }
	
}

void solve ( ) {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) { len[ i ] = 1 ; }
	for ( i = n ; i >= k + 1 ; i -- ) {
		len[ i - k ] = len[ i ] + 1 ; 
    }
	br1 = br2 = 0 ;
	for ( i = 1 ; i <= k ; i ++ ) {
		if ( len[ i ] == len[ 1 ] ) { br1 ++ ; g1 = len[ i ] ; }
		else { br2 ++ ; g2 = len[ i ] ; }
    }
	dp[ 0 ][ 0 ] = 0 ;
	int pos ;
	int prev = 0 , cur = 1 ;
	for ( i = 0 ; i <= br1 ; i ++ ) {
		for ( j = 0 ; j <= br2 ; j ++ ) {
			pos = i * g1 + j * g2 ;
			if ( i != br1 ) {
				dp[ cur ][ j ] = max ( dp[ cur ][ j ] , dp[ prev ][ j ] + diff[ pos ] ) ;
            }
			if ( j != br2 ) {
				dp[ prev ][ j + 1 ] = max ( dp[ prev ][ j + 1 ] , dp[ prev ][ j ] + diff[ pos ] ) ;
            }
        }
		if ( i == br1 ) { break ; }
		prev ^= 1 ;
		cur ^= 1 ;
		for ( j = 0 ; j <= br2 ; j ++ ) {
			dp[ cur ][ j ] = 0 ;
        }
    }
	long long sm = 0 ;
	for ( i = 1 ; i < n ; i ++ ) {
		sm += diff[ i ] ;
    }
	printf ( "%I64d\n" , sm - dp[ prev ][ br2 ] ) ;
}