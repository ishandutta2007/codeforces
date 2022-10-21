#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
string s ;


void input ( ) {
    cin >> s ;
    n = s.size ( ) ;
}

void solve ( ) {
    int i ;
    int a , b , c ;
    a = b = c = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( s[ i ] == 'a' ) { a ++ ; }
        else { break ; }
    }
    for ( ; i < n ; i ++ ) {
        if ( s[ i ] == 'b' ) { b ++ ; }
        else { break ; }
    }
    for ( ; i < n ; i ++ ) {
        if ( s[ i ] == 'c' ) { c ++ ; }
        else { break ; }
    }
    if ( i < n ) { printf ( "NO\n" ) ; return ; }
    if ( a == 0 || b == 0 ) { printf ( "NO\n" ) ; return ; }
    if ( c != a && c != b ) { printf ( "NO\n" ) ; return ; }
    printf ( "YES\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}