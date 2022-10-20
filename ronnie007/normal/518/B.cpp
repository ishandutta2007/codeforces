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
using namespace std ;

int n , m ; 
string a , b ;
int br[ 67 ] ;
int k[ 67 ] ;

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
	cin >> a >> b ;
	n = a.size ( ) ;
	m = b.size ( ) ;
}

void solve ( )  {
	int i ;
	for ( i = 0 ; i < m ; i ++ ) {
		br[ b[ i ] - 'A' ] ++ ;
    }
	for ( i = 0 ; i < n ; i ++ ) {
		k[ a[ i ] - 'A' ] ++ ;
    }
	int x = 0 ;
	int y = 0 ;
	for ( i = 0 ; i <= 65 ; i ++ ) {
		if ( k[ i ] == 0 ) { continue ; }
		int u = min ( k[ i ] , br[ i ] ) ;
		x += u ;
		k[ i ] -= u ;
		br[ i ] -= u ;
    }
	for ( i = 0 ; i <= 65 ; i ++ ) {
		if ( k[ i ] == 0 ) { continue ; }
		int id = i - 32 ;
		if ( id < 0 ) { id = i + 32 ; }
		int u = min ( k[ i ] , br[ id ] ) ;
		y += u ;
		k[ i ] -= u ;
		br[ id ] -= u ;
    }
	cout << x << " " << y << "\n" ;
}