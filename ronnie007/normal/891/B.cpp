#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 100007

int n ;
pair < int , int > a[ MAXN ] ;
int b[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ].first ) ;
        a[ i ].second = i ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( i != n ) { b[ a[ i ].second ] = a[ i + 1 ].first ; }
        else { b[ a[ i ].second ] = a[ 1 ].first ; }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d" , b[ i ] ) ;
        if ( i == n ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}