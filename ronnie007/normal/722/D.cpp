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

#define MAXN 50007

int n ;
int a[ MAXN ] ;

vector < int > lst ;

map < int , int > ZX ;

bool f ( int x ) {
	int i ;
    ZX.clear ( ) ;
    vector < int > ret ;
    ret.clear ( ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	int u = a[ i ] ;
        while ( u != 0 ) {
            if ( u <= x ) {
            	if ( ZX.find ( u ) == ZX.end ( ) ) { ZX[ u ] = 1 ; ret.push_back ( u ) ; break ; }
            }
        	u /= 2 ;            
        }
        if ( u == 0 ) { return false ; }
    }
    lst = ret ;
    return true ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
	int l , r , mid ;
    l = 1 ;
    r = 1000000007 ;
    while ( r - l > 3 ) {
    	mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { l ++ ; }
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
    	printf ( "%d" , lst[ i ] ) ;
        if ( i == ( n - 1 ) ) { printf ( "\n" ) ; }
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