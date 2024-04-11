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

#define MAXN 500007

int n , q ;
int a[ MAXN ] ;

vector < int > v[ MAXN ] ;

bool f[ MAXN ] ;

long long ans = 0 ;

int tot = 0 ;

int br[ MAXN ] ;

void add ( int x , int val ) {
	int sz = v[ x ].size ( ) ;
    int mask ;
    int i ;
    for ( mask = 1 ; mask < (1<<sz) ; mask ++ ) {
    	int h = 1 ;
    	for ( i = 0 ; i < sz ; i ++ ) {
        	if ( (mask&(1<<i)) != 0 ) { h *= v[ x ][ i ] ; }
        }
        br[ h ] += val ;
    }
}

int w ( int x ) {
	int sz = v[ x ].size ( ) ;
    int mask ;
    int i ;
    int ret = 0 ;
    for ( mask = 1 ; mask < (1<<sz) ; mask ++ ) {
    	int h = 1 ;
        int cnt = 0 ;
    	for ( i = 0 ; i < sz ; i ++ ) {
        	if ( (mask&(1<<i)) != 0 ) { h *= v[ x ][ i ] ; cnt ++ ; }
        }
        if ( ( cnt % 2 ) == 1 ) { ret += br[ h ] ; }
        else { ret -= br[ h ] ; }
    }
    return ret ;
}

void input ( ) {
	scanf ( "%d%d" , &n , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
	int i , j ;
    int lim = 500000 ;
    for ( i = 2 ; i <= lim ; i ++ ) {
    	if ( v[ i ].size ( ) != 0 ) { continue ; }
        for ( j = i ; j <= lim ; j += i ) {
        	v[ j ].push_back ( i ) ;
        }
    }
    for ( i = 1 ; i <= lim ; i ++ ) { f[ i ] = false ; }
    int x ;
    while ( q != 0 ) {
	    q -- ;
    	scanf ( "%d" , &x ) ;
		if ( f[ x ] == false ) {
        	f[ x ] = true ;
            ans += ( tot - w ( a[ x ] ) ) ;
            add ( a[ x ] , 1 ) ;
            tot ++ ;
        }
        else {
        	f[ x ] = false ;
            add ( a[ x ] , -1 ) ;
            tot -- ;
            ans -= ( tot - w ( a[ x ] ) ) ;
        }
        printf ( "%I64d\n" , ans ) ;
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}