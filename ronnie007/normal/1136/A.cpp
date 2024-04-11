#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;

int k ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        a[ i ] = ( y - x + 1 ) ;
    }
    scanf ( "%d" , &k ) ;
    k -- ;
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( k >= a[ i ] ) { k -= a[ i ] ; }
        else { break ; }
    }
    printf ( "%d\n" , n - ( i - 1 ) ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}