#include<bits/stdc++.h>
using namespace std ;

#define MAXN 57

int n , m ;
int a[ MAXN ][ MAXN ] ;
int c[ MAXN ] ;
int r[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        r[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        c[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cin >> a[ i ][ j ] ;
            r[ i ] += a[ i ][ j ] ;
            c[ j ] += a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    int f1 , f2 ;
    f1 = f2 = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        f1 += ( r[ i ] == 0 ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        f2 += ( c[ i ] == 0 ) ;
    }
    if ( f1 > f2 ) { f1 = f2 ; }
    if ( ( f1 % 2 ) == 1 ) { cout << "Ashish\n" ; }
    else { cout << "Vivek\n" ; }
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