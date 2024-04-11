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
	int i , j , t ;
	string c ;
	for ( i = 0 ; i < n ; i ++ ) {
		for ( j = i ; j < n ; j ++ ) {
			c.clear ( ) ;
			for ( t = 0 ; t < i ; t ++ ) { c += a[ t ] ; }
			for ( t = j + 1 ; t < n ; t ++ ) { c += a[ t ] ; }
			if ( c == "CODEFORCES" ) { cout << "YES\n" ; return ; }
        }
    }
	cout << "NO\n" ;
}