#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

int n ;
string a ;


void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i ;
    int x , y , z ;
    x = y = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == '0' ) { x ++ ; }
        else if ( a[ i ] == '1' ) { y ++ ; }
        else { z ++ ; }
    }
	if ( y + 1 <= ( n + 1 ) / 2 ) { cout << "00\n" ; }
	if ( a[ n - 1 ] != '0' && x <= n / 2 && y + ( a[ n - 1 ] == '?' ) <= ( n + 1 ) / 2 ) { cout << "01\n" ; }
	if ( a[ n - 1 ] != '1' && x + ( a[ n - 1 ] == '?' ) <= n / 2 && y <= ( n + 1 ) / 2 ) { cout << "10\n" ; }
	if ( x + 1 <= n / 2 ) { cout << "11\n" ; }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}