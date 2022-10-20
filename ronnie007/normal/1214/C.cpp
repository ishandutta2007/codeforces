#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

int n ;
string a ;
string aux ;


void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int sm = 0 ;
    int mn = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] == '(' ) { ++ sm ; }
        else { -- sm ; }
        if ( mn > sm ) { mn = sm ; }
    }
    if ( sm == 0 && mn == 0 ) { printf ( "Yes\n" ) ; return ; }
    if ( sm != 0 ) { printf ( "No\n" ) ; return ; }
    bool fl = false ;
    aux.clear ( ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( fl == false && a[ i ] == ')' ) {
            fl = true ;
        }
        else {
            aux += a[ i ] ;
        }
    }
    if ( fl == true ) { aux += ')' ; }
    sm = mn = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( aux[ i ] == '(' ) { ++ sm ; }
        else { -- sm ; }
        if ( mn > sm ) { mn = sm ; }
    }
    if ( sm == 0 && mn == 0 ) { printf ( "Yes\n" ) ; return ; }
    printf ( "No\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}