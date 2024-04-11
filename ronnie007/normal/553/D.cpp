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
#define eps 0.0000001
int n , m , k ;
bool fort[ MAXN ] ;
vector < int > v[ MAXN ] ;

struct tuhla {
	int vertex ;
    double val ;
};

double f[ MAXN ] ;
bool used[ MAXN ] ;

double bestval ;
int id ;

bool operator < ( struct tuhla p1 , struct tuhla p2 ) {
	return ( p1.val > p2.val ) ;
}

priority_queue < struct tuhla > q ;

void calc ( ) {
	int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( fort[ i ] == true ) { used[ i ] = true ; }
        else { used[ i ] = false ; }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( fort[ i ] == true ) { continue ; }
    	int sz = v[ i ].size ( ) ;
        double br = 0.00000 ;
    	for ( j = 0 ; j < sz ; j ++ ) {
        	if ( fort[ v[ i ][ j ] ] == false ) { br += 1.000000 ; }
        }
        f[ i ] = ( br / sz ) ;
        struct tuhla u ;
        u.vertex = i ;
        u.val = f[ i ] ;
        q.push ( u ) ;
    }
	bestval = -1.00000000 ;
    id = -1 ;
    int tot = 0 ;
    while ( q.empty ( ) == false ) {
    	struct tuhla cur = q.top ( ) ;
       	q.pop ( ) ;
        if ( fort[ cur.vertex ] == true || used[ cur.vertex ] == true ) { continue ; }
        if ( cur.val > f[ cur.vertex ] + eps ) { continue ; }
        if ( cur.val < f[ cur.vertex ] - eps ) { continue ; }
        if ( bestval < cur.val ) {
        	bestval = cur.val ;
            id = tot ;
        }
        tot ++ ;
        used[ cur.vertex ] = true ;
        int sz = v[ cur.vertex ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
        	if ( used[ v[ cur.vertex ][ i ] ] == false ) {
            	struct tuhla u ;
                f[ v[ cur.vertex ][ i ] ] = f[ v[ cur.vertex ][ i ] ] - ( 1.00000 / ( v[ v[ cur.vertex ][ i ] ].size ( ) ) ) ;
                u.vertex = v[ cur.vertex ][ i ] ;
                u.val = f[ v[ cur.vertex ][ i ] ] ;
                q.push ( u ) ;
            }
        }
    }
}

void recreate ( int br ) {
	int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( fort[ i ] == true ) { used[ i ] = true ; }
        else { used[ i ] = false ; }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	int sz = v[ i ].size ( ) ;
        double br = 0.00000 ;
    	for ( j = 0 ; j < sz ; j ++ ) {
        	if ( fort[ v[ i ][ j ] ] == false ) { br += 1.000000 ; }
        }
        f[ i ] = ( br / sz ) ;
        struct tuhla u ;
        u.vertex = i ;
        u.val = f[ i ] ;
        q.push ( u ) ;
    }
    int tot = 0 ;
    while ( q.empty ( ) == false ) {
    	struct tuhla cur = q.top ( ) ;
       	q.pop ( ) ;
        if ( fort[ cur.vertex ] == true || used[ cur.vertex ] == true ) { continue ; }
        if ( cur.val > f[ cur.vertex ] + eps ) { continue ; }
        if ( cur.val < f[ cur.vertex ] - eps ) { continue ; }
        if ( br == 0 ) { break ; }
        br -- ;
        used[ cur.vertex ] = true ;
        int sz = v[ cur.vertex ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
        	if ( used[ v[ cur.vertex ][ i ] ] == false ) {
            	struct tuhla u ;
                f[ v[ cur.vertex ][ i ] ] = f[ v[ cur.vertex ][ i ] ] - ( 1.00000 / ( v[ v[ cur.vertex ][ i ] ].size ( ) ) ) ;
                u.vertex = v[ cur.vertex ][ i ] ;
                u.val = f[ v[ cur.vertex ][ i ] ] ;
                q.push ( u ) ;
            }
        }
    }
}

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    for ( i = 1 ; i <= k ; i ++ ) {
    	int x ;
    	scanf ( "%d" , &x ) ;
        fort[ x ] = true ; 
    }
    for ( i = 1 ; i <= m ; i ++ ) {
    	int x , y ;
    	scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
	calc ( ) ;
    recreate ( id ) ;
    vector < int > ret ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( used[ i ] == false ) {
        	ret.push_back ( i ) ;
        }
    }
    int sz = ret.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	printf ( "%d" , ret[ i ] ) ;
        if ( i == sz - 1 ) { printf ( "\n" ) ; }
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