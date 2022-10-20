#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

#define MAXN 100007

int n , k ;
int a[ MAXN ] ;


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( k > ( i + 1 ) ) {
            k -= ( i + 1 ) ;
        }
        else {
            k -- ;
            printf ( "%d\n" , a[ k ] ) ;
            return ;
        }
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}