#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MAXN 100007

int n , m , q ;
map < string , int > ZX ;

int prv[ 2 * MAXN ] ;

int find ( int x ) {
	if ( prv[ x ] == -1 ) { return x ; }
	int y = find ( prv[ x ] ) ;
	prv[ x ] = y ;
	return y ;
}

void UNITE ( int x , int y ) {
	int k1 = find ( x ) ;
	int k2 = find ( y ) ;
	if ( k1 != k2 ) {
		prv[ k1 ] = k2 ;
	}
}

void input ( ) {
	cin >> n >> m >> q ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		string s ;
		cin >> s ;
		ZX[ s ] = i ;
	}
	for ( i = 1 ; i <= 2 * n ; i ++ ) {
		prv[ i ] = -1 ;
	}
}

void solve ( ) {
	int i ;
	for ( i = 1 ; i <= m ; i ++ ) {
		int x ;
		string a , b ;
		int u1 , u2 ;
		cin >> x >> a >> b ;
		u1 = ZX[ a ] ;
		u2 = ZX[ b ] ;
		if ( x == 1 ) {
			if ( find ( u1 ) == find ( n + u2 ) || find ( n + u1 ) == find ( u2 ) ) {
				cout << "NO\n" ;
			}
			else {
				UNITE ( u1 , u2 ) ;
				UNITE ( n + u1 , n + u2 ) ;
				cout << "YES\n" ;
			}
		}
		else {
			if ( find ( u1 ) == find ( u2 ) || find ( n + u1 ) == find ( n + u2 ) ) {
				cout << "NO\n" ;
			}
			else {
				UNITE ( u1 , n + u2 ) ;
				UNITE ( n + u1 , u2 ) ;			
				cout << "YES\n" ;
			}		
		}
	}
	for ( i = 1 ; i <= q ; i ++ ) {
		string a , b ;
		int u1 , u2 ;
		cin >> a >> b ;
		u1 = ZX[ a ] ;
		u2 = ZX[ b ] ;
		if ( find ( u1 ) == find ( u2 ) || find ( n + u1 ) == find ( n + u2 ) ) { cout << "1\n" ; }
		else if ( find ( u1 ) == find ( n + u2 ) || find ( n + u1 ) == find ( u2 ) ) { cout << "2\n" ; }
		else { cout << "3\n" ; }
	}
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}