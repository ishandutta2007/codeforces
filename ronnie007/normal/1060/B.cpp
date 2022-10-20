#include<bits/stdc++.h>
using namespace std ;

long long n ;

int f ( long long x ) {
    int ret = 0 ;
    while ( x > 0 ) {
        ret += ( x % 10 ) ;
        x /= 10 ;
    }
    return ret ;
}

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    long long sr = 1 ;
    while ( 10 * sr <= n ) { sr *= 10 ; }
    -- sr ;
    n -= sr ;
    cout << f ( sr ) + f ( n ) << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}