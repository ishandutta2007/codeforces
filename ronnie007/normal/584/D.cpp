#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<set>
using namespace std ;

int n ;

bool isprime ( int x ) {
	int i ;
	for ( i = 2 ; i * i <= x ; i ++ ) {
		if ( x % i == 0 ) { return false ; }
	}
	return true ;
}

void input ( ) ;
void solve ( ) ;

int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	cin >> n ;
}
 
void solve ( ) {
	if ( n == 3 ) {
		cout << "1\n" ;
		cout << "3\n" ;
		return ;
	}
	if ( n == 5 ) {
		cout << "2\n" ;
		cout << "2 3\n" ;
		return ;
	}
	int br = 0 ;
	vector < int > v ;
	int i , j ;
	int u ;
	for ( i = 2 ; i <= 160 ; i ++ ) {
		if ( isprime ( i ) == true ) { br ++ ; v.push_back ( i ) ; }
	}

	for ( i = 0 ; i < br ; i ++ ) {
		for ( j = i ; j < br ; j ++ ) {
			u = n - v[ i ] - v[ j ] ;
			if ( u < 0 ) { continue ; }
			if ( u == 0 ) {
				cout << "2\n" ;
				cout << v[ i ] << " " << v[ j ] << "\n" ;
				return ;
			}
			if ( isprime ( u ) == true ) {
				cout << "3\n" ;
				cout << v[ i ] << " " << v[ j ] << " " << u << "\n" ;
				return ;
			}
		}
	}
}