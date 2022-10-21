#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

string a ;
int b ;

void input ( ) {
    cin >> a >> b ;
}

void solve ( ) {
    int i ;
    int n = a.size ( ) ;
    int br = 0 ;
    int ans = 0 ;
    for ( i = n - 1 ; i >= 0 ; i -- ) {
        if ( a[ i ] == '0' ) { br ++ ; }
        else {
            ans ++ ;
        }
        if ( br >= b ) { cout << ans << "\n" ; return ; }
    }
    printf ( "%d\n" , ( n - 1 ) ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}