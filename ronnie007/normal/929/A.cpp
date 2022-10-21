#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 100007

int n , k ;

int a[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int ans = 1 ;
    int i ;
    int lst = a[ 1 ] ;
    for ( i = 2 ; i <= n ; i ++ ) {
        if ( a[ i ] - a[ i - 1 ] > k ) { printf ( "-1\n" ) ; return ; }
        if ( a[ i ] - lst > k ) {
            ans ++ ;
            lst = a[ i - 1 ] ;
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