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
string a , b ;
string c ;

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
	cin >> a >> b ;
	n = a.size ( ) ;
}

void solve ( )  {
	int i ;
	int fl = 1 ;
	c.clear ( ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( fl == 0 ) { c += 'a' ; }
		else if ( fl == 1 ) {
			if ( ( a[ i ] - 'a' ) + 1 < ( b[ i ] - 'a' ) ) { c += ( ( ( a[ i ] - 'a' ) + 1 ) + 'a' ) ; fl = 0 ; }
			else if ( ( a[ i ] - 'a' ) + 1 == ( b[ i ] - 'a' ) ) { c += a[ i ] ; fl = 2 ; }
			else { c += a[ i ] ; } 
        }
		else {
			if ( a[ i ] == 'z' ) { c += 'z' ; }
			else { fl = 0 ; c += 'z' ; }
        }
    }
	if ( fl == 0 ) { cout << c << "\n" ; return ; }
		fl = 1 ; 
		c.clear ( ) ;
		for ( i = 0 ; i < n ; i ++ ) {
			if ( fl == 0 ) { c += 'a' ; }
			else if ( fl == 1 ) {
				if ( ( a[ i ] - 'a' ) + 1 < ( b[ i ] - 'a' ) ) { c += ( ( ( a[ i ] - 'a' ) + 1 ) + 'a' ) ; fl = 0 ; }
				else if ( ( a[ i ] - 'a' ) + 1 == ( b[ i ] - 'a' ) ) { c += b[ i ] ; fl = 2 ; }
				else { c += a[ i ] ; } 
    	    }
			else {
				if ( b[ i ] == 'a' ) { c += 'a' ; }
				else { fl = 0 ; c += 'a' ; }
	        }
    	}
		if ( fl != 0 ) { cout << "No such string\n" ; }
		else { cout << c << "\n" ; }

}