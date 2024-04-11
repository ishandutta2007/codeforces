#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


struct tuhla {
	double x , y ;
};

struct tuhla h ;
struct tuhla u ;

void input ( ) ;
void solve ( ) ;

int det ( struct tuhla p1 , struct tuhla p2 , struct tuhla p3 ) {
	double k = p1.x * p2.y * 1 + p1.y * 1 * p3.x + 1 * p2.x * p3.y ;
	k -= p3.x * p2.y * 1 + p3.y * 1 * p1.x + 1 * p2.x * p1.y ;
	if ( k < 0 ) return -1 ;
	return 1 ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%lf%lf" , &h.x , &h.y ) ;
	scanf ( "%lf%lf" , &u.x , &u.y ) ;
}

void solve ( )  {
	int i ;
	double a , b , c ;
	int n ; 
	struct tuhla p , q ;
	int ans = 0 ;
	scanf ( "%d" , &n ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		scanf ( "%lf%lf%lf" , &a , &b , &c ) ;
		p.x = 1 ;
		if ( b != 0 ) { p.y = ( -c - a ) / b ; }
		else {
			p.y = 1 ;
			p.x = ( - c ) / a ;
        }
		

		q.x = 2 ;
		if ( b != 0 ) { q.y = ( -c - a - a ) / b ; }
		else {
			q.y = 2 ;
			q.x = ( -c ) / a ;
        }
		int st1 = det ( p , q , h ) ;
		int st2 = det ( p , q , u ) ;
		if ( st1 + st2 == 0 ) { ans ++ ; }
    }
	printf ( "%d\n" , ans ) ;
}