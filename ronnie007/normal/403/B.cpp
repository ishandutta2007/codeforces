#include<iostream>
#include<stdio.h>
#include<set>
#include<algorithm>
using namespace std ;

int n , m ;

int a[ 5007 ] ;
int b[ 5007 ] ;
int t[ 5007 ] ;
set < int > s ;

int f ( int x ) {
    int i ;
    int ret = 0 ;
    for ( i = 2 ; i * i <= x ; i ++ ) {
        while ( x % i == 0 ) {
            if ( s.count ( i ) == 0 ) ret ++ ;
            else ret -- ;
            x /= i ;
        }
    }
    if ( x != 1 ) {
        if ( s.count ( x ) == 0 ) ret ++ ;
        else ret -- ;
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 0 ; i < m ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
        s.insert ( b[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    int g = a[ 0 ] ;
    for ( i = 0 ; i < n ; i ++ ) {
        g = __gcd ( a[ i ]  , g ) ;
        t[ i ] = g ;
    }
    g = 1 ;
    for ( i = n - 1 ; i >= 0 ; i -- ) {
        t[ i ] /= g ;
        if ( f( t[ i ] ) < 0 ) {
            g *= t[ i ] ;
        }
        a[ i ] /= g ;
    }
    int ans = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        ans += f ( a[ i ] ) ;
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}