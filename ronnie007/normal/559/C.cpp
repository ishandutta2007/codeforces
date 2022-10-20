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

#define MOD 1000000007
#define MAXW 300007
#define MAXN 2007

int h , w , n ;

vector < pair < int , int > > v ;

long long dp[ MAXN ] ;

long long fac[ MAXW ] ;
long long inv[ MAXW ] ;

long long FASTPOW ( long long a , long long x ) {
	long long r = 1 ;
	while ( x != 0 ) {
		if ( x % 2 == 0 ) {
			a = a * a ;
			a %= MOD ;
			x /= 2 ;
        }
		else {
			r = r * a ;
			r %= MOD ;
			x -- ;
        }
    }
	return r ;
}

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
	scanf ( "%d%d%d" , &h , &w , &n ) ;
	v.resize ( n ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &v[ i ].first , &v[ i ].second ) ;
    }
	v.push_back ( make_pair ( h , w ) ) ;
	sort ( v.begin ( ) , v.end ( ) ) ;
}

void solve ( ) {
	int i , j ;
	long long cur = 1 ;
	fac[ 0 ] = inv[ 0 ] = 1 ;
	for ( i = 1 ; i < MAXW ; i ++ ) {
		cur *= i ;
		cur %= MOD ;
		fac[ i ] = cur ;
		inv[ i ] = FASTPOW ( cur , MOD - 2 ) ;
    }
	dp[ 0 ] = fac[ v[ 0 ].first + v[ 0 ].second - 2 ] * inv[ v[ 0 ].first - 1 ] ;
	dp[ 0 ] %= MOD ;
	dp[ 0 ] *= inv[ v[ 0 ].second - 1 ] ;
	dp[ 0 ] %= MOD ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cur = fac[ v[ i ].first + v[ i ].second - 2 ] ;
		cur *= inv[ v[ i ].first - 1 ] ;
		cur %= MOD ;
		cur *= inv[ v[ i ].second - 1 ] ;
		cur %= MOD ;
		for ( j = i - 1 ; j >= 0 ; j -- ) {
			if ( v[ j ].first > v[ i ].first || v[ j ].second > v[ i ].second ) { continue ; }
			long long g ;
			g = fac[ v[ i ].first + v[ i ].second - v[ j ].first - v[ j ].second ] ;
			g *= inv[ v[ i ].first - v[ j ].first ] ;
			g %= MOD ;
			g *= inv[ v[ i ].second - v[ j ].second ] ;
			g %= MOD ;
			g *= dp[ j ] ;
			g %= MOD ;
			cur = ( cur + MOD - g ) % MOD ;
        }
		dp[ i ] = cur ;
    }
	printf ( "%I64d\n" , dp[ n ] ) ;
}