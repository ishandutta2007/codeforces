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

#define MOD 1000000007

int n , m ;
int len ;
string a ;

int p[ 1000007 ] ;
int PI[ 2000007 ] ;


string h ;

int OFFSET ;

bool f ( ) {
	PI[ 0 ] = 0 ;
	PI[ 1 ] = 0 ;
	int i ;
	int l = 0 ;
	int sz = h.size ( ) ;
	for ( i = 2 ; i < sz ; i ++ ) {
		while ( l != 0 && h[ l + 1 ] != h[ i ] ) {
			l = PI[ l ] ;
        }
		if ( h[ l + 1 ] == h[ i ] ) { l ++ ; }
		PI[ i ] = l ;
    }
	for ( i = 0 ; i < m ; i ++ ) {
		if ( PI[ OFFSET + p[ i ] + len - 1 ] != len ) { return false ; }
    }
	return true ;
}

void fastpow ( int x ) {
	long long r = 1 ;
	long long a = 26 ;
	while ( x != 0 ) {
		if ( x % 2 == 0 ) {
			a = a * a ;
			a %= MOD ;
			x /= 2 ; 
		}
		else { 
			r = r * a ;
			r %= MOD ;
			x -- ;
        }
    }
	cout << r << "\n" ;
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
	cin >> n >> m ; 
	cin >> a ;
	len = a.size ( ) ;
	int i ;
	for ( i = 0 ; i < m ; i ++ ) {
		cin >> p[ i ] ; 
		p[ i ] -- ;
    }
}

void solve ( )  {
	h = ' ' + a ;
	h += '#' ;
	OFFSET = h.size ( ) ;
	int i , j ;
	for ( i = 0 ; i < n ; i ++ ) {
		h += '?' ;
	}
	int st = 0 ;
	int en ;
	int br = 0 ;
	int free = 0 ;
	for ( i = 0 ; i < m ; i ++ ) {
		if ( st < OFFSET + p[ i ] ) { st = OFFSET + p[ i ] ; }
		en = OFFSET + p[ i ] + len - 1 ;
		for ( j = st ; j <= en ; j ++ ) {
			h[ j ] = a[ j - ( OFFSET + p[ i ] )  ] ;
        }
		st = j ;
    }
	int sz = h.size ( ) ;
	for ( i = OFFSET ; i < sz ; i ++ ) {
		if ( h[ i ] == '?' ) { free ++ ; }
    }
	//cout << h << "\n" ;
	if ( f ( ) == false ) { cout << "0\n" ; return ; }
	fastpow ( free ) ;

}