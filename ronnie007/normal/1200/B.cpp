#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 107
int n , m , k ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i < n ; ++ i ) {
        int lw = a[ i + 1 ] - k ;
        lw = ( ( lw >= 0 ) ? lw : 0 ) ;
        if ( a[ i ] >= lw ) {
            m += a[ i ] - lw ;
        }
        else {
            if ( a[ i ] + m < lw ) {
                printf ( "NO\n" ) ;
                return ;
            }
            m -= ( lw - a[ i ] ) ;
        }
    }
    printf ( "YES\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}