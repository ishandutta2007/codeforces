#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 200007

int n ;
int a[ MAXN ] ;
bool used[ MAXN ] ;
bool en[ MAXN ] ;
int b[ MAXN ] ;

set < int > s ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = false ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        used[ a[ i ] ] = true ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == true ) { ++ ans ; }
    }
    cout << ans << "\n" ;
    if ( ans == n ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            cout << a[ i ] << " " ;
        }
        cout << "\n" ;
        return ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        en[ i ] = false ;
        b[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == true ) { continue ; }
        int x = i ;
        while ( 1 ) {
            if ( en[ a[ x ] ] == false ) {
                b[ x ] = a[ x ] ;
                en[ b[ x ] ] = true ;
                x = a[ x ] ;
            }
            else { break ; }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x = i ;
        while ( 1 ) {
            if ( en[ a[ x ] ] == false ) {
                b[ x ] = a[ x ] ;
                en[ b[ x ] ] = true ;
                x = a[ x ] ;
            }
            else { break ; }
        }
    }
        
    s.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) { s.insert ( i ) ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( b[ i ] == 0 && used[ i ] == false ) {
            auto it = s.begin ( ) ;
            if ( (*it) == i ) { ++ it ; }
            b[ i ] = (*it) ;
            s.erase ( (*it) ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( b[ i ] == 0 ) {
            auto it = s.begin ( ) ;
            b[ i ] = (*it) ;
            s.erase ( (*it) ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << b[ i ] << " " ;
    }
    cout << "\n" ;
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