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

int b[ MAXN ] ;
int c[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
}

void solve ( ) {
    int i ;
    int ans = 0 ;
    int id = n ;
    for ( i = n ; i >= 1 ; i -- ) {
        while ( id > 0 && a[ id ] >= a[ i ] ) {
            id -- ;
        }
        if ( id > 0 && a[ id ] < a[ i ] ) {
            ans ++ ;
            id -- ;
        }
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