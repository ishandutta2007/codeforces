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
string a ;

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
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( )  {
	int i ;
	int x ;
	for ( i = 0 ; i < n ; i ++ ) {
		x = ( a[ i ] - '0' ) ;
		if ( x >= 5 ) { x = 9 - x ; } 
		if ( x == 0 && i == 0 ) { x = 9 ; } 
		a[ i ] = ( x + '0' ) ;
    }
	cout << a << "\n" ; 
}