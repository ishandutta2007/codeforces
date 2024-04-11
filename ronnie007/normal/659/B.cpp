#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n , m ;

struct tuhla {
	string s ;
	int x ;
};

vector < struct tuhla > v[ MAXN ] ;

bool cmp ( struct tuhla p1 , struct tuhla p2 ) {
	return ( p1.x > p2.x ) ;
}

void input ( ) {
	cin >> n >> m ;
	int i ;
	string p ;
	int q , r ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> p >> q >> r ;
		struct tuhla u ; 
		u.s = p ;
		u.x = r ;
		v[ q ].push_back ( u ) ;
	}
	for ( i = 1 ; i <= m ; i ++ ) {
		sort ( v[ i ].begin ( ) , v[ i ].end ( ) , cmp ) ;
	}
}

void solve ( ) {
	int i ;
	for ( i = 1 ; i <= m ; i ++ ) {
		if ( v[ i ].size ( ) == 2 ) {
			cout << v[ i ][ 0 ].s << " " << v[ i ][ 1 ].s << "\n" ;
		}
		else {
			if ( ( v[ i ][ 0 ].x + v[ i ][ 1 ].x ) == ( v[ i ][ 0 ].x + v[ i ][ 2 ].x ) ) { cout << "?\n" ; }
			else { cout << v[ i ][ 0 ].s << " " << v[ i ][ 1 ].s << "\n" ; }
		}
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}