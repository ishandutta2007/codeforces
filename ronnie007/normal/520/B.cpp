#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
#include<stack>
using namespace std ;

int n , m ;
int d[ 30007 ] ;

void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> n >> m ;
}

void solve ( ) {
	int i ;
	queue < int > q ;
	q.push ( n ) ;
	for ( i = 1 ; i <= 30000 ; i ++ ) {
		d[ i ] = 100077 ;
	}
	d[ n ] = 0 ; 
	int x , y ;
	while ( q.empty ( ) == false ) {
		x = q.front ( ) ;
		q.pop ( ) ;
		if ( x != 1 && d[ x - 1 ] > d[ x ] + 1 ) { d[ x - 1 ] = d[ x ] + 1 ; q.push ( x - 1 ) ; }
		if ( 2 * x <= 30000 && d[ 2 * x ] > d[ x ] + 1 ) { d[ 2 * x ] = d[ x ] + 1 ; q.push ( 2 * x ) ; }
	}
	printf ( "%d\n" , d[ m ] ) ;
}