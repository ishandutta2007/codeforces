#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int d[ MAXN ] ;
int f[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    d[ 1 ] = 0 ;
    f[ 0 ] = 1 ;
    for ( i = 2 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        d[ i ] = d[ a[ i ] ] + 1 ;
        f[ d[ i ] ] ^= 1 ;
    }
}

void solve ( ) {
    int i ;
    int ans = 0 ;
    for ( i = 0 ; i <= n ; i ++ ) {
        ans += f[ i ] ;
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}