#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

#define MAXN 37

int n ;
int a[ MAXN ] ;
int mx ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    mx = 0 ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        if ( mx < a[ i ] ) { mx = a[ i ] ; }
    }
}

void solve ( ) {
    if ( mx <= 25 ) { printf ( "0\n" ) ; }
    else { printf ( "%d\n" , mx - 25 ) ; }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}