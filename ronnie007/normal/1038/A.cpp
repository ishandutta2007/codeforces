#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n , k ;
string a ;

int br[ 37 ] ;

void input ( ) {
    cin >> n >> k ;
    cin >> a ;
}

void solve ( ) {
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        int id = ( a[ i ] - 'A' ) ;
        br[ id ] ++ ;
    }
    int mn = br[ 0 ] ;
    for ( i = 0 ; i < k ; i ++ ) {
        if ( mn > br[ i ] ) { mn = br[ i ] ; }
    }
    cout << mn * k << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}