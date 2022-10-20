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

int n ;
string a ;

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
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( )  {
	vector < string > v ;
	string c ;
	int i ;
	while ( 1 ) {
		for ( i = 0 ; i < n ; i ++ ) {
			if ( a[ i ] != '0' ) { break ; }
        }
		if ( i == n ) { break ; }
		c.clear ( ) ;
		for ( i = 0 ; i < n ; i ++ ) {
			if ( a[ i ] != '0' ) {
				c += '1' ;
				a[ i ] -- ;
            }
			else {
				if ( c.size ( ) != 0 ) { c += '0' ; }
            }
        }
		v.push_back ( c ) ;
    }
	int sz = v.size ( ) ;
	cout << sz << "\n" ;
	for ( i = 0 ; i < sz ; i ++ ) {
		cout << v[ i ] ; 
		if ( i == sz - 1 ) { cout << "\n" ; }
		else { cout << " " ; }
    }
}