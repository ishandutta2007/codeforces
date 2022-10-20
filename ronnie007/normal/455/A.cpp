#include<iostream>
#include<stdio.h>
using namespace std ;

int n ;
long long a[ 100007 ] ;
int mx = 0 ;
long long dp[ 100007 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    int x ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &x ) ;
        a[ x ] ++ ;
        if ( mx < x ) mx = x ;
    }
}

void solve ( ) {
    int i ;
    int e = 1 ;
    long long cur ;
    long long best = -1 ;
    for ( i = 3 ; i <= mx + 2 ; i ++ ) {
        e = i - 2 ;
        /// take i - 1
        cur = max ( dp[ i - 2 ] , dp[ i - 3 ] ) + ( e - 1 ) * a[ ( e - 1 ) ] ;
        if ( dp[ i ] < cur ) dp[ i ] = cur ;
        /// take i
        cur = max ( dp[ i - 2 ] , dp[ i - 1 ] ) + e * a[ e ] ;
        if ( dp[ i + 1 ] < cur ) dp[ i + 1 ] = cur ;
        /// take i + 1
        cur = max ( dp[ i ] , dp[ i - 1 ] ) + ( e + 1 ) * a[ ( e + 1 ) ] ;
        if ( dp[ i + 2 ] < cur ) dp[ i + 2 ] = cur ;
        ///printf ( "%d %d\n" , i , dp[ i ] ) ;
    }
    printf ( "%I64d\n" , max ( dp[ mx + 2 ] , dp[ mx + 3 ] ) ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}