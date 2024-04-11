#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

#define MAXN 100007
int n ;
pair < int , int > a[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
}

void solve ( ) {
	int i ;
    int x , y ;
    int mx ;
    int id = 0 ;
    x = y = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	x += a[ i ].first ;
        y += a[ i ].second ;
    }
    mx = abs ( x - y ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	x = x - a[ i ].first + a[ i ].second ;
        y = y - a[ i ].second + a[ i ].first ;
        int cur = abs ( x - y ) ;
        x = x - a[ i ].second + a[ i ].first ;
        y = y - a[ i ].first + a[ i ].second ;
        if ( cur > mx ) { mx = cur ; id = i ; }
    }
    printf ( "%d\n" , id ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}