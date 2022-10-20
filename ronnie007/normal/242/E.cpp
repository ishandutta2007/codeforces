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

int tr[ 3 * MAXN ][ 21 ] ;
int lazy[ 3 * MAXN ][ 21 ] ;
int LEAVES ;

void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
	if ( IL > IR ) { return ; }
	int i ;
    for ( i = 0 ; i < 20 ; i ++ ) {
    	if ( lazy[ where ][ i ] != 0 ) {
        	tr[ where ][ i ] = ( IR - IL + 1 ) - tr[ where ][ i ] ;
            if ( where < LEAVES ) {
            	lazy[ 2 * where ][ i ] += lazy[ where ][ i ] ;
                lazy[ 2 * where ][ i ] %= 2 ;
            	lazy[ 2 * where + 1 ][ i ] += lazy[ where ][ i ] ;
                lazy[ 2 * where + 1 ][ i ] %= 2 ;
            }
            lazy[ where ][ i ] = 0 ;
        }
    }
    if ( CURR < IL || IR < CURL ) { return ; }
    if ( CURL <= IL && IR <= CURR ) {
        for ( i = 0 ; i < 20 ; i ++ ) {
        	if ( (val&(1<<i)) != 0 ) {
            	tr[ where ][ i ] = ( IR - IL + 1 ) - tr[ where ][ i ] ;
                if ( where < LEAVES ) {
	            	lazy[ 2 * where ][ i ] ++ ;
    	            lazy[ 2 * where ][ i ] %= 2 ;
        	    	lazy[ 2 * where + 1 ][ i ] ++ ;
            	    lazy[ 2 * where + 1 ][ i ] %= 2 ;
                }
            }
        }
        return ;
    }
    int mid = ( IL + IR ) / 2 ;
    update ( 2 * where , IL , mid , CURL , CURR , val ) ;
    update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
    for ( i = 0 ; i < 20 ; i ++ ) {
    	tr[ where ][ i ] = tr[ 2 * where ][ i ] + tr[ 2 * where + 1 ][ i ] ;
    }
}

long long query ( int where , int IL , int IR , int CURL , int CURR ) {
	if ( IL > IR ) { return 0 ; }
    int i ;
    for ( i = 0 ; i < 20 ; i ++ ) {
    	if ( lazy[ where ][ i ] != 0 ) {
        	tr[ where ][ i ] = ( IR - IL + 1 ) - tr[ where ][ i ] ;
            if ( where < LEAVES ) {
            	lazy[ 2 * where ][ i ] += lazy[ where ][ i ] ;
                lazy[ 2 * where ][ i ] %= 2 ;
            	lazy[ 2 * where + 1 ][ i ] += lazy[ where ][ i ] ;
                lazy[ 2 * where + 1 ][ i ] %= 2 ;
            }
            lazy[ where ][ i ] = 0 ;
        }    
    }
    if ( CURR < IL || IR < CURL ) { return 0 ; }
    if ( CURL <= IL && IR <= CURR ) {
    	long long ret = 0 ;
        for ( i = 0 ; i < 20 ; i ++ ) {
			ret += 1LL * tr[ where ][ i ] * (1<<i) ; 
        }
        return ret ;
    }
    int mid = ( IL + IR ) / 2 ;
    long long ret = 0 ;
    ret += query ( 2 * where , IL , mid , CURL , CURR ) ;
    ret += query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    for ( i = 0 ; i < 20 ; i ++ ) {
    	tr[ where ][ i ] = tr[ 2 * where ][ i ] + tr[ 2 * where + 1 ][ i ] ;
    }    
    return ret ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
    LEAVES = 1 ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
}

void solve ( ) {
	int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 0 ; j < 20 ; j ++ ) {
        	if ( (a[ i ]&(1<<j)) != 0 ) { tr[ LEAVES + i - 1 ][ j ] = 1 ; }
            else { tr[ LEAVES + i - 1 ][ j ] = 0 ; }
        }
    }
    for ( i = LEAVES - 1 ; i >= 1 ; i -- ) {
    	for ( j = 0 ; j < 20 ; j ++ ) {
        	tr[ i ][ j ] = tr[ 2 * i ][ j ] + tr[ 2 * i + 1 ][ j ] ;
        }
    }
    int q ;
    int x , y , z , t ;
    scanf ( "%d" , &q ) ;
    while ( q != 0 ) {
    	q -- ;
        scanf ( "%d" , &x ) ;
        if ( x == 1 ) {
        	scanf ( "%d%d" , &y , &z ) ;
            printf ( "%I64d\n" , query ( 1 , 1 , LEAVES , y , z ) ) ;
        }
        else {
        	scanf ( "%d%d%d" , &y , &z , &t ) ;
            update ( 1 , 1 , LEAVES , y , z , t ) ;
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