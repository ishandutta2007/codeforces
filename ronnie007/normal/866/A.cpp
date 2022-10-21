#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;


int k ;

void input ( ) {
    scanf ( "%d" , &k ) ;
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= 1000000 ; i ++ ) {
        int cur = ( ( i / 2 ) + 1 ) ;
        if ( cur == k ) {
            printf ( "%d 2\n1 2\n" , i ) ;
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