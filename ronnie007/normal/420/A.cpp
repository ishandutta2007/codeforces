#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
using namespace std ;

int n ;
string a ;

void input ( ) {
    cin >> a ;
}

void solve ( ) {
    n = a.size ( ) ;
    int i ;
    int k = n / 2 ;
    for ( i = 0 ; i < k ; i ++ ) {
        if ( a[ i ] != a[ n - i - 1 ] ) { printf ( "NO" ) ; return ; }
    }
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] != 'A' && a[ i ] != 'H' && a[ i ] != 'I'  && a[ i ] != 'M' && a[ i ] != 'O' && a[ i ] != 'T' && a[ i ] != 'U' && a[ i ] != 'V' && a[ i ] != 'W' && a[ i ] != 'X' && a[ i ] != 'Y' ) {
            printf ( "NO\n" ) ;
            return ;
        }
    }
    printf ( "YES\n" ) ;
}


int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}