#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
using namespace std ;

long long n , k ;

void input ( ) {
	cin >> n >> k ;
}

void solve ( ) {
	long long ans = 0 ;
	while ( ( k % 2 ) == 0 ) { k /= 2 ; ans ++ ; }
	ans ++ ;
	cout << ans << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}