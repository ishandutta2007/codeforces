#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std ;

#define MAXN 100007

int n ;
long long a[ MAXN ] ;

long long br ;
long long sm ;


void input ( ) {
	cin >> n ;
	int i ;
	br = 0 ;
	sm = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ] ; 
		br += ( a[ i ] % 2 ) ;
		sm += a[ i ] ; 
	}
	sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
	int i ;
	br %= 2 ;
	if ( br == 1 ) {
		for ( i = 1 ; i <= n ; i ++ ) {
			if ( ( a[ i ] % 2 ) == 1 ) {
				sm -= a[ i ] ;
				break ;
			}
		}
	}
	cout << sm << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}