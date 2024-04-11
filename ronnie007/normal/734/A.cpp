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

void input ( ) {
	cin >> n ;
    cin >> a ;
}

void solve ( ) {
	int i ;
    int br = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
    	if ( a[ i ] == 'A' ) { br ++ ; }
        else { br -- ; }
    }
    if ( br > 0 ) { printf ( "Anton\n" ) ; }
    else if ( br < 0 ) { printf ( "Danik\n" ) ; }
    else { printf ( "Friendship\n" ) ; }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}