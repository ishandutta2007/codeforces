#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
int n ;
int a[ MAXN ] ;

bool f[ MAXN ] ;
vector < int > v[ MAXN ] ;

int ret[ MAXN ][ 2 ] ;
int aux[ MAXN ] ;

void init ( ) {
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        if ( f[ i ] == true ) { continue ; }
        for ( int j = i ; j < MAXN ; j += i ) {
            v[ j ].push_back ( i ) ;
            f[ j ] = true ;
        }
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    long long ans = 1 ;
    for ( int i = 1 ; i < MAXN ; ++ i ) {
        ret[ i ][ 0 ] = ret[ i ][ 1 ] = MAXN ; 
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int id = a[ i ] ;
        int sz = v[ id ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int cnt = 0 ;
            int h = v[ id ][ j ] ;
            while ( ( a[ i ] % h ) == 0 ) {
                a[ i ] /= h ;
                ++ cnt ;
            }
            ++ aux[ h ] ;
            if ( ret[ h ][ 0 ] > cnt ) {
                ret[ h ][ 1 ] = ret[ h ][ 0 ] ;
                ret[ h ][ 0 ] = cnt ;
            }
            else if ( ret[ h ][ 1 ] > cnt ) {
                ret[ h ][ 1 ] = cnt ;
            }
        }
    }
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        if ( ret[ i ][ 0 ] == MAXN ) { continue ; }
        if ( aux[ i ] == n ) {
            while ( ret[ i ][ 1 ] > 0 ) {
                -- ret[ i ][ 1 ] ;
                ans *= i ;
            }
        }
        else if ( aux[ i ] == n - 1 ) {
            while ( ret[ i ][ 0 ] > 0 ) {
                -- ret[ i ][ 0 ] ;
                ans *= i ;
            }
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}