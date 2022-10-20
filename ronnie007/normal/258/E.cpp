#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
using namespace std ;

#define MAXN 100007

int n , m ;
vector < int > v[ MAXN ] ;

vector < int > ord ;
int l[ MAXN ] ;
int r[ MAXN ] ;

pair < int , int > tr[ 5 * MAXN ] ;
int LEAVES = 1 ;
int ans[ MAXN ] ;
vector < pair < int , int > > toadd[ MAXN ] ;

void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
	if ( IL > IR ) { return ; }
    if ( IR < CURL || CURR < IL ) { return ; }
    if ( CURL <= IL && IR <= CURR ) {
    	tr[ where ].second += val ;
        if ( tr[ where ].second == 0 ) {
        	tr[ where ].first = 0 ;
            if ( where < LEAVES ) {
            	tr[ where ].first = tr[ 2 * where ].first + tr[ 2 * where + 1 ].first ;
            }
		}
        else { tr[ where ].first = ( IR - IL + 1 ) ; }
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    update ( 2 * where , IL , mid , CURL , CURR , val ) ;
    update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
    tr[ where ].first = tr[ 2 * where ].first + tr[ 2 * where + 1 ].first ;
    if ( tr[ where ].second != 0 ) { tr[ where ].first = ( IR - IL + 1 ) ; }
}

void dfs ( int vertex , int par ) {
	ord.push_back ( vertex ) ;
    l[ vertex ] = ord.size ( ) ;
	int i ;
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	if ( v[ vertex ][ i ] == par ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
    r[ vertex ] = ord.size ( ) ;
}

void calc ( int vertex , int par ) {
	int i ;
    int sz = toadd[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	update ( 1 , 1 , LEAVES , toadd[ vertex ][ i ].first , toadd[ vertex ][ i ].second , 1 ) ;
    }
    ans[ vertex ] = tr[ 1 ].first ;
    if ( ans[ vertex ] != 0 ) { ans[ vertex ] -- ; }
    sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	if ( v[ vertex ][ i ] == par ) { continue ; }
        calc ( v[ vertex ][ i ] , vertex ) ;
    }
    sz = toadd[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	update ( 1 , 1 , LEAVES , toadd[ vertex ][ i ].first , toadd[ vertex ][ i ].second , -1 ) ;
    }    
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    int i ;
    int x , y ;
    for ( i = 1 ; i < n ; i ++ ) {
    	scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
	dfs ( 1 , -1 ) ;
    int i , j ;
    for ( i = 1 ; i <= m ; i ++ ) {
    	int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        toadd[ x ].push_back ( make_pair ( l[ x ] , r[ x ] ) ) ;
		toadd[ x ].push_back ( make_pair ( l[ y ] , r[ y ] ) ) ;

        toadd[ y ].push_back ( make_pair ( l[ x ] , r[ x ] ) ) ;
		toadd[ y ].push_back ( make_pair ( l[ y ] , r[ y ] ) ) ;        
    }
    LEAVES = 1 ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
    for ( i = 0 ; i <= 2 * LEAVES ; i ++ ) {
    	tr[ i ].first = tr[ i ].second = 0 ;
    }
    calc ( 1 , -1 ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	printf ( "%d" , ans[ i ] ) ;
        if ( i == n ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}