#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

#define MAXN 200007

int n ;
int pos[ MAXN ] ;

void input ( ) {
	cin >> n ;
    int i ;
    int x ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	cin >> x ;
        pos[ x ] = i ;
    }
}

void solve ( ) {
	int i ;
	long long ans = 0 ;
    for ( i = 2 ; i <= n ; i ++ ) {
    	ans += ( abs ( pos[ i ] - pos[ i - 1 ] ) ) ;
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