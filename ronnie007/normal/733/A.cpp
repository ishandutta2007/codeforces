#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

int n ;
string a ;

vector < int > v ;

void input ( ) {
	cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
	int i ;
    v.push_back ( 0 ) ;
    for ( i = 0 ; i < n ; i ++ ) {
    	if ( a[ i ] == 'A' || a[ i ] == 'E' || a[ i ] == 'I' || a[ i ] == 'O' || a[ i ] == 'U' || a[ i ] == 'Y' ) { v.push_back ( i + 1 ) ; }
    }
    v.push_back ( n + 1 ) ;
    int sz = v.size ( ) ;
    int ans = 0 ; 
    for ( i = 1 ; i < sz ; i ++ ) {
    	ans = max ( ans , ( v[ i ] - v[ i - 1 ] ) ) ;
    }
    cout << ans << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}