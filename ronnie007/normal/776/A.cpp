#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
#include<set>
using namespace std ;

string a , b ;

void input ( ) {
	cin >> a >> b ;
	int n ;
	cin >> n ;
	int i ;
	string x , y ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cout << a << " " << b << "\n" ;
		cin >> x >> y ;
		if ( a == x ) {
			a = y ;
		}
		else if ( a == y ) {
			a = x ;
		}
		else if ( b == x ) {
			b = y ;
		}
		else {
			b = x ;
		}
	}
	cout << a << " " << b << "\n" ;
}

void solve ( ) {

}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}