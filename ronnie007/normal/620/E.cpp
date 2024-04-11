#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std ;

#define MAXN 400007

int n , m ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;

vector < int > ord ;

long long pw[ MAXN ] ;

long long tr[ 6 * MAXN ] ;
long long lazy[ 6 * MAXN ] ;
int st[ MAXN ] ;
int en[ MAXN ] ;
int LEAVES ;


void dfs ( int vertex , int par ) {
	ord.push_back ( vertex ) ;
    st[ vertex ] = ord.size ( ) ;
    int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	if ( v[ vertex ][ i ] == par ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
    ord.push_back ( vertex ) ;
    en[ vertex ] = ord.size ( ) ;
}

void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
	if ( IL > IR ) { return ; }
    if ( lazy[ where ] != 0 ) {
    	tr[ where ] = lazy[ where ] ;
        if ( where < LEAVES ) {
        	lazy[ 2 * where ] = lazy[ where ] ;
            lazy[ 2 * where + 1 ] = lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
	if ( IR < CURL || CURR < IL ) { return ; }
    if ( CURL <= IL && IR <= CURR ) {
    	tr[ where ] = pw[ val ] ;
        if ( where < LEAVES ) {
        	lazy[ 2 * where ] = pw[ val ] ;
            lazy[ 2 * where + 1 ] = pw[ val ] ;
        }
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    update ( 2 * where , IL , mid , CURL , CURR , val ) ;
    update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
    tr[ where ] = ( tr[ 2 * where ] | tr[ 2 * where + 1 ] ) ;
}

long long query ( int where , int IL , int IR , int CURL , int CURR ) {
	if ( IL > IR ) { return 0 ; }
    if ( lazy[ where ] != 0 ) {
    	tr[ where ] = lazy[ where ] ;
        if ( where < LEAVES ) {
        	lazy[ 2 * where ] = lazy[ where ] ;
            lazy[ 2 * where + 1 ] = lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
	if ( IR < CURL || CURR < IL ) { return 0 ; }
    if ( CURL <= IL && IR <= CURR ) {
        return tr[ where ] ;
    }
    int mid = ( IL + IR ) / 2 ;
    long long ret = 0 ;
    ret |= query ( 2 * where , IL , mid , CURL , CURR ) ;
    ret |= query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    tr[ where ] = ( tr[ 2 * where ] | tr[ 2 * where + 1 ] ) ;
    return ret ;
}

int f ( long long x ) {
	int i ;
    int ret = 0 ;
    for ( i = 60 ; i >= 0 ; i -- ) {
    	if ( x >= pw[ i ] ) {
        	ret ++ ;
            x -= pw[ i ] ;
        }
    }
    return ret ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
        a[ i ] -- ;
    }
    int x , y ; 
    for ( i = 1 ; i < n ; i ++ ) {
    	scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
	int i ;
    pw[ 0 ] = 1 ;
    for ( i = 1 ; i <= 61 ; i ++ ) {
    	pw[ i ] = 2 * pw[ i - 1 ] ;
    }
    dfs ( 1 , -1 ) ;
    LEAVES = 1 ;
    while ( LEAVES < 2 * n ) { LEAVES *= 2 ; }
    for ( i = 1 ; i <= 2 * n ; i ++ ) {
    	update ( 1 , 1 , LEAVES , i , i , a[ ord[ i - 1 ] ] ) ;
    }
    int x , y , z ;
    while ( m != 0 ) {
    	m -- ;
    	scanf ( "%d" , &x ) ;
        if ( x == 1 ) {
        	scanf ( "%d%d" , &y , &z ) ;
            z -- ;
            update ( 1 , 1 , LEAVES , st[ y ] , en[ y ] , z ) ;
        }
        else {
        	scanf ( "%d" , &y ) ;
            long long cur = query ( 1 , 1 , LEAVES , st[ y ] , en[ y ] ) ;
			printf ( "%d\n" , f ( cur ) ) ;
        }
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}