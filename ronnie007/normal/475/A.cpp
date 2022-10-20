#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n ; 
string a[ 17 ] ; 


void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	//scanf ( "%d" , &n ) ;
	cin >> n ;
}

void solve ( )  {
	a[ 0 ] = "+------------------------+" ;
	a[ 1 ] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)" ;
	a[ 2 ] = "|#.#.#.#.#.#.#.#.#.#.#.|.|" ;
	a[ 3 ] = "|#.......................|" ;
	a[ 4 ] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)" ;
	a[ 5 ] = "+------------------------+" ;
   	int i , j ;
	int sz ;
	for ( i = 0 ; i < 40 ; i ++ ) {
		if ( n == 0 ) break ;
		for ( j = 0 ; j < 6 ; j ++ ) {
			if ( n == 0 ) break ;
			if ( a[ j ].size ( ) <= i ) continue ;
			if ( a[ j ][ i ] != '#' ) continue ;
			a[ j ][ i ] = 'O' ;
			n -- ;
		}
	}
	for ( i = 0 ; i < 6 ; i ++ ) {
		cout << a[ i ] << "\n" ; 
	}
}