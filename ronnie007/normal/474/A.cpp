#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

char dir ;
string t ;

string a[ 7 ] ;


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
	a[ 0 ] = "qwertyuiop" ;
	a[ 1 ] = "asdfghjkl;" ;
	a[ 2 ] = "zxcvbnm,./" ;
	cin >> dir ;
	cin >> t ;
}

void solve ( )  {
	int p ;
	if ( dir == 'R' ) p = -1 ;
	else p = 1 ;
	int i , j , x ;
	int n = t.size ( ) ;
	int sz ; 
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = 0 ; j < 3 ; j ++ ) {
			sz = a[ j ].size ( ) ;
			for ( x = 0 ; x < sz ; x ++ ) {
				if ( a[ j ][ x ] == t[ i ] ) break ;
			}
			if ( x != sz ) {
				cout << a[ j ][ x + p ] ; 
				break ;
			}
		}
	}
	cout << "\n" ; 
}