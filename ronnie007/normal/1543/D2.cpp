#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , k ;

vector < int > v ;

int sub ( int x , int y ) {
    v.clear ( ) ;
    while ( x > 0 || y > 0 ) {
        int dig1 = ( x % k ) ;
        int dig2 = ( y % k ) ;

        v.push_back ( ( dig1 - dig2 + k ) % k ) ;
        x /= k , y /= k ;
    }
    int ret = 0 ;
    reverse ( v.begin ( ) , v.end ( ) ) ;
    for ( auto x : v ) {
        ret = ( ret * k + x ) ;
    }
    return ret ;
}

int add ( int x , int y ) {
    v.clear ( ) ;
    while ( x > 0 || y > 0 ) {
        int dig1 = ( x % k ) ;
        int dig2 = ( y % k ) ;

        v.push_back ( ( dig1 + dig2 ) % k ) ;
        x /= k , y /= k ;
    }
    int ret = 0 ;
    reverse ( v.begin ( ) , v.end ( ) ) ;
    for ( auto x : v ) {
        ret = ( ret * k + x ) ;
    }
    return ret ;
}


void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    int ret ;
    int hh = 0 ;
    int par = 1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        par ^= 1 ;
        int aux ;
        if ( par == 1 ) { aux = sub ( hh , i ) ; }
        else { aux = add ( hh , i ) ; }
        cout << aux << "\n" ;
        fflush ( stdout ) ;

        cin >> ret ;
        if ( ret == -1 ) { exit ( 0 ) ; }
        if ( ret == 1 ) { return ; }
        hh = sub ( aux , hh ) ;
    }
}

int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
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