#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<set>
using namespace std ;

#define MAXN 127007

int n , m ;
vector < int > v[ MAXN ] ;
vector < int > h ;
int dist[ MAXN ] ;
bool ch[ MAXN ] ;
int mxpath[ MAXN ] ;


void dfs_dist ( int vertex ) {
	int sz = v[ vertex ].size ( ) ;
	int i ;
	for ( i = 0 ; i < sz ; i ++ ) {
		int u = v[ vertex ][ i ] ;
		if ( dist[ u ] != 0 ) { continue ; }
		dist[ u ] = 1 + dist[ vertex ] ;
		dfs_dist ( u ) ;
	}
}

int dfs_ans ( int vertex , int par ) {
	int sz = v[ vertex ].size ( ) ;
	if ( sz == 1 && par != -1 ) {
		if ( ch[ vertex ] == false ) { return -1 ; }
		else { return 0 ; }
	}
	int i ;
	int mx = 0 ;
	int sm = 0 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		int u = v[ vertex ][ i ] ;
		if ( u == par ) { continue ; }
		int ret = dfs_ans ( u , vertex ) ;
		if ( ret != -1 ) {
			ret += 2 ;
			sm += ret ;
			if ( mxpath[ vertex ] <= mxpath[ u ] + 1 ) { mxpath[ vertex ] = mxpath[ u ] + 1 ; }
		}
	}
	if ( sm == 0 && ch[ vertex ] == false ) { return -1 ; }
	if ( par != -1 ) { sm += mxpath[ vertex ] ; }
	return ( sm - mxpath[ vertex ] ) ;
}

void input ( ) ;
void solve ( ) ;

int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i ;
	int x , y ;
	for ( i = 0 ; i < n - 1 ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v[ x ].push_back ( y ) ;
		v[ y ].push_back ( x ) ;
	}
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d" , &x ) ;
		ch[ x ] = true ; 
		h.push_back ( x ) ;
	}
}
 
void solve ( ) {
	int st = h[ 0 ] ;
	dist[ st ] = 1 ; 
	dfs_dist ( st ) ;
	int mx = 0 ;
	int id1 = 1000000007 ;
	int id2 = 1000000007 ;
	int i ;
	for ( i = 0 ; i < m ; i ++ ) {
		if ( mx < dist[ h[ i ] ] || ( mx == dist[ h[ i ] ] && id1 > h[ i ] ) ) { mx = dist[ h[ i ] ] ; id1 = h[ i ] ; }
	}
	for ( i = 0 ; i <= n ; i ++ ) { dist[ i ] = 0 ; }
	dist[ id1 ] = 1 ; 
	dfs_dist ( id1 ) ;
	mx = 0 ;
	for ( i = 0 ; i < m ; i ++ ) {
		if ( mx < dist[ h[ i ] ] || ( mx == dist[ h[ i ] ] && id2 > h[ i ] )  ) { mx = dist[ h[ i ] ] ; id2 = h[ i ] ; }
	}
	if ( id1 > id2 ) { id1 = id2 ; }
	int ret = dfs_ans ( id1 , -1 ) ;
	printf ( "%d\n%d\n" , id1 , ret ) ;
}