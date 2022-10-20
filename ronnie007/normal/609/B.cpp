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

int n , k ;
int a[ MAXN ] ;
long long br[ MAXN ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
        br[ a[ i ] ] ++ ;
    }
}

void solve ( ) {
	int i , j ;
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	for ( j = 1 ; j <= k ; j ++ ) {
        	if ( a[ i ] == j ) { continue ; }
            ans += br[ j ] ;
        }
    }
	cout << ( ans / 2 ) << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}