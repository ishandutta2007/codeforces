#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 100007

int n ;
long long a[ MAXN ] ;
long long aux[ MAXN ] ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        aux[ i ] = a[ i ] - a[ i - 1 ] ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        long long hh = aux[ i ] * ( i - 1 ) * ( n - i + 1 ) ;
        hh -= aux[ i ] ;
        ans += hh ;
    }
    cout << -ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}