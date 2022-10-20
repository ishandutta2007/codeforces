#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 1007

int n ;
long long a[ MAXN ][ MAXN ] ;

long long b[ MAXN ] ;

bool check ( long long x ) {
    b[ 1 ] = x ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        b[ i ] = ( a[ 1 ][ i ] / b[ 1 ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j < i ; ++ j ) {
            if ( b[ i ] * b[ j ] != a[ i ][ j ] ) { return false ; }
        }
    }
    return true ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            scanf ( "%I64d" , &a[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    for ( long long x = 1 ; x * x <= a[ 1 ][ 2 ] ; ++ x ) {
        if ( ( a[ 1 ][ 2 ] % x ) == 0 ) {
            if ( check ( x ) == true ) { break ; }
            if ( check ( a[ 1 ][ 2 ] / x ) == true ) { break ; }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%I64d " , b[ i ] ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}