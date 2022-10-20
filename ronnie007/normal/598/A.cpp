#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

long long n ;

void input ( ) {
	cin >> n ;
}

void solve ( ) {
	long long st = 1 ;
    while ( st <= n ) { st *= 2 ; }
    long long ans = ( n * ( n + 1 ) / 2 ) - 2 * ( st - 1 ) ;
    cout << ans << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t != 0 ) {
    	t -- ;
		input ( ) ;
		solve ( ) ;
	}
	return 0 ;
}