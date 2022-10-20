#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
#include<ctime>
#include<set>
using namespace std ;

#define MAXN 2007

int n , k ;
string a[ MAXN ] ;
string b[ MAXN ] ;

int st[ MAXN ][ MAXN ] ;
int en[ MAXN ][ MAXN ] ;
int f[ MAXN ][ MAXN ] ;

int totrow[ MAXN ] ;
int totcol[ MAXN ] ;

int hh[ MAXN ] ;

int ans = 0 ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ i ] = '@' + a[ i ] ;
    }
}


void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            st[ i ][ j ] = ( a[ i ][ j ] == 'B' ) + st[ i ][ j - 1 ] ;
        }
        if ( st[ i ][ n ] == 0 ) { totrow[ i ] = 1 ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = n ; j >= 1 ; -- j ) {
            en[ i ][ j ] = ( a[ i ][ j ] == 'B' ) + en[ i ][ j + 1 ] ;
        }
    }

    for ( int j = 1 ; j + k - 1 <= n ; ++ j ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( st[ i ][ j - 1 ] == 0 && en[ i ][ j + k ] == 0 ) { hh[ i ] = 1 ; }
            else { hh[ i ] = 0 ; }
        }
        for ( int i = 1 ; i <= n ; ++ i ) { hh[ i ] += hh[ i - 1 ] ; }
        for ( int i = 1 ; i + k - 1 <= n ; ++ i ) {
            f[ i ][ j ] = ( hh[ i + k - 1 ] - hh[ i - 1 ] ) ;
        }
    }
    for ( int j = 1 ; j <= n ; ++ j ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            st[ i ][ j ] = ( a[ i ][ j ] == 'B' ) + st[ i - 1 ][ j ] ;
        }
        if ( st[ n ][ j ] == 0 ) { totcol[ j ] = 1 ; }
    }
    for ( int j = 1 ; j <= n ; ++ j ) {
        for ( int i = n ; i >= 1 ; -- i ) {
            en[ i ][ j ] = ( a[ i ][ j ] == 'B' ) + en[ i + 1 ][ j ] ;
        }
    }

    for ( int i = 1 ; i + k - 1 <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( st[ i - 1 ][ j ] == 0 && en[ i + k ][ j ] == 0 ) { hh[ j ] = 1 ; }
            else { hh[ j ] = 0 ; }
        }
        for ( int j = 1 ; j <= n ; ++ j ) { hh[ j ] += hh[ j - 1 ] ; }
        for ( int j = 1 ; j + k - 1 <= n ; ++ j ) {
            f[ i ][ j ] += ( hh[ j + k - 1 ] - hh[ j - 1 ] ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) { totrow[ i ] += totrow[ i - 1 ] ; }
    for ( int j = 1 ; j <= n ; ++ j ) { totcol[ j ] += totcol[ j - 1 ] ; }
    for ( int i = 1 ; i + k - 1 <= n ; ++ i ) {
        for ( int j = 1 ; j + k - 1 <= n ; ++ j ) {
            f[ i ][ j ] += totrow[ i - 1 ] + totcol[ j - 1 ] ;
            f[ i ][ j ] += totrow[ n ] - totrow[ i + k - 1 ] ;
            f[ i ][ j ] += totcol[ n ] - totcol[ j + k - 1 ] ;
            ans = ( ans < f[ i ][ j ] ) ? f[ i ][ j ] : ans ;
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}