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
long long l , r ;

int used[ 107 ] ;
long long pw[ 107 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    //ios::sync_with_stdio ( false ) ;
    //cin.tie ( NULL ) ; 
	input ( ) ;
	//solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> n ;
	while ( n > 0 ) {
		n -- ;
		cin >> l >> r ;
		solve ( ) ;
    }
}

void solve ( )  {
	long long p = 0 ;
	long long br = 0 ;
	long long i ;
	long long k ;
	k = r ;
	br = 0 ;
	for ( i = 0 ; i <= 63 ; i ++ ) used[ i ] = 0  ;
	while ( k != 0 ) { br ++ ; k /= 2 ; } 
	//printf ( "00-%d\n" , br ) ;
	long long ad = 1 ;
	for ( i = 0 ; i < br ; i ++ ) {
		p += ad ;
		ad *= 2 ;
		used[ i ] = 1 ;
    }
	unsigned long long cur = 1 ;
	//int ans = br ;
	//if ( l == 2 && r == 4 ) printf ( "%d\n" , p ) ;
	

	//printf ( "%d %d\n" , p , r ) ;
	bool fl = false ;
	long long umn = 2 ;
	pw[ 0 ] = 1 ;
	for ( i = 1 ; i <= 63 ; i ++ ) pw[ i ] = 2 * pw[ i - 1 ] ;
	while ( p > r ) {
		for ( i = 63 ; i >= 0 ; i -- ) {
			if ( used[ i ] == 0 ) continue ;
			if ( p - pw[ i ] >= l ) {
				p -= pw[ i ] ;
				used[ i ] = 0 ;
				if ( p <= r ) break ;
            }
        }
    }
	//cout << ans << "\n" ;
	// = 0 ;
    //	cur = 1 ;
    //	for ( i = 0 ; i < br ; i ++ ) {
        //	if ( used[ i ] == 1 ) p += cur ;
        //	cur *= 2 ;
        //}
	cout << p << "\n" ;
	//printf ( "%d\n" , p ) ;
}