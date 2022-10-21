#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 1000007

int n ;
vector < int > v[ MAXN ] ;

int used[ MAXN ] ;

int mxdiv[ MAXN ] ;

int f[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int i , j ;
    for ( i = 2 ; i <= n ; i ++ ) {
        if ( used[ i ] != 0 ) { continue ; }
        for ( j = 2 * i ; j <= n ; j += i ) {
            used[ j ] = 1 ;
            mxdiv[ j ] = i ;
        }
    }
    for ( i = 3 ; i <= n ; i ++ ) {
        f[ i ] = i - mxdiv[ i ] + 1 ;
    }
    int ans = n ;
    for ( i = n - mxdiv[ n ] + 1 ; i <= n ; i ++ ) {
        if ( ans > f[ i ] ) { ans = f[ i ] ; }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}