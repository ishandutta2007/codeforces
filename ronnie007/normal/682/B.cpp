#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int ans = 1 ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ] >= ans ) { ans ++ ; }
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