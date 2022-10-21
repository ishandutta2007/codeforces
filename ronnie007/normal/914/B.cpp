#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int br[ MAXN ] ;


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
    for ( i = 1 ; i <= n ; i ++ ) {
        br[ a[ i ] ] ^= 1 ;
    }
    for ( i = 0 ; i < MAXN - 2 ; i ++ ) {
        if ( br[ i ] != 0 ) {
            printf ( "Conan\n" ) ;
            return ;
        }
    }
    printf ( "Agasa\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}