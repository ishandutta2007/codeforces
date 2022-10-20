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
#include<stack>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int ret[ MAXN ] ;

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
	for ( i = 1 ; i <= n ; i ++ ) {
		scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
	set < int > s ;
	int i ;
	s.insert ( 0 ) ;
	for ( i = 1 ; i <= n ; i ++ ) {
		s.insert ( a[ i ] - i ) ;
		set < int > :: iterator j ;
		j = s.begin ( ) ;
		ret[ i ] = i + (*j) ;
    }
	s.clear ( ) ;
	s.insert ( 0 ) ;
	for ( i = n ; i >= 1 ; i -- ) {
		s.insert ( a[ i ] - ( n - i + 1 ) ) ;
		set < int > :: iterator j ;
		j = s.begin ( ) ;
		ret[ i ] = min ( ret [ i ] , ( n - i + 1 ) + (*j) ) ;
    }
	int ans = ret[ 1 ] ;
	for ( i = 2 ; i <= n ; i ++ ) {
		ans = max ( ans , ret[ i ] ) ;
    }
	printf ( "%d\n" , ans ) ;
}