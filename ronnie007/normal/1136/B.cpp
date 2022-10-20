#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

int n , k ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    if ( k == 1 || k == n ) {
        printf ( "%d\n" , 3 * n ) ;
    }
    else {
        int x = ( k - 1 ) ;
        int y = ( n - k ) ;
        if ( x > y ) { swap ( x , y ) ; }
        printf ( "%d\n" , 3 + 4 * x + 3 * y ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}