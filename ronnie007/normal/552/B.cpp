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

long long n ;

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
	scanf ( "%I64d" , &n ) ;
}

void solve ( ) {
	long long x = 9 ;
	long long c = 1 ;
	long long ans = 0 ;
	while ( n != 0 ) {
		long long u ;
		u = min ( x , n ) ;
		n -= u ;
		ans += u * c ;
		x *= 10 ;
		c ++ ;
    }
	printf ( "%I64d\n" , ans ) ;
}