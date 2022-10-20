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
int x , s ;
pair < int , int > a[ MAXN ] ;
pair < int , int > b[ MAXN ] ;

void input ( ) {
	scanf ( "%d%d%d" , &n , &m , &k ) ;
    scanf ( "%d%d" , &x , &s ) ;
    int i ;
    for ( i = 1 ; i <= m ; i ++ ) {
    	scanf ( "%d" , &a[ i ].second ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
    	scanf ( "%d" , &a[ i ].first ) ;
    }
    for ( i = 1 ; i <= k ; i ++ ) {
    	scanf ( "%d" , &b[ i ].second ) ;
    }
    for ( i = 1 ; i <= k ; i ++ ) {
    	scanf ( "%d" , &b[ i ].first ) ;
    }
    sort ( a + 1 , a + m + 1 ) ;
}

void solve ( ) {
	int mx = 0 ;
    int i ;
    int id = 1 ;
    int val = 0 ;
    long long ans = -1 ;
    for ( i = m ; i >= 0 ; i -- ) {
    	int lft = s - a[ i ].first ;
        if ( lft < 0 ) { continue ; }
        while ( id <= k && b[ id ].first <= lft ) {
        	if ( val < b[ id ].second ) { val = b[ id ].second ; }
            id ++ ;
        }
        if ( n <= val ) { printf ( "0\n" ) ; return ; }
        long long p = ( n - val ) ;
        long long cur = p * x ;
        if ( ans == -1 || ans > cur ) { ans = cur ; }
        if ( a[ i ].second == 0 ) { continue ; }
        cur = p * a[ i ].second ;
        if ( ans == -1 || ans > cur ) { ans = cur ; }
    }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}