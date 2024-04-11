#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1507

int n ;
int a[ MAXN ][ MAXN ] ;

int dx[ 4 ] = { 0 , -1 , 0 , 1 } ;
int dy[ 4 ] = { 1 , 0 , -1 , 0 } ;

void input ( ) {
    scanf ( "%d" , &n ) ;
}

void solve ( ) {
    if ( n <= 2 ) {
        printf ( "-1\n" ) ;
        return ;
    }
    int stx , sty ;
    int mx = n * n ; 
    stx = sty = 1000 ;
    a[ 1000 ][ 1000 ] = mx ;
    a[ 1000 ][ 1001 ] = mx - 4 ;
    a[ 1000 ][ 1002 ] = mx - 3 ;
    a[ 1001 ][ 1000 ] = mx - 2 ;
    a[ 1001 ][ 1001 ] = mx - 7 ;
    a[ 1001 ][ 1002 ] = mx - 1 ;
    a[ 1002 ][ 1000 ] = mx - 8 ;
    a[ 1002 ][ 1001 ] = mx - 6 ;
    a[ 1002 ][ 1002 ] = mx - 5 ;
    int x , y ;
    x = 1003 ; y = 1000 ;
    int dir = 0 ;
    int aux = mx - 9 ;
    int id = 3 ;
    while ( aux > 0 ) {
        a[ x ][ y ] = aux -- ;
        for ( int tm = 0 ; tm < 2 ; ++ tm ) {
            for ( int i = 0 ; i < id ; ++ i ) {
                x += dx[ dir ] ; y += dy[ dir ] ;
                a[ x ][ y ] = aux -- ;
                stx = min ( stx , x ) ;
                sty = min ( sty , y ) ;
            }
            if ( tm == 1 ) {
                x += dx[ dir ] ; y += dy[ dir ] ;
            }
            dir = ( dir + 1 ) % 4 ;
        }
        ++ id ;
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            printf ( "%d " , a[ stx + i ][ sty + j ] ) ;
        }
        printf ( "\n" ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}