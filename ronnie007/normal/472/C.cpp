#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
using namespace std ;

int n ;

string a[ 100007 ] ;
string b[ 100007 ] ;

int p[ 100007 ] ; 

void input ( ) ;
void solve ( ) ;



int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	cin >> n ; 
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ] >> b[ i ] ; 
		if ( a[ i ] > b[ i ] ) swap ( a[ i ] , b[ i ] ) ;
	}
	for ( i = 0 ; i < n ; i ++ ) cin >> p[ i ] ; 
}

void solve ( ) {
	int i ;
	string lst ; 
	lst = a[ p[ 0 ] ] ;
	for ( i = 1 ; i < n ; i ++ ) {
		if ( a[ p[ i ] ] > lst ) {
			lst = a[ p[ i ] ] ;
		}
		else if ( b[ p[ i ] ] > lst ) {
			lst = b[ p[ i ] ] ;
		}
		else break ;
	}
	if ( i != n ) printf ( "NO\n" ) ;
	else printf ( "YES\n" ) ;
}