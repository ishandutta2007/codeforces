#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 1e5 + 7 ;

int n , q ;
int a[ MAXN ] ;

ll get ( ll i ) {
    return i * ( n - i ) ;
}

void solve ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    ll init = 1LL * n * ( n + 1 ) / 2 ;
    ll add = 0 ;
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( a[ i ] != a[ i + 1 ] ) {
            add += get ( i ) ;
        }
    }
    while ( q -- ) {
        int i , nw ;
        cin >> i >> nw ;
        if ( i > 1 && a[ i ] != a[ i - 1 ] ) {
            add -= get ( i - 1 ) ;
        }
        if ( i < n && a[ i ] != a[ i + 1 ] ) {
            add -= get ( i ) ;
        }
        a[ i ] = nw ;
        if ( i > 1 && a[ i ] != a[ i - 1 ] ) {
            add += get ( i - 1 ) ;
        }
        if ( i < n && a[ i ] != a[ i + 1 ] ) {
            add += get ( i ) ;
        }
        cout << init + add << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}