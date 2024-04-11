#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

int n , k ;
string a ;

void input ( ) {
	cin >> n >> k ;
	cin >> a ;
}

void solve ( ) {
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		int x = ( a[ i ] - 'a' ) ;
		int y = ( 'z' - a[ i ] ) ;
		if ( x > y ) {
			if ( k >= x ) { a[ i ] = 'a' ; k -= x ; }
			else {
				while ( k != 0 ) {
					k -- ;
					a[ i ] -- ; 
				}
			}
		}
		else {
			if ( k >= y ) { a[ i ] = 'z' ; k -= y ; }
			else {
				while ( k != 0 ) {
					k -- ;
					a[ i ] ++ ; 
				}
			}
		}
	}
	if ( k != 0 ) { cout << "-1\n" ; }
	else { cout << a << "\n" ; }
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}