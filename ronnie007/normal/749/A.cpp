#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    vector < int > v ;
    if ( ( n % 2 ) == 1 ) { v.push_back ( 3 ) ; n -= 3 ; }
    while ( n != 0 ) {
        v.push_back ( 2 ) ;
        n -= 2 ;
    }
    int sz = v.size ( ) ;
    int i ;
    printf ( "%d\n" , sz ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        printf ( "%d " , v[ i ] ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}