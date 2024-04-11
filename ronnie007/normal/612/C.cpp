#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
using namespace std ;

int n ;
string a ;

int f[ 4 ] ;

void input ( ) {
	cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
	int i ;
    int ans = 0 ;
	stack < int > s ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == '<' || a[ i ] == '{' || a[ i ] == '[' || a[ i ] == '(' ) { s.push ( i ) ; }
        else {
        	if ( s.empty ( ) == true ) { cout << "Impossible\n" ; return ; }
            if ( a[ i ] == '>' ) { a[ i ] = '<' ; }
            if ( a[ i ] == '}' ) { a[ i ] = '{' ; }
            if ( a[ i ] == ']' ) { a[ i ] = '[' ; }
            if ( a[ i ] == ')' ) { a[ i ] = '(' ; }
            if ( a[ s.top ( ) ] == a[ i ] ) { s.pop ( ) ; }
			else { ans ++ ; s.pop ( ) ; }
        }
    }
	if ( s.empty ( ) == false ) { cout << "Impossible\n" ; return ; }
    cout << ans << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}