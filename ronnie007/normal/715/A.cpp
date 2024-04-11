#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

int n ;

void input ( ) {
	cin >> n ;
}

void solve ( ) {
	cout << 2 << "\n" ;
    long long i ;
    for ( i = 2 ; i <= n ; i ++ ) {
    	cout << ( i * ( i + 1 ) * ( i + 1 ) - i + 1 ) << "\n" ;
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}