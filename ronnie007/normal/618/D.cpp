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

#define MAXN 200007

int n , x , y ;
vector < int > v[ MAXN ] ;

bool f[ MAXN ] ;

int dfs ( int vertex , int par ) {
	int i ;
	int sz = v[ vertex ].size ( ) ;
    int ret = 0 ;
    int br = 0 ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	if ( v[ vertex ][ i ] == par ) { continue ; }
        ret += dfs ( v[ vertex ][ i ] , vertex ) ;
        if ( f[ v[ vertex ][ i ] ] == true ) { br ++ ; }        
    }
    if ( br == 0 ) { f[ vertex ] = true ; return ret ; }
    else if ( br == 1 ) { ret ++ ; f[ vertex ] = true ; return ret ; }
    else { ret += 2 ; f[ vertex ] = false ; return ret ; }

}

void input ( ) {
	scanf ( "%d%d%d" , &n , &y , &x ) ;
	int i ;
    int x , y ;
    for ( i = 1 ; i <= n - 1 ; i ++ ) {
    	scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
	int i ;
	if ( x <= y ) {
    	for ( i = 1 ; i <= n ; i ++ ) {
        	if ( v[ i ].size ( ) == ( n - 1 ) ) { break ; }
        }
        if ( i <= n ) {
            printf ( "%I64d\n" , 1LL * ( n - 2 ) * x + y ) ;
        }
        else { printf ( "%I64d\n" , 1LL * ( n - 1 ) * x ) ; }
        return ;
    }
    int u = dfs ( 1 , -1 ) ;
    printf ( "%I64d\n" , 1LL * u * y + 1LL * ( n - 1 - u ) * x ) ;
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}