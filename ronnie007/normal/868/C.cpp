#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , k ;
int a[ MAXN ][ 7 ] ;

int br[ 107 ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= k ; j ++ ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
        int id = 1 * a[ i ][ 1 ] + 2 * a[ i ][ 2 ] + 4 * a[ i ][ 3 ] + 8 * a[ i ][ 4 ] ;
        br[ id ] ++ ;
    }
}

void solve ( ) {
    int i , j , t ;
    for ( i = 0 ; i < 16 ; i ++ ) {
        for ( j = 0 ; j < 16 ; j ++ ) {
            if ( br[ i ] == 0 || br[ j ] == 0 ) { continue ; }
            int x , y ;
            x = i ;
            y = j ;
            for ( t = 0 ; t < 4 ; t ++ ) {
                int u1 = ( x % 2 ) ;
                int u2 = ( y % 2 ) ;
                x /= 2 ;
                y /= 2 ;
                if ( u1 == 1 && u2 == 1 ) { break ; }
            }
            if ( t == 4 ) { printf ( "YES\n" ) ; return ; }
        }
    }
    printf ( "NO\n" ) ;
}

int main ( ) {
    input ( ) ;
    solve ( ) ;
    return 0 ;
}