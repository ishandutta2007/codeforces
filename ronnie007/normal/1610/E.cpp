#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 200007

int n ;
vector < int > v ;

void input ( ) {
    cin >> n ;
    v.resize ( n ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> v[ i ] ;
    }
}

void solve ( ) {
    int mx = 0 ;
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        int cnt = 2 ;
        int lst = i + 1 ;
        if ( v[ i ] == v[ i + 1 ] ) {
            if ( i > 0 && v[ i ] == v[ i - 1 ] ) { continue ; }
        }
        while ( 1 ) {
            auto ret = lower_bound ( v.begin ( ) + lst + 1 , v.end ( ) , 2 * v[ lst ] - v[ i ] ) ;
            if ( ret == v.end ( ) ) { break ; }
            lst = ret - v.begin ( ) ;
            ++ cnt ;
        }
        mx = max ( mx , cnt ) ;
    }
    cout << n - mx << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}