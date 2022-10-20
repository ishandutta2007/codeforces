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
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( )  {
	int i ;
	int br = 0 ;
	vector < int > v ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == '(' ) br ++ ;
		if ( a[ i ] == ')' ) br -- ;
		if ( a[ i ] == '#' ) { br -- ; v.push_back ( 1 ) ; } 
		if ( br < 0 ) {
			printf ( "-1\n" ) ;
			return ;
        }
    }
	int sz = v.size ( ) ;
	v[ sz - 1 ] += br ;
	br = 0 ;
	int ind = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == '(' ) br ++ ;
		if ( a[ i ] == ')' ) br -- ;
		if ( a[ i ] == '#' ) { br -= v[ ind ] ; ind ++ ; } 
		if ( br < 0 ) {
			printf ( "-1\n" ) ;
			return ;
        }		
    }
	for ( i = 0 ; i < sz ; i ++ ) {
		cout << v[ i ] << "\n" ;
    }
}