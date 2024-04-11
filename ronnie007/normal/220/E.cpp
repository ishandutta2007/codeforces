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
long long k ;
int a[ MAXN ] ;
int LEAVES = 1 ;
int tr[ 2 ][ 5 * MAXN ] ;


map < int , int > ZX ;

void update ( int id , int where , int val ) {
	while ( where != 0 ) {
    	tr[ id ][ where ] += val ;
        where /= 2 ;
    }
}

int query ( int id , int where ) {
	int ret = 0 ;
    while ( where != 0 ) {
    	if ( (where&(where-1)) == 0 ) {
        	ret += tr[ id ][ where ] ;
            break ;
        }
        if ( where % 2 == 1 ) {
        	where /= 2 ;
        }
        else {
        	ret += tr[ id ][ where ] ;
            where -- ;
        }
    }
    return ret ;
}

void input ( ) {
	cin >> n >> k ;
    int i ;
    vector < int > v ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	cin >> a[ i ] ;
        v.push_back ( a[ i ] ) ;
    }
    sort ( v.begin ( ) , v.end ( ) ) ;
    ZX[ v[ 0 ] ] = 1 ;
    int id = 1 ;
    for ( i = 1 ; i < n ; i ++ ) {
    	if ( v[ i ] == v[ i - 1 ] ) { continue ; }
       	id ++ ;
        ZX[ v[ i ] ] = id ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	a[ i ] = ZX[ a[ i ] ] ;
    }
    LEAVES = 1 ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
}

void solve ( ) {
	int i ;
	int l , r ;
    r = 1 ;
    long long ans = 0 ;
    long long curinv = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	curinv += ( tr[ 1 ][ 1 ] - query ( 1 , LEAVES + a[ i ] - 1 ) ) ;
    	update ( 1 , LEAVES + a[ i ] - 1 , 1 ) ;
    }

    for ( l = 1 ; l <= n ; l ++ ) {
        while ( r <= l ) {
			curinv -= ( tr[ 0 ][ 1 ] - query ( 0 , LEAVES + a[ r ] - 1 ) ) ;
            if ( a[ r ] != 1 ) { curinv -= query ( 1 , LEAVES + a[ r ] - 2 ) ; }
        	update ( 1 , LEAVES + a[ r ] - 1 , -1 ) ;
            r ++ ;
        }
        curinv += ( tr[ 0 ][ 1 ] - query ( 0 , LEAVES + a[ l ] - 1 ) ) ;
        if ( a[ l ] != 1 ) { curinv += query ( 1 , LEAVES + a[ l ] - 2 ) ; }
    	update ( 0 , LEAVES + a[ l ] - 1 , 1 ) ;
        while ( r <= n && curinv > k ) {
			curinv -= ( tr[ 0 ][ 1 ] - query ( 0 , LEAVES + a[ r ] - 1 ) ) ;
            if ( a[ r ] != 1 ) { curinv -= query ( 1 , LEAVES + a[ r ] - 2 ) ; }
        	update ( 1 , LEAVES + a[ r ] - 1 , -1 ) ;
            r ++ ;        	
        }
        ans += ( n - r + 1 ) ;
    }
	cout << ans << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}