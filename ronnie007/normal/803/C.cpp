#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
using namespace std ;


long long n , k ;

bool f ( long long i ) {
    if ( ( n % i ) != 0 ) { return false ; }
    if ( ( n / i ) < ( k * ( k + 1 ) ) / 2 ) {
        return false ;
    }
    return true ;
}

void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    long long i ;
    long long u = 0 ;
    for ( i = 1 ; i <= k ; i ++ ) {
        u += i ;
        if ( u > n ) { cout << "-1\n" ; return ; }
    }
    long long lst = 1 ;
    for ( i = 1 ; i * i <= n ; i ++ ) {
        if ( f ( i ) == true ) { lst = max ( lst , i ) ; }
        if ( f ( ( n / i ) )== true ) { lst = max ( lst , ( n / i ) ) ; }
    }
    long long cur = 0 ;
    for ( i = 1 ; i <= k ; i ++ ) {
        cur += lst ;
        n -= cur ;
        if ( i == k ) { cur += n ; }
        cout << cur ;
        if ( i == k ) { cout << "\n" ; }
        else { cout << " " ; }
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}