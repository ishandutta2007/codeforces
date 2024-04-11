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

#define MAXN 100007

long long inf = 1000000007 ;

int n ;
long long k ;
long long a[ MAXN ] ;
long long pref[ MAXN ] ;

long long ans = 0 ;

map < long long , int > ZX ;

void calc ( long long cur ) {
	int i ;
	ZX.clear ( ) ;
	ZX[ 0 ] = 1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		long long x = pref[ i ] - cur ;
		ans += ZX[ x ] ;
		ZX[ pref[ i ] ] ++ ;
	}
}

void input ( ) {
	cin >> n >> k ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ] ;
		pref[ i ] = ( pref[ i - 1 ] + a[ i ] ) ;
	}
}

void solve ( ) {
	int i ;
	int st ;
	if ( k == 1 ) { st = 0 ; }
	else if ( k == -1 ) { st = 1 ; }
	else { st = 100 ; }
	long long sr = 1LL * MAXN * inf ;
	long long cur = 1 ;
	for ( i = 0 ; i <= st ; i ++ ) {
		if ( cur > sr || cur < -sr ) { break ; }
		calc ( cur ) ;
		cur *= k ;
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