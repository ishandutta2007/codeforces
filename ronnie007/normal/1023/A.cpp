#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;


int n , m ;
string a , b ;

void input ( ) {
    cin >> n >> m ;
    cin >> a >> b ;
}

void solve ( ) {
    int i ;
    bool fl = false ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == '*' ) { fl = true ; }
    }
    if ( fl == false ) {
        if ( a == b ) { cout << "YES\n" ; }
        else { cout << "NO\n" ; }
        return ;
    }
    if ( m + 1 < n ) { cout << "NO\n" ; return ; }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == '*' ) { break ; }
        if ( a[ i ] != b[ i ] ) { cout << "NO\n" ; return ; }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ n - i - 1 ] == '*' ) { break ; }
        if ( a[ n - i - 1 ] != b[ m - i - 1 ] ) { cout << "NO\n" ; return ; }
    }
    cout << "YES\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}