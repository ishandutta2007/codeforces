#include<iostream>
#include<stdio.h>
#include<string>
using namespace std ;

int n ;
string a ;
string b ;

bool f ( string c ) {
    int i ;
    int sz = c.size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( c[ i ] != c[ sz - i - 1 ] ) { return false ; }
    }
    return true ;
}

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i , j ;
    for ( i = 0 ; i < n ; i ++ ) {
        b = a ;
        for ( j = 0 ; j < 26 ; j ++ ) {
            b[ i ] = char ( j + 'a' ) ;
            if ( b[ i ] == a[ i ] ) { continue ; }
            if ( f ( b ) == true ) { cout << "YES\n" ; return ; }
        }
    }
    cout << "NO\n" ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}