#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

#define MAXN 100007

int n ;
string a ;

int pref[ MAXN ] ;
int tot = 0 ;

bool f ( int x ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        pref[ i ] = pref[ i - 1 ] ;
        if ( a[ i - 1 ] == 'S' ) { pref[ i ] ++ ; }
    }
    for ( i = x ; i <= n ; i ++ ) {
        if ( pref[ i ] - pref[ i - x ] <= 1 ) { return true ; }
    }
    return false ;
}

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int l , r , mid ;
    for ( l = 0 ; l < n ; l ++ ) {
        if ( a[ l ] == 'G' ) { tot ++ ; }
    }
    if ( tot == 0 ) { printf ( "0\n" ) ; return ; }
    l = 0 ;
    r = tot ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { l = mid ; }
        else { r = mid - 1 ; }
    }
    while ( f ( r ) == false ) { r -- ; }
    printf ( "%d\n" , r ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}