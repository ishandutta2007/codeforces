#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std ;

#define MAXN 57

int n ;
int a[ MAXN ] ;
int b[ MAXN ] ;

vector < int > v[ MAXN ] ;

void perform ( int id ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        b[ i ] = a[ i ] ;
    }
    int aux = n ;
    int sz = v[ id ].size ( ) ;
    int tot = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        tot += v[ id ][ i ] ;
        for ( int j = 0 ; j < v[ id ][ i ] ; ++ j ) {
            a[ aux -- ] = b[ tot - j ] ;
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
    if ( n == 1 ) { printf ( "0\n" ) ; return ; }
    int len = n - 1 ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        int st , en ;
        int pos ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( a[ j ] == i ) { pos = j ; }
            if ( a[ j ] == 1 ) { st = j ; }
            if ( a[ j ] == i - 1 ) { en = j ; }
        }
        if ( st <= en && en < pos ) {
            for ( int j = 1 ; j <= en ; ++ j ) {
                    v[ i - 1 ].push_back ( 1 ) ;
            }
            v[ i - 1 ].push_back ( pos - en ) ;
            for ( int j = pos + 1 ; j <= n ; ++ j ) {
                v[ i - 1 ].push_back ( 1 ) ;
            }
        }
        else if ( pos < en && en <= st ) {
            for ( int j = 1 ; j < pos ; ++ j ) {
                v[ i - 1 ].push_back ( 1 ) ;
            }
            v[ i - 1 ].push_back ( en - pos ) ;
            for ( int j = en ; j <= n ; ++ j ) {
                v[ i - 1 ].push_back ( 1 ) ;
            }
        }
        else if ( pos < st && st <= en ) {
            for ( int j = 1 ; j < pos ; ++ j ) {
                v[ i - 1 ].push_back ( 1 ) ;
            }
            v[ i - 1 ].push_back ( st - pos ) ;
            v[ i - 1 ].push_back ( en - st + 1 ) ;
            for ( int j = en + 1 ; j <= n ; ++ j ) {
                v[ i - 1 ].push_back ( 1 ) ;
            }
        }
        else { // en <= st && st < pos
            for ( int j = 1 ; j < en ; ++ j ) {
                v[ i - 1 ].push_back ( 1 ) ;
            }
            v[ i - 1 ].push_back ( st - en + 1 ) ;
            v[ i - 1 ].push_back ( pos - st ) ;
            for ( int j = pos + 1 ; j <= n ; ++ j ) {
                v[ i - 1 ].push_back ( 1 ) ;
            }
        }
        perform ( i - 1 ) ;
    }
    if ( a[ 1 ] == n ) {
        ++ len ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            v[ len ].push_back ( 1 ) ;
        }
    }
    printf ( "%d\n" , len ) ;
    for ( int i = 1 ; i <= len ; ++ i ) {
        int sz = v[ i ].size ( ) ;
        printf ( "%d" , sz ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            printf ( " %d" , v[ i ][ j ] ) ;
        }
        printf ( "\n" ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}