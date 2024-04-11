#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
pair < int , int > tr[ 5 * MAXN ] ;
int LEAVES ;
long long dp[ MAXN ] ;

void update ( int where , int val1 , int val2 ) {
	tr[ where ] = make_pair ( val1 , val2 ) ;
    where /= 2 ;
    while ( where != 0 ) {
    	if ( tr[ 2 * where ].first >= tr[ 2 * where + 1 ].first ) { tr[ where ] = tr[ 2 * where ] ; }
        else { tr[ where ] = tr[ 2 * where + 1 ] ; }
        where /= 2 ;
    }
}

int query ( int where , int IL , int IR , int CURL , int CURR ) {
	if ( IL > IR ) { return 0 ; }
    if ( IR < CURL || CURR < IL ) { return 0 ; }
    if ( CURL <= IL && IR <= CURR ) { return tr[ where ].second ; }
    int mid = ( IL + IR ) / 2 ;
    int u1 = query ( 2 * where , IL , mid , CURL , CURR ) ;
    int u2 = query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
	if ( u1 == 0 ) { return u2 ; }
    if ( u2 == 0 ) { return u1 ; }
	if ( a[ u1 ] >= a[ u2 ] ) { return u1 ; }
  	return u2 ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i < n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    a[ n ] = n ;
}

void solve ( ) {
	int i ;
    LEAVES = 1 ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
    dp[ n ] = 0 ;
    update ( LEAVES + n - 1 , a[ n ] , n ) ;
    for ( i = n - 1 ; i >= 1 ; i -- ) {
    	int id = query ( 1 , 1 , LEAVES , i + 1 , a[ i ] ) ;
        dp[ i ] = ( n - i ) + dp[ id ] - ( a[ i ] - id ) ;
        update ( LEAVES + i - 1 , a[ i ] , i ) ;
    }
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	ans += dp[ i ] ;
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