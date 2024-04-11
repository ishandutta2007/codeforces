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
	int i ;
	for ( i = 0 ; i < n - 1 ; i ++ ) {
		if ( ( a[ i ] - '0' ) % 2 == 0 && a[ i ] < a[ n - 1 ] ) {
			swap ( a[ i ] , a[ n - 1 ] ) ;
			cout << a << "\n" ;
			return ; 
        }
    }
	for ( i = n - 1 ; i >= 0 ; i -- ) {
		if ( ( a[ i ] - '0' ) % 2 == 0 ) {
			swap ( a[ i ] , a[ n - 1 ] ) ;
			cout << a << "\n" ;
			return ;
        }
    }
	cout << "-1\n" ;
}