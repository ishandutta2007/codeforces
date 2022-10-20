#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 1000007

int n ;
int a[ MAXN ] ;

long long w[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 , x ; i <= n ; ++ i ) {
        cin >> x ;
        ++ a[ x ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = MAXN - 1 ; i >= 1 ; -- i ) {
        int aux = 0 ;
        for ( int j = i ; j < MAXN ; j += i ) {
            aux += a[ j ] ;
        }
        w[ i ] = 1LL * aux * ( aux - 1 ) / 2 ;
        for ( int j = 2 * i ; j < MAXN ; j += i ) {
            w[ i ] -= w[ j ] ;
        }
        if ( w[ i ] > 0 && a[ i ] == 0 ) {
            a[ i ] = 1 ;
            w[ i ] += aux ;
            ++ ans ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}