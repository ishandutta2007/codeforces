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

#define MAXN 200007

int n , k ;
int a[ MAXN ] ;
map < long long , int > ZX ;
map < long long , int > g ;

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
	scanf ( "%d%d" , &n , &k ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		g[ a[ i ] ] ++ ;
    }
}

void solve ( ) {
	long long ans = 0 ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		g[ a[ i ] ] -- ;
		if ( a[ i ] % k == 0 ) {
			long long cur = ZX[ a[ i ] / k ] ;
			long long val = a[ i ] ;
			val *= k ;
			cur *= g[ val ] ;
			ans += cur ;
        }
		ZX[ a[ i ] ] ++ ;
    }
	printf ( "%I64d\n" , ans ) ;
}