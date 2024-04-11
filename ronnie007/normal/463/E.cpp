#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
using namespace std ;

#define MAXN 100007

int n , q ;
int a[ MAXN ] ;

vector < int > v[ MAXN ] ;

vector < int > fact[ 20 * MAXN ] ;
int f[ 20 * MAXN ] ;
int rev[ 20 * MAXN ] ;

int lvl[ MAXN ] ;

int ans[ MAXN ] ;

vector < int > toupd[ MAXN ] ;

struct query {
	int type ;
    int x , y ;
};
query h[ MAXN ] ;


void dfs ( int vertex , int prv ) {
	int i , sz ;
    sz = v[ vertex ].size ( ) ;
    int w = fact[ a[ vertex ] ].size ( ) ;
 	int g = -1 ;
    vector < int > rev ;
    for ( i = 0 ; i < w ; i ++ ) {
    	if ( f[ fact[ a[ vertex ] ][ i ] ] != 0 ) {
        	if ( g == -1 || lvl[ g ] < lvl[ f[ fact[ a[ vertex ] ][ i ] ] ] ) {
	        	g = f[ fact[ a[ vertex ] ][ i ] ] ;
			}
		}
        rev.push_back ( f[ fact[ a[ vertex ] ][ i ] ] ) ;
    	f[ fact[ a[ vertex ] ][ i ] ] = vertex ;
    }
    w = toupd[ vertex ].size ( ) ;
    for ( i = 0 ; i < w ; i ++ ) { ans[ toupd[ vertex ][ i ] ] = g ; }
    toupd[ vertex ].clear ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	if ( v[ vertex ][ i ] == prv ) { continue ; }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
    w = fact[ a[ vertex ] ].size ( ) ;    
    for ( i = 0 ; i < w ; i ++ ) {
        f[ fact[ a[ vertex ] ][ i ] ] = rev[ i ] ;
    }    
}

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    int x , y ;
    for ( i = 1 ; i < n ; i ++ ) {
    	scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
	int i , j ;
    int lim = 20 * MAXN ;
    for ( i = 2 ; i <= lim ; i ++ ) {
    	if ( fact[ i ].size ( ) != 0 ) { continue ; }
    	for ( j = i ; j <= lim ; j += i ) {
        	fact[ j ].push_back ( i ) ;
        }
    }
    for ( i = 1 ; i <= q ; i ++ ) {
    	scanf ( "%d" , &h[ i ].type ) ;
        if ( h[ i ].type == 1 ) {
        	scanf ( "%d" , &h[ i ].x ) ;
        }
        else {
        	scanf ( "%d%d" , &h[ i ].x , &h[ i ].y ) ;
        }
    }
    int lst = 0 ;
    while ( lst < q ) {
    	for ( i = lst + 1 ; i <= q ; i ++ ) {
        	if ( h[ i ].type == 2 ) { break ; }
        	toupd[ h[ i ].x ].push_back ( i ) ;
        }
        dfs ( 1 , -1 ) ;        
        a[ h[ i ].x ] = h[ i ].y ;
        lst = i ;
    }
    for ( i = 1 ; i <= q ; i ++ ) {
    	if ( h[ i ].type == 2 ) { continue ; }
        printf ( "%d\n" , ans[ i ] ) ;
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}