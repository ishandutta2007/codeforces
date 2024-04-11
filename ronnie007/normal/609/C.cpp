#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
long long sm ;
int b[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    sm = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
        sm += a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
	int i ;
    int cur = ( sm / n ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( n * cur + ( n - i + 1 ) > sm ) { b[ i ] = cur ; }
        else { b[ i ] = cur + 1 ; }
    }
    sm = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	sm += ( abs ( a[ i ] - b[ i ] ) ) ;
    }
    sm /= 2 ;
    cout << sm << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}