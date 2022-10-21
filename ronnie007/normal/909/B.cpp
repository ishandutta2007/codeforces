#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

int n ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int ans = 0 ;
    while ( n > 2 ) {
        ans += n ;
        n -= 2 ;
    }
    if ( n == 1 ) { ans ++ ; }
    if ( n == 2 ) { ans += 2 ; }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}