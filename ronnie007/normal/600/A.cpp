#include<iostream>
#include<stdio.h>
#include<vector>
#include<stack>
#include<algorithm>
#include<string>
#include<map>
using namespace std ;

int n ;
string a ;

string ans1 , ans2 ;

bool f ( string x ) {
	int k = x.size ( ) ;
    if ( k == 0 ) { return false ; }
    int i ;
    for ( i = 0 ; i < k ; i ++ ) {
    	if ( x[ i ] < '0' || x[ i ] > '9' ) { return false ; }
    }
	if ( x.size ( ) == 1 ) { return true ; }
	if ( x[ 0 ] == '0' ) { return false ; }
    return true ;
}

void print ( string x ) {
	if ( x.size ( ) == 0 ) { cout << "-\n" ; return ; }
    x.resize ( x.size ( ) - 1 ) ;
    cout << "\"" << x << "\"\n" ;
}

void input ( ) {
	cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
	int i ;
    string cur ;
    for ( i = 0 ; i < n ; i ++ ) {
    	if ( a[ i ] == ',' || a[ i ] == ';' ) {
        	if ( f ( cur ) ) { ans1 += cur ; ans1 += ',' ; }
            else { ans2 += cur ; ans2 += ',' ; }
            cur.clear ( ) ;
        }
        else { cur += a[ i ] ; }
    }
	if ( f ( cur ) ) { ans1 += cur ; ans1 += ',' ; }
	else { ans2 += cur ; ans2 += ',' ; }
	cur.clear ( ) ;
    print ( ans1 ) ;
    print ( ans2 ) ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}