#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int tot ;
int len ;
pair < int , int > a[ 4 ] ;
int ord[ 4 ] ;
bool rot[ 4 ] ;
int mark[ 1007 ][ 1007 ] ;

void print ( ) {
    printf ( "%d\n" , len ) ;
    int i , j ;
    for ( i = 1 ; i <= len ; i ++ ) {
        for ( j = 1 ; j <= len ; j ++ ) {
            if ( mark[ i ][ j ] == 1 ) { printf ( "A" ) ; }
            if ( mark[ i ][ j ] == 2 ) { printf ( "B" ) ; }
            if ( mark[ i ][ j ] == 3 ) { printf ( "C" ) ; }
        }
        printf ( "\n" ) ;
    }
}

bool check ( ) {
    int i , j ;
    for ( i = 1 ; i <= len ; i ++ ) {
        for ( j = 1 ; j <= len ; j ++ ) {
            mark[ i ][ j ] = 0 ;
        }
    }
    int id = 1 ;

    for ( id = 1 ; id <= 3 ; id ++ ) {
        for ( i = 1 ; i <= len ; i ++ ) {
            for ( j = 1 ; j <= len ; j ++ ) {
                if ( mark[ i ][ j ] == 0 ) { break ; }
            }
            if ( j != len + 1 ) { break ; }
        }
        int stx = i ;
        int sty = j ;
        int x = a[ ord[ id ] ].first ;
        int y = a[ ord[ id ] ].second ;
        if ( rot[ id ] == true ) { swap ( x , y ) ; }
        if ( stx + x - 1 > len ) { return false ; }
        if ( sty + y - 1 > len ) { return false ; }
        for ( i = 0 ; i < x ; i ++ ) {
            for ( j = 0 ; j < y ; j ++ ) {
                if ( mark[ stx + i ][ sty + j ] != 0 ) { return false ; }
                mark[ stx + i ][ sty + j ] = id ;
            }
        }
    }
    return true ;
}

bool f ( ) {
    int val = 0 ;
    for ( val = 0 ; val <= 7 ; val ++ ) {
        if ( ( val & 1 ) != 0 ) { rot[ 1 ] = 1 ; }
        else { rot[ 1 ] = 0 ; }

        if ( ( val & 2 ) != 0 ) { rot[ 2 ] = 1 ; }
        else { rot[ 2 ] = 0 ; }

        if ( ( val & 4 ) != 0 ) { rot[ 3 ] = 1 ; }
        else { rot[ 3 ] = 0 ; }
        if ( check ( ) == true ) { return true ; }
    }
    return false ;
}

void input ( ) {
    int i ;
    for ( i = 1 ; i <= 3 ; i ++ ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        tot += ( a[ i ].first * a[ i ].second ) ;
    }
}

void solve ( ) {
    int i ;
    len = 0 ;
    while ( len * len < tot ) { len ++ ; }
    if ( len * len != tot ) {
        printf ( "-1\n" ) ;
        return ;
    }
    for ( i = 1 ; i <= 3 ; i ++ ) { ord[ i ] = i ; }
    if ( f ( ) == true ) { print ( ) ; return ; }
    while ( next_permutation ( ord + 1 , ord + 4 ) ) {
        if ( f ( ) == true ) { print ( ) ; return ; }
    }
    if ( f ( ) == true ) { print ( ) ; return ; }
    printf ( "-1\n" ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}