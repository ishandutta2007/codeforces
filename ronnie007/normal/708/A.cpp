#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
using namespace std ;

int n ;
string a ;

void input ( ) {
	cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
	int i ;
    int l , r ;
    l = r = -1 ;
   	for ( i = 0 ; i < n ; i ++ ) {
    	if ( a[ i ] != 'a' ) {
        	l = i ;
			for ( r = l + 1 ; r < n ; r ++ ) {
            	if ( a[ r ] == 'a' ) { break ; }
            }
            r -- ;
            break ;
		}
    }
    if ( l == -1 && r == -1 ) {
    	for ( i = 0 ; i < n - 1 ; i ++ ) { cout << "a" ; }
        cout << "z\n" ;
        return ;
    }
    for ( i = l ; i <= r ; i ++ ) {
    	a[ i ] = char( ( ( ( a[ i ] - 'a' ) - 1 ) + 'a' ) ) ;
   	}
    cout << a << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}