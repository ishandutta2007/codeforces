#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

long long u , p ;

long long f ( int e , long long  h , long long x ) {
	long long u = ((1LL<<((h-1)))) ;
	if ( h == 0 ) { return 0 ; } 
	if ( e == 0 ) {
		if ( x <= u ) { return ( 1 + f ( 1 , h - 1 , x ) ) ; }
		else { return ( 2 * u  + f ( 0 , h - 1 , x - u ) ) ; }
    }
	if ( x <= u ) { return ( 2 * u + f ( 1 , h - 1 , x ) ) ; } 
	else { return ( 1 + f ( 0 , h - 1 , x - u ) ) ; } 
}

void input ( ) ;
void solve ( ) ;


int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	cin >> u >> p ;
}

void solve ( ) {
	cout << f ( 0 , u , p ) << "\n" ;
}