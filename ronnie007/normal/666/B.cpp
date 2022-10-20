#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

#define MAXN 3007

int n , m ;
vector < int > v[ MAXN ] ;
vector < int > revv[ MAXN ] ;

int dist[ MAXN ][ MAXN ] ;
int revdist[ MAXN ][ MAXN ] ;

vector < pair < int , int > > u[ MAXN ] ;
vector < pair < int , int > > revu[ MAXN ] ;
void bfs ( int st ) {
	int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	dist[ st ][ i ] = -1 ;
    }
    dist[ st ][ st ] = 0 ;
    queue < int > q ;
    q.push ( st ) ;
    while ( q.empty ( ) == false ) {
    	int vertex = q.front ( ) ;
        q.pop ( ) ;
        int sz = v[ vertex ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
        	if ( dist[ st ][ v[ vertex ][ i ] ] == -1 ) {
            	dist[ st ][ v[ vertex ][ i ] ] = dist[ st ][ vertex ] + 1 ;
                q.push ( v[ vertex ][ i ] ) ;
            }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	u[ st ].push_back ( make_pair ( -dist[ st ][ i ] , i ) ) ;
    }
    sort ( u[ st ].begin ( ) , u[ st ].end ( ) ) ;
    u[ st ].resize ( 3 ) ;
}

void revbfs ( int st ) {
	int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	revdist[ st ][ i ] = -1 ;
    }
    revdist[ st ][ st ] = 0 ;
    queue < int > q ;
    q.push ( st ) ;
    while ( q.empty ( ) == false ) {
    	int vertex = q.front ( ) ;
        q.pop ( ) ;
        int sz = revv[ vertex ].size ( ) ;
        for ( i = 0 ; i < sz ; i ++ ) {
        	if ( revdist[ st ][ revv[ vertex ][ i ] ] == -1 ) {
            	revdist[ st ][ revv[ vertex ][ i ] ] = revdist[ st ][ vertex ] + 1 ;
                q.push ( revv[ vertex ][ i ] ) ;
            }
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	revu[ st ].push_back ( make_pair ( -revdist[ st ][ i ] , i ) ) ;
    }
    sort ( revu[ st ].begin ( ) , revu[ st ].end ( ) ) ;
    revu[ st ].resize ( 3 ) ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
    	int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        revv[ y ].push_back ( x ) ;
    }
	for ( i = 1 ; i <= n ; i ++ ) {
    	bfs ( i ) ;
        revbfs ( i ) ;
    }
}

void solve ( ) {
	int i , j , t , z ;
    int ans = -1 ;
    int cur ;
    int p1 , p2 , p3 , p4 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= n ; j ++ ) {
        	if ( i == j ) { continue ; }
            if ( dist[ i ][ j ] == -1 ) { continue ; }
            for ( t = 0 ; t < 3 ; t ++ ) {
            	for ( z = 0 ; z < 3 ; z ++ ) {
                	int x , y ;
                    x = revu[ i ][ t ].second ;
                    y = u[ j ][ z ].second ;
                    if ( x == y ) { continue ; }
                    if ( x == i || x == j ) { continue ; }
                    if ( y == i || y == j ) { continue ; }
                    if ( revu[ i ][ t ].first >= 0 ) { continue ; }
                    if ( u[ j ][ z ].first >= 0 ) { continue ; }
                    cur = dist[ i ][ j ] - revu[ i ][ t ].first - u[ j ][ z ].first ;              
                    if ( cur > ans ) {
                    	ans = cur ;
                        p1 = x ;
                        p2 = i ;
                        p3 = j ;
                        p4 = y ;
                    }
                }
            }
        }
    }
    printf ( "%d %d %d %d\n" , p1 , p2 , p3 , p4 ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}