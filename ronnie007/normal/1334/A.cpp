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

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int a , b ;
    int x , y ;
    a = b = 0 ;
    bool bad = false ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &x , &y ) ;
        if ( x < a || y < b ) { bad = true ; }
        if ( y - b > x - a ) { bad = true ; }
        a = x ; b = y ;
    }
    if ( bad == true ) { printf ( "NO\n" ) ; }
    else { printf ( "YES\n" ) ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}