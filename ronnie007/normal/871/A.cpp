#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int q ;

void input ( ) {
    scanf ( "%d" , &q ) ;
}

void solve ( ) {
    int x ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "%d" , &x ) ;
        if ( x <= 3 ) { printf ( "-1\n" ) ; continue ; }
        if ( ( x % 2 ) == 1 && x < 9 ) { printf ( "-1\n" ) ; continue ; }
        if ( x == 11 ) { printf ( "-1\n" ) ; continue ; }
        int br = 0 ;
        if ( ( x % 2 ) == 1 ) { x -= 9 ; br ++ ; }
        br += ( x / 4 ) ;
        printf ( "%d\n" , br ) ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}