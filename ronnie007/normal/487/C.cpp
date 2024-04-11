#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<cstring>
using namespace std ;

int n ;

void input ( ) ;
void solve ( ) ;


long long f ( long long a , long long x ) {
	long long r = 1 ;
	while ( x != 0 ) {
		if ( x % 2 == 1 ) { 
			r = r * a ;
			r %= n ;
			x -- ;
		}
		else { 
			x /= 2 ;
			a = a * a ;
			a %= n ;
        }
    }
	return r ;
}


int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	scanf ( "%d" , &n ) ;
}

void solve ( ) {
	int i , j ;
	if ( n == 1 ) {
		printf ( "YES\n" ) ;
		printf ( "1\n" ) ;
		return ;
	}
	if ( n == 4 ) {
		printf ( "YES\n" ) ;
		printf ( "1\n3\n2\n4\n" ) ;
		return ;
    }
	for ( i = 2 ; i * i <= n ; i ++ ) {
		if ( n % i == 0 ) break ;
    }
	if ( i * i <= n ) { printf ( "NO\n" ) ; return ; } 
	printf ( "YES\n" ) ;
	printf ( "1\n" ) ;
	for ( i = 2 ; i <= n ; i ++ ) {
		long long u ;
		u = i * f ( i - 1 , n - 2 ) ;
		u %= n ;
		if ( u == 0 ) u = n ;
		printf ( "%I64d\n" , u ) ;
    }
}