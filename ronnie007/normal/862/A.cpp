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
int x ;
int a[ MAXN ] ;
int br[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &x ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        br[ a[ i ] ] ++ ;
    }
}

void solve ( ) {
    int i ;
    int ans = 0 ;
    for ( i = 0 ; i < x ; i ++ ) {
        if ( br[ i ] == 0 ) { ans ++ ; }
    }
    ans += br[ x ] ;
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}