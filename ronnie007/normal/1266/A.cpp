#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> a ;
}

void solve ( ) {
     n = a.size ( ) ;
     int sm = 0 ;
     int cnt = 0 ;
     int z = 0 ;
     for ( int i = 0 ; i < n ; ++ i ) {
        sm += ( a[ i ] - '0' ) ;
        z += ( a[ i ] == '0' ) ;
        cnt += ( ( ( a[ i ] - '0' ) & 1 ) ^ 1 ) ;
     }
     if ( ( sm % 3 ) == 0 && z > 0 && cnt > 1 ) { printf ( "red\n" ) ; }
     else { printf ( "cyan\n" ) ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int q ;
    cin >> q ;
    while ( q -- ) {
        input ( ) ;
        solve ( ) ;
    }

    return 0 ;
}