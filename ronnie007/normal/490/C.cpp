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
string s ;
long long a , b ;
long long l[ 1000007 ] ;
long long r[ 1000007 ] ;


void input ( ) ;
void solve ( ) ;



int main ( )  {
    ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}

void input ( ) {
	cin >> s ;
	cin >> a >> b ;
}

void solve ( ) {
	n = s.size ( ) ;
	int i , j ;
	l[ 0 ] = ( ( s[ 0 ] - '0' ) % a ) ;
	for ( i = 1 ; i < n ; i ++ ) {
		l[ i ] = ( l[ i - 1 ] * 10 + ( s[ i ] - '0' ) ) % a ;
    }
	long long u = 1 ;
	for ( i = n - 1 ; i >= 0 ; i -- ) {
		r[ i ] = ( r[ i + 1 ] + u * ( s[ i ] - '0' ) ) % b ;
		u = ( u * 10 ) % b ;
    }
	for ( i = 0 ; i < n - 1 ; i ++ ) {
		if ( l[ i ] == 0 && r[ i + 1 ] == 0 && s[ i + 1 ] != '0' ) {
			break ;
        }
    }
	if ( i == n - 1 ) {
		cout << "NO\n" ;
		return ; 
    }
	cout << "YES\n" ;
	for ( j = 0 ; j <= i ; j ++ ) {
		cout << s[ j ] ;
    }
	cout << "\n" ;
	for ( j = i + 1 ; j < n ; j ++ ) {
		cout << s[ j ] ;
    }
	cout << "\n" ;
}