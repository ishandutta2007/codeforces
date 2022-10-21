#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int mn[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    long long ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        mn[ i ] = a[ i ] + 1 ;
        if ( mn[ i ] < mn[ i - 1 ] ) { mn[ i ] = mn[ i - 1 ] ; }
    }
    for ( i = n ; i >= 1 ; i -- ) {
        if ( mn[ i ] < mn[ i + 1 ] - 1 ) {
            mn[ i ] = mn[ i + 1 ] - 1 ;
        }
        ans += ( mn[ i ] - a[ i ] - 1 ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}