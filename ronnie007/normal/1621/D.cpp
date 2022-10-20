#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 507

int n ;
int a[ MAXN ][ MAXN ] ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        for ( int j = 1 ; j <= 2 * n ; ++ j ) {
            cin >> a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    long long ans = 0 ;
    for ( int i = n + 1 ; i <= 2 * n ; ++ i ) {
        for ( int j = n + 1 ; j <= 2 * n ; ++ j ) {
            ans += a[ i ][ j ] ;
        }
    }
    set < int > s ;
    for ( auto x : { n + 1 , 2 * n } ) {
        for ( auto y : { 1 , n } ) {
            s.insert ( a[ x ][ y ] ) ;
            s.insert ( a[ 2 * n - x + 1 ][ 2 * n - y + 1 ] ) ;
        }
    }
    ans += *s.begin ( ) ;
    cout << ans << "\n" ;
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