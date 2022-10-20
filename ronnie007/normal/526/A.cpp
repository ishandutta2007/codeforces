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
	cin >> n ;
	cin >> a ;
}

void solve ( )  {
	int i , j ;
	for ( i = 1 ; i <= n ; i ++ ) {
		for ( j = 0 ; j + 4 * i < n ; j ++ ) {
			if ( a[ j ] == '.' ) { continue ; }
			if ( a[ j + i ] == '.' ) { continue ; }
			if ( a[ j + i + i ] == '.' ) { continue ; }
			if ( a[ j + i + i + i ] == '.' ) { continue ; }
			if ( a[ j + i + i + i + i ] == '.' ) { continue ; }
			cout << "yes\n" ;
			return ; 
        }
    }
	cout << "no\n" ;
}