#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

#define MOD 1000000007
#define MAXN 1007

int n ;
int a[ MAXN ] ;
long long dp[ MAXN ] ;

void input ( ) {
	cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	cin >> a[ i ] ;
    }
}

void solve ( ) {
	int i , j ;
    long long ans = 0 ;
	for ( i = 1 ; i <= n ; i ++ ) {
    	dp[ i ] = 2 ;
        for ( j = a[ i ] ; j < i ; j ++ ) {
        	dp[ i ] += dp[ j ] ;
            dp[ i ] %= MOD ;
        }
        ans += dp[ i ] ;
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