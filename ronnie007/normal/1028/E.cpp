#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std ;

#define MAXN 400007

int n ;
long long a[ MAXN ] ;
long long b[ MAXN ] ;
long long ans[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%I64d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    int mx = -1 ;
    int id = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] != a[ 1 ] ) { break ; }
    }
    if ( i > n ) {
        if ( a[ 1 ] != 0 ) { printf ( "NO\n" ) ; }
        else {
            printf ( "YES\n" ) ;
            for ( i = 1 ; i <= n ; i ++ ) {
                printf ( "1" ) ;
                if ( i == n ) { printf ( "\n" ) ; }
                else { printf ( " " ) ; }
            }
        }
        return ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( mx < a[ i ] ) { mx = a[ i ] ; }
    }
    a[ 0 ] = a[ n ] ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] == mx && a[ i ] > a[ i - 1 ] ) { id = i ; break ; }
    }
    b[ id ] = a[ id ] ;
    for ( i = id - 1 ; i != id ; i -- ) {
        if ( i <= 0 ) { i += n ; b[ n + 1 ] = b[ 1 ] ; }
        if ( i == id ) { break ; }
        b[ i ] += b[ i + 1 ] + a[ i ] ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( i != id ) { b[ i ] += a[ id ] ; }
    }
    printf ( "YES\n" ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%I64d" , b[ i ] ) ;
        if ( i == n ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}