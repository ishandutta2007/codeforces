#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std ;

#define MAXN 57

int n , l ;
int a[ MAXN ] ;
int b[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &l ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &b[ i ] ) ;
    }
}

void solve ( ) {
    int i , j , t ;
    for ( i = 0 ; i < l ; i ++ ) {
        for ( j = 0 ; j < l ; j ++ ) {
            vector < int > v1 , v2 ;
            v1.clear ( ) ;
            v2.clear ( ) ;
            int x ;
            for ( t = 1 ; t <= n ; t ++ ) {
                x = ( i - a[ t ] + 100 * l ) % l ;
                v1.push_back ( x ) ;
                x = ( j - b[ t ] + 100 * l ) % l ;
                v2.push_back ( x ) ;
            }
            sort ( v1.begin ( ) , v1.end ( ) ) ;
            sort ( v2.begin ( ) , v2.end ( ) ) ;
            for ( t = 0 ; t < n ; t ++ ) {
                if ( v1[ t ] != v2[ t ] ) { break ; }
            }
            if ( t == n ) { printf ( "YES\n" ) ; return ; }
        }
    }
    printf ( "NO\n" ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}