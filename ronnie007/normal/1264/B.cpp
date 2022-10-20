#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int sm , even , odd ;
int cnt[ 5 ] ;

int a[ MAXN ] ;
int b[ MAXN ] ;

bool interleave ( bool fl ) {
    int pos1 , pos2 ;
    pos1 = pos2 = 0 ;
    int lst = -1 ;
    int turn = -1 ;
    if ( fl == true ) {
        lst = a[ ++ pos1 ] ;
        turn = 1 ;
    }
    else {
        lst = b[ ++ pos2 ] ;
        turn = 0 ;
    }
    vector < int > aux ;
    aux.clear ( ) ;
    aux.push_back ( lst ) ;
    while ( pos1 + pos2 < sm ) {
        if ( turn == 1 ) {
            if ( pos2 == odd ) { return false ; }
            if ( abs ( lst - b[ ++ pos2 ] ) > 1 ) { return false ; }
            aux.push_back ( b[ pos2 ] ) ;
            lst = b[ pos2 ] ;
        }
        else {
            if ( pos1 == even ) { return false ; }
            if ( abs ( lst - a[ ++ pos1 ] ) > 1 ) { return false ; }
            aux.push_back ( a[ pos1 ] ) ;
            lst = a[ pos1 ] ;
        }
        turn ^= 1 ;
    }
    printf ( "YES\n" ) ;
    for ( int i = 0 ; i < sm ; ++ i ) {
        printf ( "%d " , aux[ i ] ) ;
    }
    printf ( "\n" ) ;
    return true ;
}

void input ( ) {
    for ( int i = 0 ; i < 4 ; ++ i ) {
        scanf ( "%d" , &cnt[ i ] ) ;
        sm += cnt[ i ] ;
    }
}

void solve ( ) {
    even = cnt[ 0 ] + cnt[ 2 ] ;
    odd = cnt[ 1 ] + cnt[ 3 ] ;
    if ( even > odd + 1 ) { printf ( "NO\n" ) ; return ; }
    if ( odd > even + 1 ) { printf ( "NO\n" ) ; return ; }
    int id1 = 0 ;
    int id2 = 0 ;
    for ( int i = 0 ; i < 4 ; ++ i ) {
        for ( int j = 0 ; j < cnt[ i ] ; ++ j ) {
            if ( ( i % 2 ) == 0 ) { a[ ++ id1 ] = i ; }
            else { b[ ++ id2 ] = i ; }
        }
    }
    if ( even == odd + 1 ) {
        if ( interleave ( true ) == true ) { return ; }
    }
    else if ( odd == even + 1 ) {
        if ( interleave ( false ) == true ) { return ; }
    }
    else {
        if ( interleave ( true ) == true ) { return ; }
        if ( interleave ( false ) == true ) { return ; }
    }
    printf ( "NO\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}