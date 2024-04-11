#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n , m ;
int k ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
}

void solve ( ) {
    int x , y ;
    for ( y = 1 ; y <= n ; y ++ ) {
        for ( x = 1 ; x <= m ; x ++ ) {
            if ( k == 1 ) { printf ( "%d %d L\n" , y , x ) ; }
            else if ( k == 2 ) { printf ( "%d %d R\n" , y , x ) ; }
            k -= 2 ;
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