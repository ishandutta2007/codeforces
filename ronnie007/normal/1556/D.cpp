#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 10007

int n , k ;

int a[ MAXN ] ;
long long b[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
}

void solve ( ) {
    for ( int i = 2 ; i <= n ; ++ i ) {
        int ret ;
        printf ( "and 1 %d\n" , i ) ;
        fflush ( stdout ) ;
        scanf ( "%d" , &ret ) ;
        b[ i ] += ret ;

        printf ( "or 1 %d\n" , i ) ;
        fflush ( stdout ) ;
        scanf ( "%d" , &ret ) ;
        b[ i ] += ret ;
    }
    long long diff = b[ 2 ] - b[ 3 ] ;
    long long sm = 0 ;
    int ret ;
    printf ( "and 2 3\n" ) ;
    fflush ( stdout ) ;
    scanf ( "%d" , &ret ) ;
    sm += ret ;

    printf ( "or 2 3\n" ) ;
    fflush ( stdout ) ;
    scanf ( "%d" , &ret ) ;
    sm += ret ;

    a[ 2 ] = ( sm + diff ) / 2 ;
    a[ 1 ] = b[ 2 ] - a[ 2 ] ;
    for ( int i = 3 ; i <= n ; ++ i ) {
        a[ i ] = b[ i ] - a[ 1 ] ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    printf ( "finish %d\n" , a[ k ] ) ;
    fflush ( stdout ) ;
}

int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}