#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<stack>
#include<map>
using namespace std ;

#define MAXN 200007

int n , m , k ;
int a[ MAXN ] ;

vector < int > v[ MAXN ] ;
bool used1[ MAXN ] ;
bool used2[ MAXN ] ;
int br[ MAXN ] ;

int compsz = 0 ;
int mx = 0 ;

void unmark ( int vertex ) {
	used2[ vertex ] = true ;
    compsz ++ ;
    if ( mx < br[ a[ vertex ] ] ) { mx = br[ a[ vertex ] ] ; }
    br[ a[ vertex ] ] -- ;
   	int i , sz ;
    sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	int h = v[ vertex ][ i ] ;
        if ( used2[ h ] == false ) { unmark ( h ) ; }
    }
}

void dfs ( int vertex ) {
	used1[ vertex ] = true ;
	int sz , i ;
    sz = v[ vertex ].size ( ) ;
    br[ a[ vertex ] ] ++ ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	int h = v[ vertex ][ i ] ;
        if ( used1[ h ] == false ) { dfs ( h ) ; }
    }
}

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
    	int x , y ; 
    	scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
	int i ;
    int ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( used1[ i ] == false ) {
        	dfs ( i ) ;
            compsz = mx = 0 ;
            unmark ( i ) ;
            ans += ( compsz - mx ) ;
        }
    }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}