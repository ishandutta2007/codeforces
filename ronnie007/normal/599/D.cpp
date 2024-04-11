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

vector < pair < long long , long long > > v ;

long long n ;

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
	scanf ( "%I64d" , &n ) ;
}
 
void solve ( ) {
	long long i ;
	int r = 2 ;
	for ( i = 1 ; i <= 6 ; i ++ ) { r *= 10 ; }
	long long cur ;
	long long h ;
	long long lft ;
	for ( i = 1 ; i <= r ; i ++ ) {
		cur = ( i - 1 ) * i * ( 2 * ( i - 1 ) + 1 ) ;
		lft = 6 * n - cur ;
		lft += 3 * i * i * i ;
		lft -= 3 * i * i ;
		cur = 3 * ( i * i + i ) ;
		//if ( i == 1 ) { printf ( "%I64d %I64d\n" , lft , cur ) ; }

		//if ( lft % 3 != 0 ) { continue ; }
		//lft /= 3 ;
		if ( lft % cur == 0 ) {
			long long m = lft / cur ;
			if ( m < i ) { break ; }
			v.push_back ( make_pair ( i , m ) ) ;
			if ( i != m ) { v.push_back ( make_pair ( m , i ) ) ; }
		}
	}
	int sz = v.size ( ) ;
	sort ( v.begin ( ) , v.end ( ) ) ;
	printf ( "%d\n" , sz ) ;
	for ( i = 0 ; i < sz ; i ++ ) {
		printf ( "%I64d %I64d\n" , v[ i ].first , v[ i ].second ) ;
	}
}