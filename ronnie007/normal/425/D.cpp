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
#include<unordered_map>
using namespace std ;

#define MAXN 100007

int n ;
pair < int , int > a[ MAXN ] ;
unordered_map < int , bool > ZX[ MAXN ] ;

vector < int > row[ MAXN ] ;
vector < int > col[ MAXN ] ;

void input ( ) {
	scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        ZX[ a[ i ].first ][ a[ i ].second ] = true ;
        col[ a[ i ].first ].push_back ( a[ i ].second ) ;
        row[ a[ i ].second ].push_back ( a[ i ].first ) ;
    }
    for ( i = 0 ; i <= 100000 ; i ++ ) {
    	sort ( row[ i ].begin ( ) , row[ i ].end ( ) ) ;
        sort ( col[ i ].begin ( ) , col[ i ].end ( ) ) ;
    }
}

void solve ( ) {
	int i ;
    int ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	int x = a[ i ].first ;
        int y = a[ i ].second ;
    	vector < int > :: iterator it1 = upper_bound ( col[ x ].begin ( ) , col[ x ].end ( ) , y ) ;
    	vector < int > :: iterator it2 = upper_bound ( row[ y ].begin ( ) , row[ y ].end ( ) , x ) ;
        if ( distance ( it1 , col[ x ].end ( ) ) < distance ( it2 , row[ y ].end ( ) ) ) {
        	while ( it1 != col[ x ].end ( ) ) {
            	int len = (*it1) - y ;
                if ( ZX[ x + len ][ y ] == true && ZX[ x + len ][ y + len ] == true ) { ans ++ ; }
                it1 ++ ;
            }
        }
        else {
        	while ( it2 != row[ y ].end ( ) ) {
            	int len = (*it2) - x ;
                if ( ZX[ x ][ y + len ] == true && ZX[ x + len ][ y + len ] == true ) { ans ++ ; }
                it2 ++ ;
            }
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