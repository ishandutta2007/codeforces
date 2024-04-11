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

int n , a , b , k ;


void input ( ) {
	cin >> n >> k >> a >> b ;
}

void solve ( ) {
	int br1 , br2 ;
	br1 = br2 = 0 ;
	int i ;
	string ret ;
	ret.clear ( ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		if ( a < 0 || b < 0 ) { cout << "NO\n" ; return ; }
		if ( br1 == k ) {
			br1 = 0 ;
			br2 = 1 ;
			ret += 'B' ;
			b -- ;
			continue ;
		}
		if ( br2 == k ) {
			br1 = 1 ;
			br2 = 0 ;
			ret += 'G' ;
			a -- ;
			continue ;
		}
		if ( a >= b ) {
			br1 ++ ;
			ret += 'G' ;
			a -- ;
		}
		else {
			br2 ++ ;
			ret += 'B' ;
			b -- ;
		}
	}
	if ( a < 0 || b < 0 ) { cout << "NO\n" ; return ; }
	cout << ret << "\n" ;
}

int main ( ) {
	input ( ) ;
	solve ( ) ;
	return 0 ;
}