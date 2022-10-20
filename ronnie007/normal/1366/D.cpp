#include<bits/stdc++.h>
using namespace std ;

#define MAXN 10000007
#define ww 500007

int n ;
int a[ ww ] ;

int ans1[ ww ] ;
int ans2[ ww ] ;

bool f[ MAXN ] ;

int fst[ MAXN ][ 2 ] ;

int coef[ MAXN ] ;


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        ans1[ i ] = ans2[ i ] = -1 ;
    }
}

void solve ( ) {
    long long aux ;
    for ( int i = 2 ; i < MAXN ; ++ i ) {
        if ( f[ i ] == true ) { continue ; }
        for ( int j = i ; j < MAXN ; j += i ) {
            if ( fst[ j ][ 0 ] == 0 ) { fst[ j ][ 0 ] = i ; }
            else if ( fst[ j ][ 1 ] == 0 ) { fst[ j ][ 1 ] = i ; }
            f[ j ] = true ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( ( a[ i ] % 2 ) == 0 ) {
            int aux = a[ i ] ;
            while ( ( a[ i ] % 2 ) == 0 ) { a[ i ] /= 2 ; }
            if ( a[ i ] > 1 ) {
                ans1[ i ] = 2 ;
                ans2[ i ] = a[ i ] ;
            }
        }
        else {
            if ( fst[ a[ i ] ][ 1 ] != 0 ) {
                ans1[ i ] = fst[ a[ i ] ][ 0 ] ;
                ans2[ i ] = fst[ a[ i ] ][ 1 ] ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , ans1[ i ] ) ;
    }
    printf ( "\n" ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , ans2[ i ] ) ;
    }
    printf ( "\n" ) ;

}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}