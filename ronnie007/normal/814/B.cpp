#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 1007
int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;


int fl[ MAXN ] ;

bool used[ MAXN ] ;

int ans[ MAXN  ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    int i , j ;
    int br = 0 ;
    int u1 , u2 ;
    u1 = u2 = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] == b[ i ] ) { fl[ i ] = 1 ; used[ a[ i ] ] = true ; ans[ i ] = a[ i ] ; continue ; }
        if ( u1 == -1 ) { u1 = i ; }
        else { u2 = i ; }
    }
    if ( u2 != -1 ) {
        if ( used[ a[ u1 ] ] == false && used[ b[ u2 ] ] == false ) {
            ans[ u1 ] = a[ u1 ] ;
            ans[ u2 ] = b[ u2 ] ;
        }
        else {
            ans[ u1 ] = b[ u1 ] ;
            ans[ u2 ] = a[ u2 ] ;
        }
    }
    else {
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( used[ i ] == false ) { ans[ u1 ] = i ; }
        }
    }
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