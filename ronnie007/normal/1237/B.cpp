#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;


#define MAXN 100007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

int pos[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
        pos[ b[ i ] ] = i ;
    }
}

void solve ( ) {
    int ans = 0 ;
    int mxpos = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mxpos > pos[ a[ i ] ] ) { ++ ans ; }
        mxpos = max ( mxpos , pos[ a[ i ] ] ) ;
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}