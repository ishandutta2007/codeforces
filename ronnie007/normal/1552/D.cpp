#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 12

int n ;
int a[ MAXN ] ;
int dig[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int mask = 0 ;
    int lim = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) { lim *= 3 ; }
    for ( int mask = 1 ; mask < lim ; ++ mask ) {
        int h = mask ;
        for ( int i = 0 ; i < n ; ++ i ) {
            dig[ i ] = ( h % 3 ) ;
            h /= 3 ;
        }
        int sm = 0 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( dig[ i ] == 1 ) { sm += a[ i ] ; }
            else if ( dig[ i ] == 2 ) { sm -= a[ i ] ; }
        }
        if ( sm == 0 ) {
            cout << "YES\n" ;
            return ;
        }
    }
    cout << "NO\n" ; 
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}