#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;


int n ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int dig = ( n % 10 ) ;
    if ( dig <= 5 ) { n -= dig ; }
    else { n += ( 10 - dig ) ; }
    printf ( "%d\n" , n ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}