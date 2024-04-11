#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

string a ;
int n ;

void input ( ) {
    cin >> a ;
    cin >> n ;
}

void solve ( ) {
    int i ;
    bool fl = false ;
    bool x = false ;
    bool y = false ;
    string s ;
    for ( i = 0 ; i < n ; i ++ ) {
        cin >> s ;
        if ( a == s ) { fl = true ; }
        if ( s[ 1 ] == a[ 0 ] ) { x = true ; }
        if ( a[ 1 ] == s[ 0 ] ) { y = true ; }
    }
    if ( x == true && y == true ) { fl = true ; }
    if ( fl == true ) { cout << "YES\n" ; }
    else { cout << "NO\n" ; }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}