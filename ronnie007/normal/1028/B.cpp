#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

int n , m ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
}

void solve ( ) {
    int x , y ;
    x = y = 5 ;
    n -= 5 ;
    int br = 0 ;
    while ( n > 0 ) {
        n -= 4 ;
        br ++ ;
    }
    int i ;
    for ( i = 0 ; i < br ; i ++ ) { printf ( "4" ) ; }
    printf ( "5\n" ) ;
    for ( i = 0 ; i < br ; i ++ ) { printf ( "5" ) ; }
    printf ( "5\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}