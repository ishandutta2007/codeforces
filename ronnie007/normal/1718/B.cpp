#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define fi first
#define se second

int n ;
pair < int , int > a[ 101 ] ;
ll aux[ 50 ] ;

void init ( ) {
    aux[ 0 ] = aux[ 1 ] = 1 ;
    for ( int i = 2 ; i < 50 ; ++ i ) {
        aux[ i ] = aux[ i - 1 ] + aux[ i - 2 ] ;
    }
}

void solve ( ) {
    cin >> n ;
    ll sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].fi ;
        sm += a[ i ].fi ;
        a[ i ].se = i ;
    }
    sort ( a + 1 , a + n + 1 , greater < pair < int , int > > ( ) ) ;
    int wh = 0 ; ll sr = 0 ;
    while ( sr < sm ) {
        sr += aux[ wh ++ ] ;
    }
    if ( sr != sm ) {
        cout << "NO\n" ;
        return ;
    }
    int lst = -1 ;
    for ( int i = wh - 1 ; i >= 0 ; -- i ) {
        if ( a[ 1 ].fi < aux[ i ] || a[ 1 ].se == lst ) {
            cout << "NO\n" ;
            return ;
        }
        a[ 1 ].fi -= aux[ i ] ;
        lst = a[ 1 ].se ;
        int ch = 1 ;
        while ( ch + 1 <= n && a[ ch ].fi <= a[ ch + 1 ].fi ) {
            swap ( a[ ch ] , a[ ch + 1 ] ) ;
            ++ ch ;
        }
    }
    cout << "YES\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}