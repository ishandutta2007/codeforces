#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 200007

int n , k ;
int br[ MAXN ] ;


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    int i ;
    for ( i = 2 ; i <= k + 1 ; i ++ ) {
        br[ i ] = 1 ;
    }
    for ( i = k + 2 ; i <= n ; i ++ ) {
        br[ i ] = br[ i - k ] + 1 ;
    }
    printf ( "%d\n" , br[ n ] + br[ n - 1 ] ) ;
    for ( i = 2 ; i <= k + 1 ; i ++ ) {
        printf ( "1 %d\n" , i ) ;
        br[ i ] = 1 ;
    }
    for ( i = k + 2 ; i <= n ; i ++ ) {
        printf ( "%d %d\n" , i - k , i ) ;
        br[ i ] = br[ i - k ] + 1 ;
    }

}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}