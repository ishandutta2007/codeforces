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

long long st , en , k ;
int n ;
long long a[ MAXN ] ;

long long ans = -1 ;

long long get ( long long tm , long long init ) {
	return max ( 0LL , ( init - tm ) ) ;
}

void input ( ) {
	cin >> st >> en >> k ;
	cin >> n ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ] ;
	}
}

void solve ( ) {
	int i ;
	long long cur = st ;
	long long id = -1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( a[ i ] == a[ i - 1 ] ) { cur += k ; continue ; }
		else {
			if ( ( cur + k ) <= en ) {
				long long ret = get ( a[ i ] - 1 , cur ) ;
				if ( ans == -1 || ans > ret ) { ans = ret ; id = a[ i ] - 1 ; }
				if ( ( cur + k ) < a[ i ] - 1 ) { ans = 0 ; id = cur ; }
			}
			if ( cur < a[ i ] ) { cur = a[ i ] ; }
			cur += k ;
		}
	}
	if ( ( cur + k ) <= en ) { ans = 0 ; id = cur ; }
	cout << id << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}