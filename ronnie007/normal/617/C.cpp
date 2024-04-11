#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std ;

#define MAXN 2007

int n ;
pair < long long , long long > st1 , st2 ;
pair < long long , long long > a[ MAXN ] ;

long long d1[ MAXN ] ;
long long d2[ MAXN ] ;

void input ( ) {
	cin >> n ;
	cin >> st1.first >> st1.second ;
	cin >> st2.first >> st2.second ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ].first >> a[ i ].second ;
		d1[ i ] = ( a[ i ].first - st1.first ) * ( a[ i ].first - st1.first ) + ( a[ i ].second - st1.second ) * ( a[ i ].second - st1.second ) ;
		d2[ i ] = ( a[ i ].first - st2.first ) * ( a[ i ].first - st2.first ) + ( a[ i ].second - st2.second ) * ( a[ i ].second - st2.second ) ;
	}
}

void solve ( ) {
	int i , j ;
	long long cur = 0 ;
	long long ans = -1 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cur = 0 ;
		for ( j = 1 ; j <= n ; j ++ ) {
			if ( d1[ j ] > d1[ i ] ) {
				cur = max ( cur , d2[ j ] ) ;
			}
		}
		cur += d1[ i ] ;
		if ( ans == -1 || ans > cur ) { ans = cur ; }
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		cur = 0 ;
		for ( j = 1 ; j <= n ; j ++ ) {
			if ( d2[ j ] > d2[ i ] ) {
				cur = max ( cur , d1[ j ] ) ;
			}
		}
		cur += d2[ i ] ;
		if ( ans == -1 || ans > cur ) { ans = cur ; }
	}
	cout << ans << "\n" ; 
}


int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}