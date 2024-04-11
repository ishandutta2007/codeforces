#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 200007

int n , k ;
string a ;
string s ;

void input ( ) {
    cin >> n >> k ;
    cin >> a ;
}

void solve ( ) {
    s = a ;
    for ( int i = 0 ; i < k ; ++ i ) {
        for ( int j = i ; j < n ; j += k ) {
            s[ j ] = a[ i ] ;
        }
    }
    cout << n << "\n" ;
    if ( s == a ) { cout << s << "\n" ; return ; }
    for ( int i = k ; i < n ; ++ i ) {
        if ( a[ i ] == s[ i ] ) { continue ; }
        if ( s[ i ] > a[ i ] ) { cout << s << "\n" ; return ; }
        else { break ; }
    }
    for ( int i = k - 1 ; i >= 0 ; -- i ) {
        if ( s[ i ] != '9' ) {
            ++ s[ i ] ;
            for ( int j = i + 1 ; j < k ; ++ j ) {
                s[ j ] = '0' ;
            }
            break ;
        }
    }
    for ( int i = k ; i < n ; ++ i ) {
        s[ i ] = s[ i - k ] ;
    }
    cout << s << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}