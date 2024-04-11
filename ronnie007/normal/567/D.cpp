#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstdlib>
#include<cstring>
#include<set>
using namespace std ;

#define MAXN 200007

int n , k , a ;
int p ;
int x[ MAXN ] ;

void input ( ) ;
void solve ( ) ;

int f ( int len ) {
	if ( len < a ) { return 0 ; }
	long long l , r , mid ;
	l = 0 ;
	r = n ; 
	while ( r - l >= 3 ) {
		mid = ( l + r ) / 2 ;
		if ( mid * a + mid - 1 <= len ) { l = mid ; }
		else { r = mid ; }
    }
	while ( 1 ) {
		if ( r * a + r - 1 > len ) { r -- ; }
		else { break ; }
    }
	if ( r < 0 ) { r = 0 ; }
	return r ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%d%d%d" , &n , &k , &a ) ;
	scanf ( "%d" , &p ) ;
	int i ;
	for ( i = 1 ; i <= p ; i ++ ) {
		scanf ( "%d" , &x[ i ] ) ;
    }
}
 
void solve ( )  {
	set < int > s ;
	s.insert ( 0 ) ;
	s.insert ( n + 1 ) ;
	int i ;
	int cur = f ( n ) ;
	set < int > :: iterator it1 , it2 ;
	for ( i = 1 ; i <= p ; i ++ ) {
		s.insert ( x[ i ] ) ;
		it1 = s.lower_bound ( x[ i ] ) ;
		it2 = s.upper_bound ( x[ i ] ) ;
		it1 -- ;
		cur -= f ( (*it2) - (*it1) - 1 ) ;
		cur += f ( x[ i ] - (*it1) - 1 ) ;
		cur += f ( (*it2) - x[ i ] - 1 ) ;
		if ( cur < k ) { printf ( "%d\n" , i ) ; break ; }
    }
	if ( cur >= k ) { printf ( "-1\n" ) ; }
}