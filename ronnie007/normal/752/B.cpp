#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

int n ;
string a , b ;

int to[ 37 ] ;

void input ( ) {
    cin >> a >> b ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i ;
    for ( i = 0 ; i < 26 ; i ++ ) { to[ i ] = -2 ; }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] != b[ i ] ) {
            to[ ( a[ i ] - 'a' ) ] = ( b[ i ] - 'a' ) ;
            to[ ( b[ i ] - 'a' ) ] = ( a[ i ] - 'a' ) ;
        }
        else {
            to[ ( a[ i ] - 'a' ) ] = -1 ;
        }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == b[ i ] ) {
            if ( to[ a[ i ] - 'a' ] != -1 ) { printf ( "-1\n" ) ; return ; }
        }
        else {
            if ( to[ ( a[ i ] - 'a' ) ] != ( b[ i ] - 'a' ) ) { printf ( "-1\n" ) ; return ; }
            if ( to[ ( b[ i ] - 'a' ) ] != ( a[ i ] - 'a' ) ) { printf ( "-1\n" ) ; return ; }
        }
    }
    vector < pair < int , int > > v ;
    for ( i = 0 ; i < 26 ; i ++ ) {
        if ( to[ i ] >= i ) {
            v.push_back ( make_pair ( i , to[ i ] ) ) ;
        }
    }
    int sz = v.size ( ) ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%c %c\n" , char( 'a' + v[ i ].first ) , char( 'a' + v[ i ].second ) ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}