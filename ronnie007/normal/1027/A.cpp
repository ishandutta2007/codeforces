#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int i ;
    for ( i = 0 ; i < ( n / 2 ) ; i ++ ) {
        int x = ( a[ i ] - 'a' ) ;
        int y = ( a[ n - i - 1 ] - 'a' ) ;
        if ( x > y ) { swap ( x , y ) ; }
        y -= x ;
        if ( y != 0 && y != 2 ) { cout << "NO\n" ; return ; }
    }
    cout << "YES\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t != 0 ) {
        t -- ;
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}