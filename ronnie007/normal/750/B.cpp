#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
using namespace std ;

#define MAXN 57

int n ;

string s[ MAXN ] ;
int u[ MAXN ] ;

void input ( ) {
	cin >> n ;
}

void solve ( ) {
	string a ;
	int val ;
	int x = 0 ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> u[ i ] >> s[ i ] ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		val = u[ i ] ;
		a = s[ i ] ;
		if ( x == 0 && a != "South" ) {
			cout << "NO\n" ;
			return ;
		}
		if ( x == 20000 && a != "North" ) {
			cout << "NO\n" ;
			return ;
		}
		if ( a == "North" ) {
			if ( x - val < 0 ) { cout << "NO\n" ; return ; }
			x -= val ;
		}
		if ( a == "South" ) {
			if ( x + val > 20000 ) { cout << "NO\n" ; return ; }
			x += val ;
		}
	}
	if ( x != 0 ) { cout << "NO\n" ; return ; }
	cout << "YES\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}