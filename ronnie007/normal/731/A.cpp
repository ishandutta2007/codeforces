#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

int n ;
string a ;


void input ( ) {
	cin >> a ;
    a = 'a' + a ;
    n = a.size ( ) ;
}

void solve ( ) {
	int i ;
    int ans = 0 ;
    for ( i = 1 ; i < n ; i ++ ) {
    	int x = ( a[ i - 1 ] - 'a' ) ;
        int y = ( a[ i ] - 'a' ) ;
        int cur1 = y - x ;
        if ( cur1 < 0 ) { cur1 += 26 ; }
        int cur2 = x - y ;
        if ( cur2 < 0 ) { cur2 += 26 ; }
        ans += min ( cur1 , cur2 ) ;
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