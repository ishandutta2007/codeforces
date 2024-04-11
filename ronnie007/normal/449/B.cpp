#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

#define MAXN 100007

int n , m , k ;
struct tuhla {
	int vertex ;
    long long cost ;
};

vector < struct tuhla > v[ MAXN ] ;

long long dist[ MAXN ] ;
int used[ MAXN ] ;

int prv[ MAXN ] ;

bool operator < ( struct tuhla p1 , struct tuhla p2 ) {
	return ( p1.cost > p2.cost ) ; 
}

priority_queue < struct tuhla > q ;

void dijkstra ( ) {
	struct tuhla u , e ;
    int i , sz ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( dist[ i ] == -1 ) { continue ; }
	    u.vertex = i ;
    	u.cost = dist[ i ] ;
	    q.push ( u ) ;
	}
    while ( q.empty ( ) == false ) {
    	u = q.top ( ) ;
        q.pop ( ) ;
        if ( dist[ u.vertex ] != u.cost ) { continue ; }
        int sz = v[ u.vertex ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
	        if ( dist[ v[ u.vertex ][ i ].vertex ] == dist[ u.vertex ] + v[ u.vertex ][ i ].cost ) {
            	prv[ v[ u.vertex ][ i ].vertex ] = 0 ;
            }
        	if ( dist[ v[ u.vertex ][ i ].vertex ] == -1 || dist[ v[ u.vertex ][ i ].vertex ] > dist[ u.vertex ] + v[ u.vertex ][ i ].cost ) {
            	dist[ v[ u.vertex ][ i ].vertex ] = dist[ u.vertex ] + v[ u.vertex ][ i ].cost ;
                e.vertex = v[ u.vertex ][ i ].vertex ;
                e.cost = dist[ v[ u.vertex ][ i ].vertex ] ;
                prv[ e.vertex ] = 0 ;
                q.push ( e ) ;
            }
        }
    }
}

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    struct tuhla u ;
    for ( i = 1 ; i <= m ; i ++ ) {
    	int x , y , z ;
    	scanf ( "%d%d%d" , &x , &y , &z ) ;
        u.vertex = y ;
       	u.cost = z ;
        v[ x ].push_back ( u ) ;
        u.vertex = x ;
        v[ y ].push_back ( u ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) { dist[ i ] = -1 ; }
    dist[ 1 ] = 0 ;    
    for ( i = 1 ; i <= k ; i ++ ) {
    	int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
		if ( dist[ x ] == -1 || dist[ x ] > y ) { dist[ x ] = y ; prv[ x ] = i ; }
    }
}

void solve ( ) {
	dijkstra ( ) ;
    int i ;
    int br = 0 ;
    for ( i = 2 ; i <= n ; i ++ ) {
    	used[ prv[ i ] ] ++ ;
    }
    for ( i = 1 ; i <= k ; i ++ ) {
    	if ( used[ i ] == 0 ) { br ++ ; }
    }
    printf ( "%d\n" , br ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}