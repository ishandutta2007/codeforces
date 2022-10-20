#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<ctime>
using namespace std ;

#define MAXN 1007

#define MOD 1000000007

int n ; 
long long fac[ MAXN ] ;
int a[ MAXN ] ;

long long p = 0 ;

long long fpow ( long long val , long long x ) {
	long long r = 1 ;
	while ( x != 0 ) {
		if ( x % 2 == 0 ) { val = val * val ; val %= MOD ; x /= 2 ; }
		else { r = r * val ; r %= MOD ; x -- ; }
    }
	return r ;
}

long long get ( int x , int y ) {
	long long ret ;
	ret = fac[ x ] * ( ( fpow ( fac[ y ] , MOD - 2 ) ) * ( fpow ( fac[ x - y ] , MOD - 2 ) ) % MOD ) % MOD ;
	return ret ;
}


void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	p = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
		p += a[ i ] ;
    }
	fac[ 0 ] = 1 ;
	for ( i = 1 ; i <= p ; i ++ ) { fac[ i ] = fac[ i - 1 ] * i ; fac[ i ] %= MOD ; }
}

void solve ( )  {
	int i ;
	long long ans = 1 ;
	for ( i = n - 1 ; i >= 0 ; i -- ) {
		ans = ans * ( get ( p - 1 , a[ i ] - 1 ) ) ;
		ans %= MOD ;
		p -= a[ i ] ;
    }
	printf ( "%I64d\n" , ans ) ;
}