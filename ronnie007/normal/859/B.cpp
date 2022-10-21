#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;


int n ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int i ;
    int ans = -1 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        int x = ( n / i ) ;
        if ( ( n % i ) != 0 ) { x ++ ; }
        if ( ans == -1 ) { ans = 2 * ( x + i ) ; }
        if ( ans > 2 * ( x + i ) ) {
            ans = 2 * ( x + i ) ;
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}