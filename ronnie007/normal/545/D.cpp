#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
using namespace std ;

#define inf 1000000007
#define MAXN 100007

int n ;

int a[ MAXN ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) { scanf ( "%d" , &a[ i ] ) ; }
	sort ( a , a + n ) ;
}
 
void solve ( )  {
	int i ;
	int sm = 0 ;
	int ans = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( sm > inf || sm > a[ i ] ) { 
			ans ++ ; 
        }
		else { sm += a[ i ] ; }
    }
	printf ( "%d\n" , ( n - ans ) ) ;
}