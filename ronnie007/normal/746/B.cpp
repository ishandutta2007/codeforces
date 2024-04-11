#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
using namespace std ;

int n ;
string a ;


void input ( ) {
	cin >> n ;
	cin >> a ;
}

void solve ( ) {
	string ret ;
	ret.resize ( n ) ;
	int i ;
	int l , r ;
	l = r = ( n - 1 ) / 2 ;
	ret[ l ] = a[ 0 ] ;
	for ( i = 1 ; i < n ; i ++ ) {
		if ( ( n % 2 ) == 1 ) {
			if ( ( i % 2 ) == 1 ) {
				l -- ;
				ret[ l ] = a[ i ] ; 
			}
			else {
				r ++ ;
				ret[ r ] = a[ i ] ;
			}
		}
		else {
			if ( ( i % 2 ) == 0 ) {
				l -- ;
				ret[ l ] = a[ i ] ; 
			}
			else {
				r ++ ;
				ret[ r ] = a[ i ] ;
			}		
		}
	}
	cout << ret << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}