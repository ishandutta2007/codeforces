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
int a[ MAXN ] ;

int f[ MAXN ] ;
vector < int > v[ MAXN ] ;
int ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        f[ a[ i ] ] ++ ;
        v[ a[ i ] ].push_back ( i ) ;
    }
}

void solve ( ) {
    int i , j ;
    int val = 1 ;
    for ( i = 0 ; i < n ; i ++ ) {
        int hh = ( n - i ) ;
        if ( ( f[ i ] % hh ) != 0 ) { printf ( "Impossible\n" ) ; return ; }
        int sz = v[ i ].size ( ) ;
        if ( sz == 0 ) { continue ; }
        int cur = 0 ;
        for ( j = 0 ; j < sz ; j ++ ) {
            cur ++ ;
            if ( cur > hh ) { cur = 1 ; val ++ ; }
            ans[ v[ i ][ j ] ] = val ;
        }
        if ( cur == hh ) { val ++ ; }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( ans[ i ] > n ) { printf ( "Impossible\n" ) ; return ; }
    }
    printf ( "Possible\n" ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d " , ans[ i ] ) ;
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