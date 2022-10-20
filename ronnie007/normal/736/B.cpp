#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

long long n ;

bool pr ( long long x ) {
	long long i ;
	for ( i = 2 ; i * i <= x ; i ++ ) {
		if ( ( x % i ) == 0 ) { return false ; }
	}
	return true ;
}

void input ( ) {
	cin >> n ;
}

void solve ( ) {
	if ( pr ( n ) == true ) { cout << "1\n" ; return ; }
	if ( ( n % 2 ) == 0 ) { cout << "2\n" ; return ; }
	if ( pr ( n - 2 ) == true ) { cout << "2\n" ; return ; }
	cout << "3\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}