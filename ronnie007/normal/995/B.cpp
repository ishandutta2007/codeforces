#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 107

int n ;
int a[ 2 * MAXN ] ;

int f[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= 2 * n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    int ans = 0 ;
    for ( i = 1 ; i <= 2 * n ; i ++ ) {
        f[ a[ i ] ] ^= 1 ;
        if ( f[ a[ i ] ] == 0 ) {
            int x = i ;
            while ( a[ x - 1 ] != a[ x ] ) {
                swap ( a[ x ] , a[ x - 1 ] ) ;
                ans ++ ;
                x -- ;
            }
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