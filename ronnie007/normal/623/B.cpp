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

#define MAXN 1000007

int n , x , y ;
int a[ MAXN ] ;

long long pref[ MAXN ] ;
long long suff[ MAXN ] ;

long long add[ MAXN ] ;

long long dist[ MAXN ] ;

vector < int > v ;

long long ans = -1 ;

void calc ( int val ) {
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( ( a[ i ] / val ) == ( ( a[ i ] + val - 1 ) / val ) ) { add[ i ] = 0 ; }
		else if ( ( a[ i ] + 1 ) / val == ( ( a[ i ] + 1 + val - 1 ) / val ) ) { add[ i ] = y ; }
		else if ( ( a[ i ] - 1 ) / val == ( ( a[ i ] - 1 + val - 1 ) / val ) ) { add[ i ] = y ; }
		else { add[ i ] = -1 ; }
	}
	pref[ 0 ] = 0 ;	
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( pref[ i - 1 ] == -1 ) { pref[ i ] = -1 ; continue ; }
		if ( add[ i ] == -1 ) { pref[ i ] = -1 ; }
		else {
			pref[ i ] = pref[ i - 1 ] + add[ i ] ;
		}
	}
	suff[ n + 1 ] = 0 ;
	for ( i = n ; i >= 1 ; i -- ) {
		if ( suff[ i + 1 ] == -1 ) { suff[ i ] = -1 ; continue ; }
		if ( add[ i ] == -1 ) { suff[ i ] = -1 ; }
		else {
			suff[ i ] = suff[ i + 1 ] + add[ i ] ;
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( pref[ i ] != -1 ) {
			if ( ans > pref[ i ] + dist[ n - i ] ) { ans = pref[ i ] + dist[ n - i ] ; }
		}
		if ( suff[ i ] != -1 ) {
			if ( ans > suff[ i ] + dist[ i - 1 ] ) { ans = suff[ i ] + dist[ i - 1 ] ; }
		}
	}
	pair < long long , int > bst ;
	bst.first = -1 ;
	bst.second = -1 ;
	for ( i = 3 ; i <= n ; i ++ ) {
		if ( pref[ i - 2 ] != -1 ) {
			pair < long long , int > p = make_pair ( pref[ i - 2 ] - dist[ i - 3 ] , i - 2 ) ;
			if ( bst.second == -1 || p.first < bst.first ) {
				bst = p ;
			}
		}
		if ( bst.second == -1 ) { continue ; }
		else {
			if ( suff[ i ] != -1 ) {
				int id = bst.second ;		
				long long u = suff[ i ] + pref[ id ] + dist[ i - id - 1 ] ;
				if ( ans == -1 || ans > u ) { ans = u ; }
			}
		}
	}
}

void div ( int num ) {
	int i ;
	for ( i = 2 ; i * i <= num ; i ++ ) {
		if ( ( num % i ) == 0 ) { calc ( i ) ; }
		while ( ( num % i ) == 0 ) { num /= i ; }
	}
	if ( num > 1 ) { calc ( num ) ; }
}

void input ( ) {
	scanf ( "%d%d%d" , &n , &x , &y ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
	}
}

void solve ( ) {
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		dist[ i ] = dist[ i - 1 ] + x ;
	}
 	ans = dist[ n - 1 ] ;
	div ( a[ 1 ] - 1 ) ;
	div ( a[ 1 ] ) ;
	div ( a[ 1 ] + 1 ) ;

	div ( a[ n ] - 1 ) ;
	div ( a[ n ] ) ;
	div ( a[ n ] + 1 ) ;
	cout << ans << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}