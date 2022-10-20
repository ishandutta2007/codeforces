#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

#define MOD 1000000007

int n ;
string a ;
int br[ 37 ] ;

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
	cin >> a ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) { br[ a[ i ] - 'A' ] ++ ; }
}

void solve ( ) {
	int mx = 0 ;
	int u = 0 ;
	int i ;
	for ( i = 0 ; i < 26 ; i ++ ) {
		if ( mx < br[ i ] ) { mx = br[ i ] ; }
	}
	for ( i = 0 ; i < 26 ; i ++ ) {
		if ( mx == br[ i ] ) { u ++ ; }
	}
	long long ret = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) { ret *= u ; ret %= MOD ; }
	printf ( "%I64d\n" , ret ) ;
}