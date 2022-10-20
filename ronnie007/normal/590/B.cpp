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

#define eps 0.00000001
#define step 0.00000001

double stx , sty ;
double enx , eny ;
double vmax , t ;
double vx , vy ;
double wx , wy ;

bool f ( double x ) {
	double dx , dy ; 
	dx = dy = 0.0000000000 ;
	if ( x > t ) {
		dx += t * vx ;
		dy += t * vy ;
		dx += ( x - t ) * wx ;
		dy += ( x - t ) * wy ;
	}
	else {
		dx = x * vx ;
		dy = x * vy ;
	}
	dx += stx ;
	dy += sty ;
	double dist = ( ( enx - dx ) * ( enx - dx ) + ( eny - dy ) * ( eny - dy ) ) ;
	double cur = x * vmax ;
	if ( dist > cur * cur ) { return false ; }
	return true ;
}

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
	cin >> stx >> sty ;
	cin >> enx >> eny ;
	cin >> vmax >> t ;
	cin >> vx >> vy ;
	cin >> wx >> wy ;
}

void solve ( ) {
	double l , r , mid ;
	l = 0.00000000000000 ;
	r = 1.00000000000000 ;
	int i ;
	for ( i = 1 ; i <= 15 ; i ++ ) { r *= 10.000000000 ; }
	while ( r - l > eps ) {
		mid = ( l + r ) / 2.000000000000 ;
		if ( f ( mid ) == false ) { l = mid ; }
		else { r = mid ; }
	}
	printf ( "%.12lf\n" , l ) ;
}