#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n , m ;
long long ans = 0 ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int k = ( 5 - ( i % 5 ) ) ;
        if ( m < k ) { continue ; }
        ans += ( m - k ) / 5 + 1 ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}