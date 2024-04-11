#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;


#define PI M_PI


int len[ 17 ] ;

pair < double , double > a[ 17 ] ;

void input ( ) ;
void solve ( ) ;

double det ( pair < double , double > p1 , pair < double , double > p2 , pair < double , double > p3 ) {
	double k = p1.first * p2.second + p1.second * p3.first + p2.first * p3.second ;
	k -= p3.first * p2.second + p3.second * p1.first + p2.first * p1.second ;
	return k ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	int i ;
	for ( i = 1 ; i <= 6 ; i ++ ) {
		scanf ( "%d" , &len[ i ] ) ;
    }
}

void solve ( )  {
	a[ 1 ].first = a[ 1 ].second = 1.000000000 ;
	int i ;
	double ang = 0.000 ;
	double dx , dy ;
	for ( i = 1 ; i <=	 6 ; i ++ ) {
		dx = ( len[ i ] * sin ( ( ang * PI ) / 180.00 ) ) ;
		dy = ( len[ i ] * cos ( ( ang * PI ) / 180.00 ) ) ;
		a[ i + 1 ].first = a[ i ].first + dx ;
		a[ i + 1 ].second = a[ i ].second + dy ;
		//printf ( "%lf %lf\n" , a[ i + 1 ].first , a[ i + 1 ].second ) ;
		ang += 60.00 ;
    }
	pair < double , double > st ;
	st.first = st.second = 0.000 ;
	double area = 0.0000 ;
	for ( i = 1 ; i <= 6 ; i ++ ) {
		int id = i + 1 ;
		if ( id == 7 ) { id = 1 ; }
		area += det ( st , a[ id ] , a[ i ] ) ;
    }
	area /= 2 ;
	//printf ( "%lf\n" , area ) ;
	double tr = ( sqrt ( 3 ) / 4.0000 ) ;
	//printf ( "%lf\n" , tr ) ;
	area /= tr ;
	printf ( "%d\n" , int ( area + 0.51 )  ) ;
}