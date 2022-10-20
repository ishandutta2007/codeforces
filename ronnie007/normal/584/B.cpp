#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
#include<stack>
using namespace std ;

#define MOD 1000000007
int n ;


void input ( ) ;
void solve ( ) ;

int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> n ;
}

void solve ( ) {
	int i ;
	long long cur1 = 1 ;
	long long cur2 = 1 ;
	for ( i = 1 ; i <=  n ; i ++ ) {
		cur1 *= 27 ;
		cur1 %= MOD ;
		cur2 *= 7 ;
		cur2 %= MOD ;
	}
	cur1 -= cur2 ;
	if ( cur1 < 0 ) { cur1 += MOD ; }
	cout << cur1 << "\n" ;
}