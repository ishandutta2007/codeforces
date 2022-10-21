#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    string c ;
    cin >> c ;
    int i ;
    for ( i = 0 ; i < n ; i ++ ) {
        if ( c[ i ] == 'U' ) { a[ i + 1 ] = 0 ; }
        if ( c[ i ] == 'L' ) { a[ i + 1 ] = 1 ; }
        if ( c[ i ] == 'D' ) { a[ i + 1 ] = 2 ; }
        if ( c[ i ] == 'R' ) { a[ i + 1 ] = 3 ; }
    }
}

void solve ( ) {
    int lst = 0 ;
    int i ;
    i = 0 ;
    int p , q ;
    int ans = 0 ;
    while ( lst < n ) {
        p = q = -1 ;
        for ( i = lst + 1 ; i <= n ; i ++ ) {
            if ( a[ i ] == 0 || a[ i ] == 2 ) {
                if ( p == -1 ) { p = a[ i ] ; }
                if ( p != a[ i ] ) { break ; }
            }
            else {
                if ( q == -1 ) { q = a[ i ] ; }
                if ( q != a[ i ] ) { break ; }
            }
        }
        lst = i - 1 ;
        ans ++ ;
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}