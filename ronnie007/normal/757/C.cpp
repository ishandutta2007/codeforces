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

#define MAXN 1000007
#define MOD 1000000007

int n , m ;
int a[ MAXN ] ;
long long comp[ MAXN ] ;
bool vis[ MAXN ] ;

int br[ MAXN ] ;

long long fac[ MAXN ] ;

map < long long , long long > ZX ;

long long id = 0 ;

vector < int > v[ MAXN ] ;

void calc ( int pr ) {
	ZX.clear ( ) ;
	int sz = v[ pr ].size ( ) ;
	int i ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( ZX.find ( comp[ v[ pr ][ i ] ] ) != ZX.end ( ) ) {
			comp[ v[ pr ][ i ] ] = ZX[ comp[ v[ pr ][ i ] ] ] ;
		}
		else {
			id ++ ;
			ZX[ comp[ v[ pr ][ i ] ] ] = id ;
			comp[ v[ pr ][ i ] ] = id ;
		}
	}
	ZX.clear ( ) ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
	int i , j ;
	for ( i = 1 ; i <= m ; i ++ ) {
		comp[ i ] = 0 ;
		v[ i ].clear ( ) ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		int sz ;
		scanf ( "%d" , &sz ) ;
		for ( j = 0 ; j < sz ; j ++ ) {
			scanf ( "%d" , &a[ j ] ) ;
			br[ a[ j ] ] ++ ;
		}
		for ( j = 0 ; j < sz ; j ++ ) {
			if ( vis[ a[ j ] ] == 0 ) {
				vis[ a[ j ] ] = 1 ;
				v[ br[ a[ j ] ] ].push_back ( a[ j ] ) ;
			}
		}	
		for ( j = 0 ; j < sz ; j ++ ) {
			vis[ a[ j ] ] = 0 ;
		}
		for ( j = 0 ; j < sz ; j ++ ) {
			if ( vis[ br[ a[ j ] ] ] == 0 ) {
				vis[ br[ a[ j ] ] ] = 1 ;
				calc ( br[ a[ j ] ] ) ;
			}
		}
		for ( j = 0 ; j < sz ; j ++ ) {
			vis[ br[ a[ j ] ] ] = 0 ;
		}
		for ( j = 0 ; j < sz ; j ++ ) {
			if ( vis[ a[ j ] ] == 0 ) {
				vis[ a[ j ] ] = 1 ;
				v[ br[ a[ j ] ] ].pop_back ( ) ;
			}
		}
		for ( j = 0 ; j < sz ; j ++ ) {
			vis[ a[ j ] ] = 0 ;
		}	
		for ( j = 0 ; j < sz ; j ++ ) {
			br[ a[ j ] ] -- ;
		}
	}
}

void solve ( ) {
	int i ;
	fac[ 0 ] = 1 ;
	for ( i = 1 ; i <= m ; i ++ ) {
		fac[ i ] = ( fac[ i - 1 ] * i ) % MOD ;
	}
	sort ( comp + 1 , comp + m + 1 ) ;
	int br = 1 ;
	long long ans = 1 ;
	for ( i = 2 ; i <= m ; i ++ ) {
		if ( comp[ i ] == comp[ i - 1 ] ) { br ++ ; }
		else {
			ans *= fac[ br ] ;
			ans %= MOD ;
			br = 1 ;
		}
	}
	if ( br != 1 ) {
		ans *= fac[ br ] ;
		ans %= MOD ;
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