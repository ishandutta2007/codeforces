#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
using namespace std ;

#define MAXN 5007

int n ;
int a[ MAXN ] ;

int LEAVES ;
int tr[ 4 * MAXN ] ;

void update ( int where , int val ) {
	while ( where != 0 ) {
    	tr[ where ] += val ;
        where /= 2 ;
    }
}

int query ( int where ) {
	int ret = 0 ;
    while ( where != 0 ) {
    	if ( (where&(where-1)) == 0 ) {
        	ret += tr[ where ] ;
			break ;
        }
        if ( ( where % 2 ) == 1 ) {
        	where /= 2 ;
        }
        else {
        	ret += tr[ where ] ;
            where -- ;
        }
    }
    return ret ;
}

int f ( ) {
	int i ;
    int ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	ans += ( tr[ 1 ] - query ( LEAVES + a[ i ] ) ) ;
        update ( LEAVES + a[ i ] , 1 ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        update ( LEAVES + a[ i ] , -1 ) ;
    }
    return ans ;
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
    int init = f ( ) ;
    int ans = init ;
	int br = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = i ; j <= n ; j ++ ) {
            int cur = init + tr[ 1 ] - 2 * query ( LEAVES + a[ i ] ) + 2 * query ( LEAVES + a[ j ] ) - tr[ 1 ] ;
            if ( a[ i ] > a[ j ] ) { cur -- ; }
            else if ( a[ i ] < a[ j ] ) { cur ++ ; }
            if ( cur < ans ) { ans = cur ; br = 0 ; }
            if ( cur == ans ) { br ++ ; }
        	if ( i != j ) { update ( LEAVES + a[ j ] , 1 ) ; }
        }
        for ( j = i + 1 ; j <= n ; j ++ ) {
        	update ( LEAVES + a[ j ] , -1 ) ;
        }
    }
    printf ( "%d %d\n" , ans , br ) ;
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}