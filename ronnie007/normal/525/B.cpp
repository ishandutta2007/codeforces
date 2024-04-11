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

#define MAXN 200007

int n ;
string a ;
int m ;
int f[ MAXN ] ;
int p[ MAXN ] ;

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
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( )  {
	cin >> m ;
	int x ;
	while ( m != 0 ) {
		m -- ;
		cin >> x ;
		f[ x - 1 ] ++ ;
		p[ x - 1 ] ++ ;
    }
	string r ;
	int i ;
	int mid = n / 2 ;
	int cur = 0 ;
	for ( i = 0 ; i < mid ; i ++ ) {
		cur += f[ i ] ;
		if ( cur % 2 == 0 ) { cout << a[ i ] ; r += a[ n - i - 1 ] ; }
		else { cout << a[ n - i - 1 ] ; r += a[ i ] ; }
    }
	if ( n % 2 == 1 ) { cout << a[ n / 2 ] ; }
	int sz = r.size ( )  ;
	for ( i = sz - 1 ; i >= 0 ; i -- ) { cout << r[ i ] ; }
	cout << "\n" ;
}