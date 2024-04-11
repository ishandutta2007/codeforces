#include<bits/stdc++.h>
using namespace std ;

#define MAXN 5007

int n ;
int a[ MAXN ] ;

int pos[ MAXN ] ;

vector < int > v[ MAXN ] ;

int fst[ MAXN ] ;
int lst[ MAXN ] ;

int dp[ MAXN ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
        v[ a[ i ] ].push_back ( i ) ;
        pos[ i ] = 1 ;
    }
    for ( i = 0 ; i <= 5000 ; i ++ ) {
        if ( v[ i ].size ( ) == 0 ) { continue ; }
        fst[ i ] = v[ i ][ 0 ] ;
        lst[ i ] = v[ i ][ v[ i ].size ( ) - 1 ] ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        dp[ i ] = max ( dp[ i ] , dp[ i - 1 ] ) ;
        if ( pos[ i ] == 0 ) { continue ; }
        int en = i ;
        int cur = 0 ;
        for ( j = i ; j <= n ; j ++ ) {
            if ( pos[ j ] == 0 ) { break ; }
            if ( j == fst[ a[ j ] ] ) {
                cur ^= a[ j ] ;
                en = max ( en , lst[ a[ j ] ] ) ;
            }
            if ( en <= j ) {
                dp[ j ] = max ( dp[ j ] , cur + dp[ i - 1 ] ) ;
            }
        }
        int sz = v[ a[ i ] ].size ( ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            pos[ v[ a[ i ] ][ j ] ] = 0 ;
        }
    }
    printf ( "%d\n" , dp[ n ] ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}