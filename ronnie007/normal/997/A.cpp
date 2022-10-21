#include<iostream>
#include<stdio.h>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
using namespace std ;

int n ;
long long x , y ;
string a ;


void input ( ) {
    cin >> n >> x >> y ;
    cin >> a ;
}

void solve ( ) {
    int i ;
    int tot = 0 ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( a[ i ] == '0' ) {
            if ( i == 0 || a[ i - 1 ] == '1' ) { tot ++ ; }
        }
    }
    if ( tot == 0 ) { printf ( "0\n" ) ; return ; }
    printf ( "%I64d\n" , 1LL * ( tot - 1 ) * ( min ( x , y ) ) + y ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}