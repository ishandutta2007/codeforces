#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MOD 1000000007
#define MAXN 1007
#define OFFSET 10000
int n ;
int a[ MAXN ] ;
int dp[ MAXN ][ 3 * OFFSET ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
	dp[ 0 ][ OFFSET ] = 1 ;
    int i , j ;
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = a[ i ] ; j <= 2 * OFFSET ; j ++ ) {
        	dp[ i ][ j ] = ( dp[ i ][ j ] + dp[ i - 1 ][ j - a[ i ] ] ) % MOD ;
        }
        for ( j = 0 ; j + a[ i ] <= 2 * OFFSET ; j ++ ) {
        	dp[ i ][ j ] = ( dp[ i ][ j ] + dp[ i - 1 ][ j + a[ i ] ] ) % MOD ;        
        }
		ans = ( ans + dp[ i ][ OFFSET ] ) % MOD ;
        dp[ i ][ OFFSET ] ++ ;
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