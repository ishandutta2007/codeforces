#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n ;

int f ( int sr ) {
    return ( n - ( ( n + sr - 1 ) / sr ) - sr + 1 ) ;
}

bool a[ MAXN ] ;

vector < int > v ;

int ask ( int k ) {
    v.clear ( ) ;
    int sz = 0 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( sz == k ) { break ; }
        if ( ( i % k ) == 0 ) { continue ; }
        if ( a[ i ] == false ) {
            v.push_back ( i ) ;
            ++ sz ;
        }
    }
    if ( sz < k ) { return -1 ; }
    printf ( "%d" , k ) ;
    for ( int i = 0 ; i < k ; ++ i ) {
        printf ( " %d" , v[ i ] + 1 ) ;
        a[ v[ i ] ] = true ;
    }
    printf ( "\n" ) ;
    fflush ( stdout ) ;
    int ret ;
    scanf ( "%d" , &ret ) ;
    return ret ;
}

void reset ( int st , int k ) {
    -- st ;
    for ( int i = 0 ; i < k ; ++ i ) {
        a[ st ++ ] = false ;
        if ( st >= n ) { st = 0 ; }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    int mx = -1 ;
    int k = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int aux = f ( i ) ;
        if ( mx < aux ) {
            mx = aux ;
            k = i ;
        }
    }
    while ( 1 ) {
        int h = ask ( k ) ;
        if ( h < 0 ) { break ; }
        reset ( h , k ) ;
    }
    printf ( "0\n" ) ;
    fflush ( stdout ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}