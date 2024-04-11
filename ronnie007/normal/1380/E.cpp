#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , k ;
int sz[ MAXN ] ;
vector < int > v[ MAXN ] ;
int h[ MAXN ] ;

int prv[ MAXN ] ;

int ans = 0 ;

void upd ( int pos , int val ) {
    int cnt = 0 ;
    if ( h[ pos ] != 0 ) {
        if ( h[ pos - 1 ] == h[ pos ] ) { ++ cnt ; }
        if ( h[ pos + 1 ] == h[ pos ] ) { ++ cnt ; }
        if ( cnt == 0 ) { -- ans ; }
        else if ( cnt == 2 ) { ++ ans ; }
    }
    cnt = 0 ;
    if ( h[ pos - 1 ] == val ) { ++ cnt ; }
    if ( h[ pos + 1 ] == val ) { ++ cnt ; }
    if ( cnt == 0 ) { ++ ans ; }
    else if ( cnt == 2 ) { -- ans ; }
    h[ pos ] = val ;
}

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        v[ x ].push_back ( i ) ;
        upd ( i , x ) ;
        ++ sz[ x ] ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= k ; ++ i ) {
        prv[ i ] = -1 ;
    }
    -- ans ;
    cout << ans << "\n" ;
    for ( int t = 1 ; t < k ; ++ t ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        x = find ( x ) ;
        y = find ( y ) ;
        if ( sz[ x ] < sz[ y ] ) {
            for ( int i = 0 ; i < sz[ x ] ; ++ i ) {
                upd ( v[ x ][ i ] , y ) ;
                v[ y ].push_back ( v[ x ][ i ] ) ;
            }
            sz[ y ] += sz[ x ] ;
            prv[ x ] = y ;
        }
        else {
            for ( int i = 0 ; i < sz[ y ] ; ++ i ) {
                upd ( v[ y ][ i ] , x ) ;
                v[ x ].push_back ( v[ y ][ i ] ) ;
            }
            sz[ x ] += sz[ y ] ;
            prv[ y ] = x ;
        }
        cout << ans << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}