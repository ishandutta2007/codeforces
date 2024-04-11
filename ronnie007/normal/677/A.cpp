#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n , k ;
int ans = 0 ;

void input ( ) {
    int i ;
    int x ;
    scanf ( "%d%d" , &n , &k ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &x ) ;
        if ( x <= k ) { ans ++ ; }
        else { ans += 2 ; }
    }
}

void solve ( ) {
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}