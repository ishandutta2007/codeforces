#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<queue>
#include<cmath>
#include<map>
using namespace std ;

#define MAXN 107

int n ;
int br[ MAXN ] ;


void input ( ) {
	cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
    	cin >> br[ i ] ;
    }
}

void solve ( ) {
	int i , j ;
    string a ;
    bool fl = true ;
    getline ( cin , a ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
		getline ( cin , a ) ;
        int sz = a.size ( ) ;
        int cur = 0 ;
        for ( j = 0 ; j < sz ; j ++ ) {
        	if ( a[ j ] == 'a' || a[ j ] == 'e' || a[ j ] == 'i' || a[ j ] == 'o' || a[ j ] == 'u' || a[ j ] == 'y' ) { cur ++ ; }
        }
        if ( cur != br[ i ] ) { fl = false ; }
    }
    if ( fl == true ) { cout << "YES\n" ; }
    else { cout << "NO\n" ; }
}


int main ( ) {
	ios::sync_with_stdio ( false ) ;
	cin.tie ( NULL ) ;
	input ( ) ;
	solve ( ) ;
	return 0 ;
}