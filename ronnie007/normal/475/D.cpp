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

int n ;
int a[ MAXN ] ;


vector < int > v[ MAXN ] ;

map < int , long long > curvals ;
map < int , long long > ZX ;

map < int , long long > aux ;

int w ( int x , int y ) {
	if ( x < y ) { swap ( x , y ) ; }
	if ( y == 0 ) { return x ; }
	return w ( y , ( x % y ) ) ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int i , j ;
	map < int , long long > :: iterator it ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( it = curvals.begin ( ) ; it != curvals.end ( ) ; it ++ ) {
			int u = w ( it->first , a[ i ] ) ;
			ZX[ u ] += it->second ;
			aux[ u ] += it->second ;
		}
		curvals.clear ( ) ;
		for ( it = aux.begin ( ) ; it != aux.end ( ) ; it ++ ) {
			curvals[ it->first ] = it->second ;
		}
		aux.clear ( ) ;
		curvals[ a[ i ] ] ++ ;
		ZX[ a[ i ] ] ++ ;
	}
	int q , x ;
	scanf ( "%d" , &q ) ;
	while ( q != 0 ) {
		q -- ;
		scanf ( "%d" , &x ) ;
		printf ( "%I64d\n" , ZX[ x ] ) ;
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}