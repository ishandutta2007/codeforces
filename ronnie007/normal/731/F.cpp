#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

int bg[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
	int i , j ;
    int id = n ;
    long long ans = 0 ;
    for ( i = 200000 ; i >= 1 ; i -- ) {
    	while ( id >= 1 && a[ id ] >= i ) { id -- ; }
        bg[ i ] = ( n - id ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( i != 1 && a[ i ] == a[ i - 1 ] ) { continue ; }
        long long cur = 0 ;
        int st ;
        for ( st = a[ i ] ; st <= 200000 ; st += a[ i ] ) { }
        st -= a[ i ] ;
        int br = 0 ;
		for ( j = st ; j >= a[ i ] ; j -= a[ i ] ) {
        	long long u = ( bg[ j ] - br ) ;
            u *= j ;
            br = bg[ j ] ;
            cur += u ;
        }
        if ( ans < cur ) { ans = cur ; }
    }
    cout << ans << "\n" ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}