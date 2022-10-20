#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MAXN 100007
typedef pair < long long , long long > TYPE ;

int n ;
TYPE a[ MAXN ] ;
vector < int > v[ MAXN ] ;

int f[ MAXN ][ 20 ] ;
int lvl[ MAXN ] ;

long long det ( TYPE p1 , TYPE p2 , TYPE p3 ) {
	long long ret = p1.first * p2.second + p1.second * p3.first + p2.first * p3.second ;
	ret -= p3.first * p2.second + p3.second * p1.first + p2.first * p1.second ;
    return ret ;
}

void create_edges ( ) {
	stack < int > s ;
    int i ;
    s.push ( n ) ;
    s.push ( n - 1 ) ;
    v[ n - 1 ].push_back ( n ) ;
    v[ n ].push_back ( n - 1 ) ;
    for ( i = n - 2 ; i >= 1 ; i -- ) {
    	while ( s.size ( ) >= 2 ) {
        	int x = s.top ( ) ;
            s.pop ( ) ;
            int y = s.top ( ) ;
            s.pop ( ) ;
            if ( det ( a[ i ] , a[ x ] , a[ y ] ) > 0 ) {
            	s.push ( y ) ;
            }
            else {
            	s.push ( y ) ;
                s.push ( x ) ;
                break ;
            }
        }
        v[ i ].push_back ( s.top ( ) ) ;
        v[ s.top ( ) ].push_back ( i ) ;
        s.push ( i ) ;
    }
}

void dfs ( int vertex , int prv ) {
	int i ;
    for ( i = 1 ; i <= 18 ; i ++ ) {
    	f[ vertex ][ i ] = f[ f[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    int sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	if ( v[ vertex ][ i ] == prv ) { continue ; }
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        f[ v[ vertex ][ i ] ][ 0 ] = vertex ;
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
}

int LCA ( int x , int y ) {
	int i ;
    for ( i = 18 ; i >= 0 ; i -- ) {
    	int u = (1<<i) ;
    	if ( lvl[ x ] - u >= lvl[ y ] ) {
        	x = f[ x ][ i ] ;
        }
        if ( lvl[ y ] - u >= lvl[ x ] ) {
        	y = f[ y ][ i ] ;
        }
    }
    for ( i = 18 ; i >= 0 ; i -- ) {
    	if ( f[ x ][ i ] != f[ y ][ i ] ) {
        	x = f[ x ][ i ] ;
            y = f[ y ][ i ] ;
        }
    }
    if ( x != y ) { x = f[ x ][ 0 ] ; }
    return x ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%I64d%I64d" , &a[ i ].first , &a[ i ].second ) ;
    }
}

void solve ( ) {
	create_edges ( ) ;
    dfs ( n , -1 ) ;
    int q ;
    int x , y ;
    scanf ( "%d" , &q ) ;
    while ( q != 0 ) {
    	q -- ;
        scanf ( "%d%d" , &x , &y ) ;
        printf ( "%d\n" , LCA ( x , y ) ) ;
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}