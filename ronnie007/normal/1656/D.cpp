#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

long long n ;

void input ( ) {
    cin >> n ;
}

void solve ( ) {
    long long rem = n ;
    long long coef = 1 ;
    while ( ( rem % 2 ) == 0 ) {
        rem /= 2 ;
        coef *= 2 ;
    }
    if ( rem == 1 ) {
        cout << "-1\n" ;
        return ;
    }
    long long hh = ( rem / 2 ) ;
    long long mn = hh - coef + 1 ;
    long long sub = 0 ;
    if ( mn <= 0 ) { ++ sub ; }
    if ( mn < 0 ) {
        sub += 2 * ( -mn ) ;
    }
    cout << coef + coef - sub << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}