#include<bits/stdc++.h>
using namespace std ;

#define MAXN 307

int n , k ;

int a[ MAXN ][ MAXN ] ;
int r[ MAXN ] ;
int c[ MAXN ] ;


void input ( ) {
    cin >> n >> k ;
}

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        r[ i ] = c[ i ] = 0 ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            a[ i ][ j ] = 0 ;
        }
    }
    for ( int st = 1 ; st <= n ; ++ st ) {
        int x , y ;
        x = 1 ;
        y = st ;
        if ( k == 0 ) { break ; }
        int lft = n ;
        while ( lft > 0 && k > 0 ) {
            -- lft ; -- k ;
            a[ x ][ y ] = 1 ;
            ++ r[ x ] ; ++ c[ y ] ;
            ++ x ; ++ y ;
            if ( x == n + 1 ) { x = 1 ; }
            if ( y == n + 1 ) { y = 1 ; }
        }
    }
    sort ( r + 1 , r + n + 1 ) ;
    sort ( c + 1 , c + n + 1 ) ;
    cout << ( r[ n ] - r[ 1 ] ) * ( r[ n ] - r[ 1 ] ) + ( c[ n ] - c[ 1 ] ) * ( c[ n ] - c[ 1 ] ) << "\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            cout << a[ i ][ j ] ;
        }
        cout << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}