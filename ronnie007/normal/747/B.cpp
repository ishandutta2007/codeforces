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
	if ( ( n % 4 ) != 0 ) { cout << "===\n" ; return ; }
	int u = ( n / 4 ) ;
	int i ;
	int br1 , br2 , br3 , br4 ;
	br1 = br2 = br3 = br4 = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == 'A' ) { br1 ++ ; }
		if ( a[ i ] == 'C' ) { br2 ++ ; }
		if ( a[ i ] == 'G' ) { br3 ++ ; }
		if ( a[ i ] == 'T' ) { br4 ++ ; }
	}
	if ( br1 > u ) { cout << "===\n" ; return ; }
	if ( br2 > u ) { cout << "===\n" ; return ; }
	if ( br3 > u ) { cout << "===\n" ; return ; }
	if ( br4 > u ) { cout << "===\n" ; return ; }
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == '?' ) {
			if ( br1 < u ) { br1 ++ ; a[ i ] = 'A' ; }
			else if ( br2 < u ) { br2 ++ ; a[ i ] = 'C' ; }
			else if ( br3 < u ) { br3 ++ ; a[ i ] = 'G' ; }
			else { br4 ++ ; a[ i ] = 'T' ; }
		}
	}
	cout << a << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}