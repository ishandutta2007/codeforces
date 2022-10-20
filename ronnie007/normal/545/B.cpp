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

int n ;
string a , b ;

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
	cin >> a >> b ;
	n = a.size ( ) ;
}

void solve ( )  {
	int i ;
	int br = 0 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] != b[ i ] ) { br ++ ; }
    }
	if ( br % 2 != 0 ) {
		cout << "impossible\n" ;
		return ;
    }
	int k = br / 2 ;
	for ( i = 0 ; i < n ; i ++ ) {
		if ( a[ i ] == b[ i ] ) { cout << "1" ; }
		else {
			if ( k != 0 ) { k -- ; cout << a[ i ] ; }
			else { cout << b[ i ] ; }
        }
    }
	cout << "\n" ;
}