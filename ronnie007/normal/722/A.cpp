#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

int x ;
string a ;

void input ( ) {
	cin >> x ;
    cin >> a ;
}

void solve ( ) {
	if ( ( a[ 3 ] - '0' ) >= 6 ) { a[ 3 ] = '0' ; }
    int h = 10 * ( a[ 0 ] - '0' ) + ( a[ 1 ] - '0' ) ;    
    if ( x == 24 ) {
        if ( h >= 24 ) { a[ 0 ] = '0' ; }
    }
    else {
    	if ( h > 12 ) {
        	if ( a[ 1 ] != '0' ) { a[ 0 ] = '0' ; }
            else { a[ 0 ] = '1' ; }
        }
        else if ( h == 0 ) {
        	a[ 0 ] = '1' ; 
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