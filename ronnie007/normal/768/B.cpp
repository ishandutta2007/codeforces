#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
#include<set>
#include<iomanip>
#include<cstdlib>
using namespace std ;


long long n , l , r ;

long long f ( long long num , long long IL , long long IR , long long st , long long en ) {
	if ( IR < st || en < IL ) { return 0 ; }
	long long pos = ( IL + IR ) / 2 ;
	long long ret = 0 ;
	if ( st <= pos && pos <= en ) { ret += ( num % 2 ) ; }
	if ( num <= 1 ) { return ret ; }
	ret += f ( ( num / 2 ) , IL , pos - 1 , st , en ) ;
	ret += f ( ( num / 2 ) , pos + 1 , IR , st , en ) ;	
	return ret ;
}

void input ( ) {
	cin >> n >> l >> r ;
}

void solve ( ) {
	long long en = 1 ;
	long long k = n ;
	while ( k != 0 ) {
		k /= 2 ;
		en *= 2 ;
	}
	en -- ;
	long long ret = f ( n , 1 , en , l , r ) ;
	cout << ret << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}