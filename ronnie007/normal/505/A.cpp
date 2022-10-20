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

string rev ( string x ) {
	string ret ;
	ret.clear ( ) ;
	int i ;
	int sz = x.size ( ) ;
	for ( i = sz - 1 ; i >= 0 ; i -- ) {
		ret += x[ i ] ; 
    }
	return ret ;
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


void input ( )  {
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( )  {
	int i , j , t ;
	string b , c , d ;
	b.clear ( ) ;
	for ( i = 0 ; i <= n ; i ++ ) {
		for ( j = 0 ; j < 26 ; j ++ ) {
			c = b ;
			c += ( j + 'a' ) ;
			for ( t = i ; t < n ; t ++ ) {
				c += a[ t ] ; 
            }
			d = rev ( c ) ;
			if ( c == d ) { cout << c << "\n" ; return ; } 
        }
		if ( i != n ) { b += a[ i ] ; } 
    }
	cout << "NA\n" ;
}