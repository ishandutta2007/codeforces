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
int b[ MAXN ] ;

int br1[ 7 ] ;
int br2[ 7 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        br1[ a[ i ] ] ++ ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
        br2[ b[ i ] ] ++ ;
    }
}

void solve ( ) {
    int i ;
    int ans = 0 ;
    for ( i = 1 ; i <= 5 ; i ++ ) {
        if ( ( br1[ i ] + br2[ i ] ) % 2 == 1 ) { printf ( "-1\n" ) ; return ; }
        int sr = ( br1[ i ] + br2[ i ] ) / 2 ;
        ans += abs ( sr - br1[ i ] ) ;
    }
    ans /= 2 ;
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}