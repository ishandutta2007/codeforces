#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n , t ;
string a ;

bool f ( ) {
	int i ;
	int p = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		p = ( p * 10 + ( a[ i ] - '0' ) ) ;
		p %= t ; 
	}
	return ( p == 0 ) ;
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
	cin >> n >> t ;
}

void solve ( ) {
	int i ;
	if ( n == 1 ) {
		if ( t == 10 ) { cout << "-1\n" ; return ; }
		else { cout << t << "\n" ; return ; }
	}
	a += '1' ;
	for ( i = 2 ; i <= n ; i ++ ) {
		a += '0' ;
	}
	for ( i = 0 ; i <= 9 ; i ++ ) {
		a[ n - 1 ] = char ( i + '0' ) ;
		if ( f ( ) == true ) {
			cout << a << "\n" ; 
			return ; 
		}
	}
	cout << "-1\n" ;
}