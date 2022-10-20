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

#define MAXN 300007

int n ;
int a[ MAXN ] ;

map < int , int > lst ;

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
	int i , j ;
	i = 1 ;
    vector < pair < int , int > > ans ;
    while ( i <= n ) {
    	for ( j = i ; j <= n ; j ++ ) {
        	int pos = lst[ a[ j ] ] ;
            lst[ a[ j ] ] = j ;
            if ( pos >= i ) { break ; }
        }
        if ( j > n && ans.size ( ) == 0 ) { printf ( "-1\n" ) ; return ; }
        if ( j > n && ans.size ( ) != 0 ) { ans[ ans.size ( ) - 1 ].second = n ; break ; }
        ans.push_back ( make_pair ( i , j ) ) ;
        i = j + 1 ;
    }
    int sz = ans.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
    	printf ( "%d %d\n" , ans[ i ].first , ans[ i ].second ) ;
    }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}