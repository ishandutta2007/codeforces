#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<string.h>
#include<set>
using namespace std ;

#define inf 1000000007

int n ;
pair < int , int > a[ 1007 ] ;
pair < int , int > b[ 1007 ] ;
vector < pair < int , int > > srt ;

void input ( ) ;
void solve ( ) ;


int main ( )  {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d" , &n ) ;
	int i ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
		swap ( a[ i ].first , a[ i ].second ) ;
    }
}

void solve ( )  {
	int i , j ;
	int sm = 0 ;
	int br = 0 ;
	int ans = inf ;
	int h ;
	for ( h = 1 ; h <= 1000 ; h ++ ) {
		br = 0 ;
		for ( i = 0 ; i < n ; i ++ ) {
			b[ i ] = a[ i ] ;
        }
		for ( i = 0 ; i < n ; i ++ ) {
			if ( b[ i ].first > h ) { swap ( b[ i ].first , b[ i ].second ) ; br ++ ; }
		}
		for ( i = 0 ; i < n ; i ++ ) {
			if ( b[ i ].first > h ) { break ; }
        }
		if ( br > n / 2 || i != n ) { continue ; }
		srt.clear ( ) ;
		for ( i = 0 ; i < n ; i ++ ) {
			if ( b[ i ].first <= h && b[ i ].second <= h ) {
				if ( b[ i ].first < b[ i ].second ) { srt.push_back ( make_pair ( b[ i ].second - b[ i ].first , i ) ) ; }
            }
        }
		sort ( srt.begin ( ) , srt.end ( ) ) ;
		int id = srt.size ( ) - 1 ;
		while ( 1 ) {
			if ( br == n / 2 ) { break ; }
			if ( id < 0 ) { break ; }
			br ++ ;
			swap ( b[ srt[ id ].second ].first , b[ srt[ id ].second ].second ) ;
			id -- ;
        }
		sm = 0 ;
		for ( i = 0 ; i < n ; i ++ ) { sm += b[ i ].second ; }
		ans = min ( ans , h * sm ) ;
    }
	printf ( "%d\n" , ans ) ;
}