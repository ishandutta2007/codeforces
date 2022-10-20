#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 100007

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;
int cnt[ MAXN ][ 2 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < MAXN ; ++ i ) {
        cnt[ i ][ 0 ] = cnt[ i ][ 1 ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        b[ i ] = a[ i ] ;
        ++ cnt[ a[ i ] ][ ( i % 2 ) ] ;
    }
}

void solve ( ) {
    sort ( b + 1 , b + n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        -- cnt[ b[ i ] ][ ( i % 2 ) ] ;
        if ( cnt[ b[ i ] ][ ( i % 2 ) ] < 0 ) {
            cout << "NO\n" ;
            return ;
        }
    }
    cout << "YES\n" ;
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