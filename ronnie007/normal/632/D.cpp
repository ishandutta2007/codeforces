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

#define MAXN 1000007

int n , m ;
int a[ MAXN ] ;

int br[ MAXN ] ;

int u[ MAXN ] ;

void input ( ) {
	scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
		if ( a[ i ] > m ) { continue ; }
        br[ a[ i ] ] ++ ;
    }
}

void solve ( ) {
	int i , j ;
    for ( i = 1 ; i <= m ; i ++ ) {
    	for ( j = i ; j <= m ; j += i ) {
        	u[ j ] += br[ i ] ;
        }
    }
    int id = 0 ;
    for ( i = m ; i >= 1 ; i -- ) {
    	if ( u[ i ] >= u[ id ] ) { id = i ; }
    }
    vector < int > v ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	if ( id >= a[ i ] && ( id % a[ i ] ) == 0 ) { v.push_back ( i ) ; }
    }
    int sz = v.size ( ) ;
    printf ( "%d %d\n" , id , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	printf ( "%d" , v[ i ] ) ;
        if ( i == ( sz - 1 ) ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}