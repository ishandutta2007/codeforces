#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<set>
#include<ctime>
using namespace std ;

int n ;
string a ; 

vector < int > v ;
long long get ( int st , int en ) {
	long long curmul = ( a[ st ] - '0' )  ;
	long long ret = 0 ;
	int i ;
	for ( i = st ; i <= en ; i ++ ) {
		if ( a[ i ] == '*' ) {
			curmul *= ( a[ i + 1 ] - '0' ) ;
        }
		else if ( a[ i ] == '+' ) {
			ret += curmul ;
			curmul = ( a[ i + 1 ] - '0' ) ;
        }
    }
	ret += curmul ;
	return ret ;
}

long long f ( int st , int en ) {
	long long p , u , q ;
	p = get ( st , en ) ;
	int i ;
	long long ret = 0 ;
	long long curmul = ( a[ 0 ] - '0' ) ;
	if ( st == 0 ) { curmul = p ; }
	for ( i = 0 ; i < n ; i ++ ) {
		if ( i >= st && i <= en ) { continue ; }
		long long val ;
		if ( st == i + 1 ) { val = p ; }
		else { val = ( a[ i + 1 ] - '0' ) ; }
		if ( a[ i ] == '*' ) {
			curmul *= val ;
		}
		else if ( a[ i ] == '+' ) {
			ret += curmul ;
			curmul = val ;
        }		
    }
	ret += curmul ;
	return ret ;
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


void input ( ) {
	cin >> a ;
	n = a.size ( ) ;
}

void solve ( )  {
	int i , j ;
	v.push_back ( 0 ) ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == '*' ) { v.push_back ( i - 1 ) ; v.push_back ( i + 1 ) ; }
    }
	v.push_back ( n - 1 ) ;
	int sz = v.size ( ) ;
	long long ans , cur ;
	ans = 0 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		for ( j = i + 1 ; j < sz ; j ++ ) {
			cur = f ( v[ i ] , v[ j ] ) ;
			ans = max ( cur , ans ) ;
        }
    }
	printf ( "%I64d\n" , ans ) ;
}