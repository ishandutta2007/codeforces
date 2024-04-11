#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
using namespace std ;

#define MAXN 200007
#define inf 2000000007

int n ;
int a[ MAXN ] ;
long long dp[ MAXN ] ;

long long pref[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	pref[ i ] = pref[ i - 1 ] + a[ i ] ;
    }
}

void solve ( ) {
	int i ;
	set < long long > s ;
    set < long long > :: iterator it ;
    for ( i = n ; i >= 1 ; i -- ) {
    	dp[ i ] = pref[ n ] ;
        if ( s.size ( ) != 0 ) {
        	it = s.end ( ) ;
            it -- ;
            long long cur = (*it) ;
            if ( dp[ i ] < cur ) { dp[ i ] = cur ; }
        }
		if ( i >= 3 ) { s.insert ( pref[ i - 1 ] - dp[ i ] ) ; }
    }
    cout << dp[ 1 ] << "\n" ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}