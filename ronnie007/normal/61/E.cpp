#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
using namespace std ;

#define MAXN 1000007
int n ;
int a[ MAXN ] ;
map < int , int > ZX ;

int tr[ 2 ][ 5 * MAXN ] ;
int LEAVES = 1 ;

void update ( int id , int where , int val ) {
	while ( where != 0 ) {
    	tr[ id ][ where ] += val ;
        where /= 2 ;
    }
}


int query ( int id , int where ) {
	if ( where < LEAVES ) { return 0 ; }
    int ret = 0 ;
    while ( where != 0 ) {
    	if ( (where&(where-1)) == 0 ) {
        	ret += tr[ id ][ where ] ;
            break ;
        }
        if ( ( where % 2 ) == 1 ) {
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
	scanf ( "%d" , &n ) ;
    int i ;
    vector < int > v ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
        v.push_back ( a[ i ] ) ;
    }
    sort ( v.begin ( ) , v.end ( ) ) ;
    ZX[ v[ 0 ] ] = 1 ;
    int id = 2 ;    
    for ( i = 1 ; i < n ; i ++ ) {
    	if ( v[ i ] == v[ i - 1 ] ) { continue ; }
        ZX[ v[ i ] ] = id ;
        id ++ ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	a[ i ] = ZX[ a[ i ] ] ;
    }
}

void solve ( ) {
	LEAVES = 1 ;
    while ( LEAVES < n ) { LEAVES *= 2 ; }
    int i ;    
    long long l , r ;
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	update ( 1 , LEAVES + a[ i ] - 1 , 1 ) ;
    }
	for ( i = 1 ; i <= n ; i ++ ) {
    	long long l = tr[ 0 ][ 1 ] - query ( 0 , LEAVES + a[ i ] - 1 ) ;
        long long r = query ( 1 , LEAVES + a[ i ] - 2 ) ;
        ans += l * r ;
        update ( 0 , LEAVES + a[ i ] - 1 , 1 ) ;
        update ( 1 , LEAVES + a[ i ] - 1 , -1 ) ;
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