#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

int n ;
string a ;

int br[ 37 ] ;

int diff ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        br[ ( a[ i ] - 'a' ) ] ++ ;
        if ( br[ ( a[ i ] - 'a' ) ] == 1 ) { diff ++ ; }
    }
}

void solve ( ) {
    int i ;
    if ( diff > 4 ) { printf ( "no\n" ) ; return ; }
    if ( diff == 4 ) { printf ( "yes\n" ) ; return ; }
    if ( diff == 3 ) {
        for ( i = 0 ; i < 26 ; i ++ ) {
            if ( br[ i ] >= 2 ) { printf ( "yes\n" ) ; return ; }
        }
        printf ( "no\n" ) ;
        return ;
    }
    if ( diff == 2 ) {
        for ( i = 0 ; i < 26 ; i ++ ) {
            if ( br[ i ] == 1 ) { printf ( "no\n" ) ; return ; }
        }
        printf ( "yes\n" ) ;
        return ;
    }
    printf ( "no\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}