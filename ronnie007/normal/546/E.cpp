#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<ctime>
using namespace std ;

#define inf 1000000

#define MAXN 507

int n , m ;
int st[ MAXN ] ;
int en[ MAXN ] ;
int lst[ MAXN ] ;
int d[ MAXN ] ;
int ans[ MAXN ][ MAXN ] ;

int source ;
int sink ;

struct tuhla {
	int to ;
	int flow ;
	int cap ;
	int prev ;
};
vector < struct tuhla > v ;

struct tuhla add_edge ( int x , int y , int z ) {
	struct tuhla ret ;
	ret.to = x ;
	ret.flow = 0 ;
	ret.cap = y ;
	ret.prev = z ;
	return ret ;
}

bool bfs ( int vertex ) {
	int i ;
	for ( i = 1 ; i <= sink ; i ++ ) {
		d[ i ] = inf ; 
	}
	queue < int > q ;
	d[ vertex ] = 0 ;
	q.push ( vertex ) ;
	int e ;
	while ( q.empty ( ) == false ) {
		e = q.front ( ) ;
		q.pop ( ) ;
		for ( i = lst[ e ] ; i != -7 ; i = v[ i ].prev ) {
			if ( d[ v[ i ].to ] == inf && v[ i ^ 1 ].cap != v[ i ^ 1 ].flow ) {
				q.push ( v[ i ].to ) ;
				d[ v[ i ].to ] = d[ e ] + 1 ;
			}
		}
	}
	return ( d[ source ] != inf ) ;
}

int dfs ( int vertex , int y ) {
	int i ;
	int go ; 
	if ( vertex == sink ) return y ;
	for ( i = lst[ vertex ] ; i != -7 ; i = v[ i ].prev ) {
		if ( d[ vertex ] == d[ v[ i ].to ] + 1 && v[ i ].flow != v[ i ].cap ) {
			go = dfs ( v[ i ].to , min ( y , v[ i ].cap - v[ i ].flow ) ) ;
			if ( go != -1 ) {
				v[ i ].flow += go ;
				v[ i ^ 1 ].flow -= go ;
				return go ;
			}
		}
	}
	d[ vertex ] = -1 ;
	return -1 ; 
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
	source = 2 * n + 1 ;
	sink = source + 1 ;
	for ( i = 1 ; i <= sink ; i ++ ) { lst[ i ] = -7 ; }
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &st[ i ] ) ;
		v.push_back ( add_edge ( i , st[ i ] , lst[ source ] ) ) ;
		lst[ source ] = v.size ( ) - 1 ;
		v.push_back ( add_edge ( source , 0 , lst[ i ] ) ) ;
		lst[ i ] = v.size ( ) - 1 ;
    }
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &en[ i ] ) ;
		v.push_back ( add_edge ( sink , en[ i ] , lst[ n + i ] ) ) ;
		lst[ n + i ] = v.size ( ) - 1 ;
		v.push_back ( add_edge ( n + i , 0 , lst[ sink ] ) ) ;
		lst[ sink ] = v.size ( ) - 1 ;
    }
	for ( i = 1 ; i <= n ; i ++ ) {
		v.push_back ( add_edge ( n + i , inf , lst[ i ] ) ) ;
		lst[ i ] = v.size ( ) - 1 ;
		v.push_back ( add_edge ( i , 0 , lst[ n + i ] ) ) ;
		lst[ n + i ] = v.size ( ) - 1 ;
    }
	int x , y ;
	for ( i = 0 ; i < m ; i ++ ) {
		scanf ( "%d%d" , &x , &y ) ;
		v.push_back ( add_edge ( n + y , inf , lst[ x ] ) ) ;
		lst[ x ] = v.size ( ) - 1 ;
		v.push_back ( add_edge ( x , 0 , lst[ n + y ] ) ) ;
		lst[ n + y ] = v.size ( ) - 1 ;

		v.push_back ( add_edge ( n + x , inf , lst[ y ] ) ) ;
		lst[ y ] = v.size ( ) - 1 ;
		v.push_back ( add_edge ( y , 0 , lst[ n + x ] ) ) ;
		lst[ n + x ] = v.size ( ) - 1 ;
    }
}

void solve ( )  {
	long long maxflow = 0 ;
	long long flow ; 
	while ( bfs ( sink ) == true ) {
		while ( 1 ) {
			flow = dfs ( source , inf ) ;
			if ( flow == -1 ) break ;
			maxflow += flow ;
		}
	}
	//printf ( "%d\n" , maxflow ) ;
	int i , j ;
	int sm = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( st[ i ] != en[ i ] ) { break ; }
    }
	if ( i == n + 1 ) { 
		printf ( "YES\n" ) ;
		for ( i = 1 ; i <= n ; i ++ ) {
			for ( j = 1 ; j <= n ; j ++ ) {
				if ( i != j ) { printf ( "0" ) ; }
				else { printf ( "%d" , st[ i ] ) ; }
				if ( j == n ) { printf ( "\n" ) ; }
				else { printf ( " " ) ; }
	        }
    	}		
		return ;
	}
	int sm2 = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) { sm2 += st[ i ] ; }
	for ( i = 1 ; i <= n ; i ++ ) { sm += en[ i ] ; }
	if ( maxflow != sm || sm != sm2 ) {
		printf ( "NO\n" ) ;
		return ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = lst[ i ] ; j != -7 ; j = v[ j ].prev ) {
			//printf ( "%d %d\n" , v[ j ].to , v[ j ].flow ) ;
			if ( v[ j ].to != source ) {
				ans[ i ][ v[ j ].to - n ] = v[ j ].flow ;
            }
        }
		//printf ( "---\n" ) ;
    }
	printf ( "YES\n" ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			printf ( "%d" , ans[ i ][ j ] ) ;
			if ( j == n ) { printf ( "\n" ) ; }
			else { printf ( " " ) ; }
        }
    }
}