#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

int n ;
string a ;
string b ;


void input ( ) {
	cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
	int m ;
    cin >> m ;
    int l , r , k ;
    int i ;
	while ( m != 0 ) {
    	m -- ;
    	cin >> l >> r >> k ;
        l -- ;
        r -- ;
        k %= ( r - l + 1 ) ;
        b.resize ( ( r - l + 1 ) ) ;
		for ( i = l ; i <= r ; i ++ ) {
        	b[ ( ( i - l ) + k ) % ( r - l + 1 ) ] = a[ i ] ;
        }
        for ( i = l ; i <= r ; i ++ ) {
        	a[ i ] = b[ ( i - l ) ] ;
        }
    }
    cout << a << "\n" ;
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}