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

int w , h , n ;
pair < char , int > a[ MAXN ] ;

long long mxw , mxh ;

set < int > rows , cols ;

long long ans[ MAXN ] ;

void input ( ) {
	cin >> w >> h >> n ;
	int i ;
	for ( i = 1 ; i <= n ; i ++ ) {
		cin >> a[ i ].first >> a[ i ].second ;
		if ( a[ i ].first == 'H' ) {
			rows.insert ( a[ i ].second ) ;
		}
		else {
			cols.insert ( a[ i ].second ) ;
		}
	}
	rows.insert ( 0 ) ;
	cols.insert ( 0 ) ;
	rows.insert ( h ) ;
	cols.insert ( w ) ;
}

void solve ( ) {
	int i ;
	set < int > :: iterator it1 , it2 ;
	for ( it1 = rows.begin ( ) ; it1 != rows.end ( ) ; it1 ++ ) {
		if ( it1 == rows.begin ( ) ) { continue ; }
		it2 = it1 ;
		it1 -- ;
		if ( mxh < (*it2) - (*it1) ) { mxh = (*it2) - (*it1) ; }
		it1 ++ ;
	}

	for ( it1 = cols.begin ( ) ; it1 != cols.end ( ) ; it1 ++ ) {
		if ( it1 == cols.begin ( ) ) { continue ; }
		it2 = it1 ;
		it1 -- ;		
		if ( mxw < (*it2) - (*it1) ) { mxw = (*it2) - (*it1) ; }
		it1 ++ ;
	}
	for ( i = n ; i >= 1 ; i -- ) {
		ans[ i ] = mxh * mxw ;	
		if ( a[ i ].first == 'H' ) {
			rows.erase ( a[ i ].second ) ;
			it1 = it2 = rows.upper_bound ( a[ i ].second ) ;
			if ( it1 != rows.begin ( ) ) { it1 -- ; }			
			if ( mxh < (*it2) - (*it1) ) { mxh = (*it2) - (*it1) ; }
		}
		else {
			cols.erase ( a[ i ].second ) ;
			it1 = it2 = cols.upper_bound ( a[ i ].second ) ;
			if ( it1 != cols.begin ( ) ) { it1 -- ; }
			if ( mxw < (*it2) - (*it1) ) { mxw = (*it2) - (*it1) ; }			
		}
	}
	for ( i = 1 ; i <= n ; i ++ ) {
		cout << ans[ i ] << "\n" ;
	}
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}