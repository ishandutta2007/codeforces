#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<stack>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

int lst[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int ans = n + 2 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( lst[ a[ i ] ] > 0 ) {
            ans = min ( ans , i - lst[ a[ i ] ] + 1 ) ;
        }
        lst[ a[ i ] ] = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        lst[ a[ i ] ] = 0 ;
    }
    if ( ans > n ) { ans = -1 ; }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }

    return 0 ;
}