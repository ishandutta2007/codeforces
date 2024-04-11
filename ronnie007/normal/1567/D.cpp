#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , k ;
string s ;
int cnt[ 12 ] ;

void input ( ) {
    cin >> s >> k ;
    n = s.size ( ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cnt[ i ] = ( s[ i ] - '0' ) ;
    }
}

void solve ( ) {
    while ( 1 ) {
        int sm = 0 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            sm += cnt[ i ] ;
        }
        if ( sm < k ) {
            for ( int i = n - 2 ; i >= 0 ; -- i ) {
                if ( cnt[ i ] > 0 ) {
                    -- cnt[ i ] ;
                    cnt[ i + 1 ] += 10 ;
                    break ;
                }
            }
        }
        else { break ; }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        while ( k > 1 && cnt[ i ] > 0 ) {
            int hh = 1 ;
            for ( int j = 0 ; j < ( n - i - 1 ) ; ++ j ) { hh *= 10 ; }
            cout << hh << " " ;
            -- k ;
            -- cnt[ i ] ;
        }
    }
    int ret = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int hh = cnt[ i ] ;
        for ( int j = 0 ; j < ( n - i - 1 ) ; ++ j ) { hh *= 10 ; }
        ret += hh ;
    }
    cout << ret << "\n" ;
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