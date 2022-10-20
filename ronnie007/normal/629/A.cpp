#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std ;

#define MAXN 107

int n ;
int br1[ MAXN ] ;
int br2[ MAXN ] ;

void input ( ) {
	cin >> n ;
	int i , j ;
	string a ;
	for ( i = 0 ; i < n ; i ++ ) {
		cin >> a ;
		for ( j = 0 ; j < n ; j ++ ) {
			if ( a[ j ] == 'C' ) { br1[ i ] ++ ; br2[ j ] ++ ; }
		}
	}
}

void solve ( ) {
	int ans = 0 ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		ans += ( br1[ i ] * ( br1[ i ] - 1 ) ) / 2 ;
		ans += ( br2[ i ] * ( br2[ i ] - 1 ) ) / 2 ;
	}
	cout << ans << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}