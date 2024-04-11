#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

long long ans = 0 ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    ans = a[ n ] ;
    for ( i = n - 1 ; i >= 1 ; i -- ) {
        if ( a[ i ] >= a[ i + 1 ] ) {
            a[ i ] = a[ i + 1 ] - 1 ;
        }
        if ( a[ i ] < 0 ) { a[ i ] = 0 ; }
        ans += a[ i ] ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}