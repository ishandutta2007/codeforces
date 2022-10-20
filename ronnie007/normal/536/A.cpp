#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

#define inf 10000007

long long a , b , q ;

long long st , t , m ; 

bool check ( long long r ) {
	long long sm , mx ;
	mx = a + ( r - 1 ) * b ; 
	if ( mx > t ) { return false ; }
	long long tot = ( t * m ) ;
	sm = a * ( r - st + 1 ) + ( r * ( r - 1 ) / 2 ) * b ;
	if ( st >= 1 ) { 
		sm -= ( ( st - 1 ) * ( st - 2 ) / 2 ) * b ;
	}
	if ( sm > tot ) { return false ; }
	return true ;
}

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	scanf ( "%I64d%I64d%I64d" , &a , &b , &q ) ;
}

void solve ( )  {
	long long l , r , mid ; 
	while ( q != 0 ) {
		q -- ;
		scanf ( "%I64d%I64d%I64d" , &st , &t , &m ) ;
		if ( check ( st ) == false ) { printf ( "-1\n" ) ; continue ; }
		l = st ;
		r = inf ;
		//r *= r ;
		while ( r - l > 3 ) {
			mid = ( l + r ) / 2 ;
			if ( check ( mid ) == true ) { l = mid ; }
			else { r = mid ; }
        }
		while ( check ( r ) == false ) { r -- ; }
		printf ( "%I64d\n" , r ) ;
    }
}