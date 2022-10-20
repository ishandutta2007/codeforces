#include<bits/stdc++.h>
using namespace std ;

#define MAXN 400007

int n ;
vector < int > a , b ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        if ( x > 0 ) { a.push_back ( x ) ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        if ( x > 0 ) { b.push_back ( x ) ; }
    }
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        a.push_back ( a[ i ] ) ;
    }
}

void solve ( ) {
    int st ;
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        if ( a[ i ] == b[ 0 ] ) { st = i ; break ; }
    }
    for ( int i = 0 ; i < n - 1 ; ++ i ) {
        if ( b[ i ] != a[ st + i ] ) {
            printf ( "NO\n" ) ;
            return ;
        }
    }
    printf ( "YES\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}