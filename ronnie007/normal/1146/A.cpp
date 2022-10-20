#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    int i ;
    int f = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == 'a' ) { f ++ ; }
    }
    printf ( "%d\n" , min ( 2 * f - 1 , n ) ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}