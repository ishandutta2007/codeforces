#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

string a ;

void input ( ) {
    cin >> a ;
}

void solve ( ) {
    int n = a.size ( ) ;
    int ans = 0 ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == 'a' ) { ans ++ ; }
        if ( a[ i ] == 'e' ) { ans ++ ; }
        if ( a[ i ] == 'i' ) { ans ++ ; }
        if ( a[ i ] == 'o' ) { ans ++ ; }
        if ( a[ i ] == 'u' ) { ans ++ ; }
        if ( a[ i ] >= '0' && a[ i ] <= '9' ) {
            int x = ( a[ i ] - '0' ) ;
            if ( ( x % 2 ) == 1 ) { ans ++ ; }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}