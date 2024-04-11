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
bool a[ MAXN ] ;
vector < int > v[ MAXN ] ;
int br[ MAXN ] ;

long long ans = 0 ;


void dfs ( int vertex , int prv ) {
	int i , sz ;
    sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex ) ;
        br[ vertex ] += br[ v[ vertex ][ i ] ] ;
    }
    if ( a[ vertex ] == true ) { br[ vertex ] ++ ; }
    ans += min ( br[ vertex ] , 2 * k - br[ vertex ] ) ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= 2 * k ; i ++ ) {
    	int x ;
    	scanf ( "%d" , &x ) ;
        a[ x ] = true ;
    }
   	for ( i = 1 ; i <= ( n - 1 ) ; i ++ ) {
    	int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
	dfs ( 1 , -1 ) ;
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}