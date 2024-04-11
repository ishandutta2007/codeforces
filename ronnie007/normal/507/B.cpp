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

double p , x , y , a , b ; 

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
	cin >> p >> x >> y >> a >> b ;
	p *= 2 ; 
}

void solve ( )  {
	double u = ( x - a ) * ( x - a ) + ( y - b ) * ( y - b ) ;
	u = sqrt ( u ) ;
	int l , r , mid , i ;
	l = 0 ; 
	r = 300007 ;
	while ( r - l > 7 ) {
		mid = ( l + r ) / 2 ;
		if ( mid * p >= u ) { r = mid ; } 
		else { l = mid ; }
    }
	for ( i = l ; i <= r ; i ++ ) {
		if ( i * p >= u ) { break ; }
    }
	printf ( "%d\n" , i ) ;
}