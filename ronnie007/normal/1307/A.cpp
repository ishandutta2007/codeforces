#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

int n , d ;

void input ( ) {
    scanf ( "%d%d" , &n , &d ) ;
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        if ( i == 1 ) { ans += x ; }
        else {
            int aux = ( d / ( i - 1 ) ) ;
            aux = min ( aux , x ) ;
            ans += aux , d -= aux * ( i - 1 ) ;
        }
    }
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