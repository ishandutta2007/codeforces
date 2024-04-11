#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstdio>
#include<set>
#include<stack>
using namespace std ;

#define MAXN 100007
#define MOD 1000000007

int n ;
pair < int , int > prv[ MAXN ] ;
long long sm[ MAXN ] ;
int br[ MAXN ] ;

bool used[ MAXN ] ;

pair < int , int > find ( pair < int , int > x ) {
	if ( prv[ x.first ].first == -1 ) { return x ; }
	else {
		pair < int , int > ret = find ( make_pair ( prv[ x.first ].first , ( prv[ x.first ].second + x.second ) % MOD ) ) ;
		prv[ x.first ].first = ret.first ;
		prv[ x.first ].second = ( ret.second - x.second + MOD ) % MOD ;
		return ret ;
	}
}

void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		prv[ i ].first= -1 ;
		prv[ i ].second = 0 ;
		br[ i ] = 1 ;
		sm[ i ] = 0 ;
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		int sz ;
		int x , y ;
		scanf ( "%d" , &sz ) ;
		while ( sz != 0 ) {
			sz -- ;
			scanf ( "%d%d" , &x , &y ) ;
			if ( y < 0 ) { y += MOD ; }
			pair < int , int > p ;
			p = find ( make_pair ( x , 0 ) ) ;
			sm[ i ] += sm[ p.first ] ;
			sm[ i ] %= MOD ;			
			br[ i ] += br[ p.first ] ;
			sm[ i ] += p.second + y ;
			sm[ i ] %= MOD ;
			prv[ p.first ].first = i ;
			prv[ p.first ].second = ( p.second + y ) % MOD ;
		}
	}
}

void solve ( ) {
	int i ;
	long long ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		int k = find ( make_pair ( i , 0 ) ).first ;
		if ( used[ k ] == false ) { ans = ( ans + sm[ k ] ) % MOD ; }
		used[ k ] = true ;
	}
	printf ( "%d\n" , ans ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}