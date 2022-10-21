#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
int a[ 107 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    int mx = 0 ;
    int sm = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( mx < a[ i ] ) { mx = a[ i ] ; }
        sm += a[ i ] ;
    }
    printf ( "%d\n" , mx * n - sm ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}