#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 300007

int n , m ;
int a[ 2 * MAXN ] ;
int hit[ MAXN ] ;

int b[ MAXN ] ;
bool used[ MAXN ] ;

bool f ( int sr ) {
    int pos = 1 ;
    for ( int i = sr + 1 ; i <= n ; ++ i ) {
        b[ pos ++ ] = a[ i ] ;
    }
    for ( int i = 1 ; i <= sr ; ++ i ) {
        b[ pos ++ ] = a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = false ;
    }
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == true ) { continue ; }
        int len = 0 ;
        int x = i ;
        while ( 1 ) {
            used[ x ] = true ;
            ++ len ;
            x = b[ x ] ;
            if ( used[ x ] == true ) { break ; }
        }
        cnt += ( len - 1 ) ;
    }
    return ( cnt <= m ) ;
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ n + i ] = a[ i ] ;
    }
    for ( int i = 0 ; i <= n ; ++ i ) {
        hit[ i ] = 0 ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        ++ hit[ ( i - a[ i ] + n ) % n ] ;
    }
    vector < int > cand ;
    cand.clear ( ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( hit[ i ] + 2 * m >= n ) {
            cand.push_back ( i ) ;
        }
    }
    vector < int > ans ;
    ans.clear ( ) ;
    for ( auto x : cand ) {
        if ( f ( x ) == true ) {
            ans.push_back ( x ) ;
        }
    }
    cout << ans.size ( ) ;
    for ( auto x : ans ) {
        cout << " " << x ;
    }
    cout << "\n" ;
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