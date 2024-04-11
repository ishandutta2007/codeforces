#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std ;

#define MAXN 100007
#define inf 1000000007
int n , k ;
int a[ MAXN ] ;
int prv[ MAXN ] ;
int nxt[ MAXN ] ;
map < int , int > ZX ;

int LEAVES = 1 ;
int tr[ 6 * MAXN ] ;

void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
	if ( IL > IR ) { return ; }
	if ( IR < CURL || CURR < IL ) { return ; }
	if ( CURL <= IL && IR <= CURR ) {
    	tr[ where ] = max ( tr[ where ] , val ) ;
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    update ( 2 * where , IL , mid , CURL , CURR , val ) ;
    update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
}

int query ( int where ) {
	int ret = -inf ;
    while ( where != 0 ) {
    	ret = max ( ret , tr[ where ] ) ;
        where /= 2 ;
    }
    return ret ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
    int i ;
   	for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
        if ( ZX.find ( a[ i ] ) != ZX.end ( ) ) {
        	int u = ZX[ a[ i ] ] ;
            nxt[ u ] = i ;
            prv[ i ] = u ;
        }
        ZX[ a[ i ] ] = i ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( nxt[ i ] == 0 ) { nxt[ i ] = n + 1 ; }
    }
}

void solve ( ) {
	int i ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
    for ( i = 1 ; i <= 2 * LEAVES ; i ++ ) {
    	tr[ i ] = -inf ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	int lst = nxt[ i ] - k ;
        int st = prv[ i ] + 1 ;
        if ( st < ( i - k  + 1 ) ) { st = i - k + 1 ; }
        if ( lst > i ) { lst = i ; }
        if ( lst >= prv[ i ] + 1 ) {
        	update ( 1 , 1 , LEAVES , st , lst , a[ i ] ) ;
        }
    }
    for ( i = 1 ; i <= ( n - k + 1 ) ; i ++ ) {
    	int ans = query ( LEAVES + i - 1 ) ;
        if ( ans == -inf ) { printf ( "Nothing\n" ) ; }
        else { printf ( "%d\n" , ans ) ; }
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}