#include<iostream>
#include<stdio.h>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
using namespace std ;

int n ;
string a ;
int br[ 37 ] ;

void input ( ) ;
void solve ( ) ;


int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ; 
	input ( ) ;
	solve ( ) ;
	return 0 ;
}


void input ( )  {
	cin >> n ;
	cin >> a ;
}

void solve ( )  {
	int sz = 2 * n - 2 ;
	int i ;
	int ans = 0 ;
	for ( i = 0 ; i < sz ; i ++ ) {
		if ( a[ i ] >= 'a' && a[ i ] <= 'z' ) {
			br[ a[ i ] - 'a' ] ++ ;
        }
		else {
			int id = ( a[ i ] - 'A' ) ;
			if ( br[ id ] == 0 ) { ans ++ ; }
			else { br[ id ] -- ; }
        }
    }
	cout << ans << "\n" ;
}