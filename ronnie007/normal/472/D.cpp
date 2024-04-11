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
using namespace std ;


int n ;
int adj[ 2007 ][ 2007 ] ; 
vector < pair < int , int > > gr[ 2007 ]  ; 
int br = 0 ; 

struct tuhla {
	int x , y ;
	int len ; 
};

vector < struct tuhla > v ; 

bool f ( struct tuhla p1 , struct tuhla p2 ) {
	if ( p1.len != p2.len ) return ( p1.len < p2.len ) ;
	if ( p1.x != p2.x ) return ( p1.x < p2.x ) ;
	return ( p1.y < p2.y ) ;
}

int par[ 2007 ] ;
int rnk[ 2007 ] ; 

int find ( int e ) {
	if ( par[ e ] == -1 ) return e ;
	int ret = find ( par[ e ] ) ;
	par[ e ] = ret ;
	return ret ; 
}

void UNITE ( struct tuhla u ) {
	int k1 = find ( u.x ) ;
	int k2 = find ( u.y ) ;
	if ( u.x == 2 && u.y == 3 ) {
        //	printf ( "--%d %d\n" , k1 , k2 ) ;
	}
	if ( k1 != k2 ) {
        //	printf ( "%d %d\n" , k1 , k2 ) ;
		gr[ u.x ].push_back ( make_pair ( u.y , u.len ) ) ;
		gr[ u.y ].push_back ( make_pair ( u.x , u.len ) ) ;
		br ++ ;
		if ( rnk[ k1 ] > rnk[ k2 ] ) {
			par[ k2 ] = k1 ;
		}
		else if ( rnk[ k2 ] > rnk[ k1 ] ) {
			par[ k1 ] = k2 ;
		}
		else { 
			par[ k2 ] = k1 ;
			rnk[ k1 ] ++ ;
		}
	}
}

long long dist[ 2007 ] ; 



bool BFS ( int vertex ) {
	int i ;
	int sz ; 
	for ( i = 1 ; i <= n ; i ++ ) dist[ i ] = -1 ;
	dist[ vertex ] = 0 ;
	queue < int > q ;
	while ( q.empty ( ) == false ) q.pop ( ) ;
	q.push ( vertex ) ;
	int cur ;
	while ( q.empty ( ) == false ) {
		cur = q.front ( ) ;
		if ( dist[ cur ] != adj[ vertex ][ cur ] ) return false ; 
		q.pop ( ) ;
		sz = gr[ cur ].size ( ) ;
		for ( i = 0 ; i < sz ; i ++ ) {
			int h = gr[ cur ][ i ].first ;
			int c = gr[ cur ][ i ].second ;
			if ( dist[ h ] == -1 ) {
				dist[ h ] = dist[ cur ] + c ;
				q.push ( h ) ;
			}
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( dist[ i ] != adj[ vertex ][ i ] ) break ;
	}
	if ( i != n + 1 ) return false ;
	return true ; 
}


void input ( ) ;
void solve ( ) ;



int main ( )  {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d" , &n ) ;
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			scanf ( "%d" , &adj[ i ][ j ] ) ;
		}
	}
}
 
void solve ( )  {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( adj[ i ][ i ] != 0 ) {
			printf ( "NO\n" ) ;
			return ;
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 1 ; j <= n ; j ++ ) {
			if ( adj[ i ][ j ] != adj[ j ][ i ] ) {
				printf ( "NO\n" ) ;
				return ;
			}
			if ( i != j && adj[ i ][ j ] == 0 ) {
				printf ( "NO\n" ) ;
				return ;
			}
		}
	}
	struct tuhla u ; 
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = i + 1 ; j <= n ; j ++ ) {
			u.x = i ; 
			u.y = j ;
			u.len = adj[ i ][ j ] ;
			if ( u.len == 0 ) continue ; 
			v.push_back ( u ) ;
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) { rnk[ i ] = 0 ; par[ i ] = -1 ; } 


	sort ( v.begin ( ) , v.end ( ) , f ) ;
	int sz = v.size ( ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( br == n - 1 ) break ;
		UNITE ( v[ i ] ) ;
	}
	if ( br != n - 1 ) {
		printf ( "NO\n" ) ;
		return ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( BFS ( i ) == false ) { printf ( "NO\n" ) ; return ; } 
	}
	printf ( "YES\n" ) ;
}