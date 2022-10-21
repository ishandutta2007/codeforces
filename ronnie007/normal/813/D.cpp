#include<bits/stdc++.h>
using namespace std ;

#define MAXN 5007
#define MAXVAL 100007

int n ;
int a[ MAXN ] ;
int dp[ MAXN ][ MAXN ] ;

int mxval[ MAXVAL ] ;
int mxmod[ 7 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 7 ; ++ j ) {
            mxmod[ j ] = 0 ;
        }
        for ( int j = 1 ; j <= n ; ++ j ) {
            mxval[ a[ j ] ] = 0 ;
        }
        for ( int j = 1 ; j < i ; ++ j ) {
            mxval[ a[ j ] ] = max ( mxval[ a[ j ] ] , dp[ j ][ i ] ) ;
            mxmod[ ( a[ j ] % 7 ) ] = max ( mxmod[ ( a[ j ] % 7 ) ] , dp[ j ][ i ] ) ;
        }
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            dp[ i ][ j ] = dp[ 0 ][ i ] + 1 ;
            dp[ i ][ j ] = max ( dp[ i ][ j ] , mxval[ a[ j ] - 1 ] + 1 ) ;
            dp[ i ][ j ] = max ( dp[ i ][ j ] , mxval[ a[ j ] + 1 ] + 1 ) ;
            dp[ i ][ j ] = max ( dp[ i ][ j ] , mxmod[ ( a[ j ] % 7 ) ] + 1 ) ;

            mxval[ a[ j ] ] = max ( mxval[ a[ j ] ] , dp[ i ][ j ] ) ;
            mxmod[ ( a[ j ] % 7 ) ] = max ( mxmod[ ( a[ j ] % 7 ) ] , dp[ i ][ j ] ) ;
        }
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = i + 1 ; j <= n ; ++ j ) {
            ans = max ( ans , dp[ i ][ j ] ) ;
        }
    }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}