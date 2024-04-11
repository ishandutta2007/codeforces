#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std ;

#define MOD 1000000007

int n ;
string a ;

int dp[ 77 ][ 1200000 ] ;

int dfs ( int pos , int mask ) {
	if ( dp[ pos ][ mask ] != 0 ) { return dp[ pos ][ mask ] - 1 ; }
	int i ;
	int ret = 0 ;
	if ( mask != 0 && (mask&(mask+1)) == 0 ) { ret ++ ; }
	int num = 0 ;
	for ( i = pos ; i < n ; i ++ ) {
		num = ( num * 2 + ( a[ i ] - '0' ) ) ;
		if ( num > 20 ) { break ; }
		if ( num != 0 ) {
			ret += dfs ( i + 1 , (mask|(1<<(num-1))) ) ;
			ret %= MOD ;
		}
	}
	dp[ pos ][ mask ] = ret + 1 ;
	return ret ;
}

void input ( ) {
	cin >> n ;
	cin >> a ;
}

void solve ( ) {
	int i ;
	int ans = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		ans += dfs ( i , 0 ) ;
		ans %= MOD ;
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