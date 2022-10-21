#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 1007

int n ;
int a[ MAXN ] ;

bool f[ MAXN * MAXN ] ;

int ans ;


void input ( ) {
    int i ;
    for ( i = 0 ; i <= 1000 ; i ++ ) {
        f[ i * i ] = true ;
    }
    scanf ( "%d" , &n ) ;
    ans = - MAXN * MAXN ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] >= 0 ) {
            if ( f[ a[ i ] ] == true ) { continue ; }
        }
        if ( ans < a[ i ] ) { ans = a[ i ] ; }
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