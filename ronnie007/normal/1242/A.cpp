#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;


long long n ;

long long w ( long long x , long long y ) {
    if ( x < y ) { swap ( x , y ) ; }
    if ( y == 0 ) { return x ; }
    return w ( y , ( x % y ) ) ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    long long ans = n ;
    for ( long long i = 2 ; i * i <= n ; ++ i ) {
        if ( ( n % i ) == 0 ) {
            ans = w ( ans , i ) ;
            ans = w ( ans , ( n / i ) ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}