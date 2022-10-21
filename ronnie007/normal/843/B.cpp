#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std ;

int n , st , val ;

int h[ 2007 ] ;

bool f[ 500007 ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &st , &val ) ;
}

void solve ( ) {
    int i , j ;
    srand ( 1337 ) ;
    int mx = -1 ;
    int id = -1 ;
    printf ( "? %d\n" , st ) ;
    fflush ( stdout ) ;
    int x , y ;
    scanf ( "%d%d" , &x , &y ) ;
    mx = x ;
    id = st ;
    f[ st ] = true ;
    if ( val <= x ) {
        printf ( "! %d\n" , x ) ;
        fflush ( stdout ) ;
        return ;
    }
    else {
        if ( n == 1 ) {
            printf ( "! -1\n" ) ;
            fflush ( stdout ) ;
            return ;
        }
    }
    int steps = 1000 ;
    for ( i = 1 ; i <= steps ; i ++ ) {
        int u ;
        if ( i >= n ) { break ; }
        u = ( ( rand ( ) + rand ( ) ) % ( n - i ) ) ;
        u ++ ;
        for ( j = 1 ; j <= u ; j ++ ) {
            if ( f[ j ] == true ) { u ++ ; }
            if ( j == u ) { break ; }
        }
        f[ u ] = true ;
        h[ i + 1 ] = u ;
        printf ( "? %d\n" , u ) ;
        fflush ( stdout ) ;
        scanf ( "%d%d" , &x , &y ) ;
        if ( x < val ) {
            if ( mx < x ) {
                mx = x ;
                id = u ;
            }
        }
        if ( x == val ) {
            printf ( "! %d\n" , x ) ;
            fflush ( stdout ) ;
            return ;
        }
    }
    int lft = 1996 - steps ;
    while ( lft != 0 ) {
        lft -- ;
        printf ( "? %d\n" , id ) ;
        fflush ( stdout ) ;
        scanf ( "%d%d" , &x , &y ) ;
        if ( val <= x ) {
            printf ( "! %d\n" , x ) ;
            fflush ( stdout ) ;
            return ;
        }
        id = y ;
        if ( id == -1 ) {
            printf ( "! -1\n" ) ;
            fflush ( stdout ) ;
            return ;
        }
    }
    printf ( "! -1\n" ) ;
    fflush ( stdout ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}