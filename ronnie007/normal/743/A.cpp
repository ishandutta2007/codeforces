#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

int n , a , b ;
string s ;

void input ( ) {
	cin >> n >> a >> b ;
	cin >> s ;
}

void solve ( ) {
	a -- ; b -- ;
	if ( s[ a ] == s[ b ] ) { cout << "0\n" ; }
	else { cout << "1\n" ; }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}