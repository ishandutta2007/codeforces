#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std ;

#define MAXN 100007
#define inf 1000000007

int n ;
int a[ MAXN ] ;

int LEAVES ;
int tr[ 5 * MAXN ] ;
int lazy[ 5 * MAXN ] ;

void init ( int where , int val ) {
	while ( where != 0 ) {
    	tr[ where ] = min ( tr[ where ] , val ) ;
        where /= 2 ;
    }
}

void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
	if ( IR < IL ) { return ; }
    if ( lazy[ where ] != 0 ) {
    	tr[ where ] -= lazy[ where ] ;
        if ( where < LEAVES ) {
        	lazy[ 2 * where ] += lazy[ where ];
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    if ( IR < CURL || CURR < IL ) { return ; }
    if ( CURL <= IL && IR <= CURR ) {
		tr[ where ] -= val ;
        if ( where < LEAVES ) {
        	lazy[ 2 * where ] += val ;
            lazy[ 2 * where + 1 ] += val ;
        }
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
	update ( 2 * where , IL , mid , CURL , CURR , val ) ;
    update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
    tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
}

int query ( int where , int IL , int IR , int CURL , int CURR ) {
	if ( IR < IL ) { return inf ; }
    if ( lazy[ where ] != 0 ) {
    	tr[ where ] -= lazy[ where ] ;
        if ( where < LEAVES ) {
        	lazy[ 2 * where ] += lazy[ where ];
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    if ( IR < CURL || CURR < IL ) { return inf ; }
    if ( CURL <= IL && IR <= CURR ) {
		return tr[ where ] ;
    }
    int mid = ( IL + IR ) / 2 ;
    int ret = inf ;
	ret = min ( ret , query ( 2 * where , IL , mid , CURL , CURR ) ) ;
    ret = min ( ret , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    return ret ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
	LEAVES = 1 ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
    int i , j ;
    for ( i = 0 ; i <= 2 * LEAVES ; i ++ ) { tr[ i ] = inf ; }
    for ( i = 1 ; i <= n ; i ++ ) {
    	init ( LEAVES + i - 1 , a[ i ] ) ;
    }
    vector < pair < int , int > > v ;
    for ( i = 1 ; i <= n ; i ++ ) {
        while ( 1 ) {
	    	if ( query ( 1 , 1 , LEAVES , i , i ) == 0 ) { break ; }
	    	int l , r , mid ;
			l = i ;
        	r = n ;
	        while ( r - l > 3 ) {
    	    	int mid = ( l + r ) / 2 ;
        	    if ( query ( 1 , 1 , LEAVES , i , mid ) != 0 ) { l = mid ; }
                else { r = mid ; }
	        }
            while ( query ( 1 , 1 , LEAVES , i , r ) == 0 ) { r -- ; }
            int val = query ( 1 , 1 , LEAVES , i , r ) ;
            update ( 1 , 1 , LEAVES , i , r , val ) ;
            while ( val != 0 ) {
            	val -- ;
                v.push_back ( make_pair ( i , r ) ) ;
            }
		}
    }
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	printf ( "%d %d\n" , v[ i ].first , v[ i ].second ) ;
    }
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}