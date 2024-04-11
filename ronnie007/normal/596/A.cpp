#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n ;
pair < int , int > a[ 7 ] ;
int mxx , mnx , mxy , mny ; 

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( ) {
	scanf ( "%d" , &n ) ;
	int i ;
	mxx = mxy = -1007 ;
	mnx = mny = 1007 ;
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
		mxx = max ( mxx , a[ i ].first ) ;
		mnx = min ( mnx , a[ i ].first ) ;
		mxy = max ( mxy , a[ i ].second ) ;
		mny = min ( mny , a[ i ].second ) ;
	}
}

void solve ( ) {
	if ( mxx != mnx && mxy != mny ) { printf ( "%d\n" , ( mxx - mnx ) * ( mxy - mny ) ) ; }
	else { printf ( "-1\n" ) ; }
}