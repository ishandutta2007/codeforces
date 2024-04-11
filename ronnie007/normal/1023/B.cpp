#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
using namespace std ;

long long k , n ;

void input ( ) {
    cin >> k >> n ;
}

void solve ( ) {
    if ( 2 * k <= n ) { cout << "0\n" ; return ; }
    long long a , b , c , d ;
    a = 1 ;
    b = k ;
    c = n - k ;
    d = n - 1 ;
    a = max ( a , c ) ;
    b = min ( b , d ) ;
    if ( a >= b ) { cout << "0\n" ; return ; }
    cout << ( b - a + 1 ) / 2 << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}