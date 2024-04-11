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
int br[ 37 ] ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    if ( n == 1 ) { printf ( "Yes\n" ) ; return ; }
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        int x = ( a[ i ] - 'a' ) ;
        br[ x ] ++ ;
    }
    int w = 0 ;
    int p = 0 ;
    for ( i = 0 ; i < 26 ; i ++ ) {
        if ( br[ i ] == 1 ) { w ++ ; }
        if ( br[ i ] >= 2 ) { p ++ ; }
    }
    if ( w > 1 && p == 0 ) { printf ( "No\n" ) ; }
    else { printf ( "Yes\n" ) ; }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}