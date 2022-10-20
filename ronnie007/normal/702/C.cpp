#include<iostream>
#include<stdio.h>
using namespace std ;

#define MAXN 1000007

int n , m ;
int a[ MAXN ] ;
int b[ MAXN ] ;


bool f ( long long x ) {
    int i , j ;
    j = 1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] + x < b[ j ] ) { return false ; }
        while ( j <= m && b[ j ] + x < a[ i ] ) { j ++ ; }
        if ( a[ i ] + x < b[ j ] ) { return false ; }
        if ( j > m ) { return false ; }
    }
    return true ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    long long l , r ;
    long long mid ;
    l = 0 ;
    r = 2 ;
    int i ;
    for ( i = 1 ; i <= 9 ; i ++ ) { r *= 10 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { l ++ ; }
    printf ( "%d\n" , l ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}