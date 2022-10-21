#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 2007

int n , m , k ;
string a[ MAXN ] ;

int rw[ MAXN ][ MAXN ] ;
int cl[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n >> m >> k ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> a[ i ] ;
        a[ i ] = ( '#' + a[ i ] ) ;
    }
}

void solve ( ) {
    int i , j ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            rw[ i ][ j ] = rw[ i ][ j - 1 ] ;
            if ( a[ i ][ j ] == '*' ) {
                rw[ i ][ j ] ++ ;
            }
            cl[ i ][ j ] = cl[ i - 1 ][ j ] ;
            if ( a[ i ][ j ] == '*' ) {
                cl[ i ][ j ] ++ ;
            }
        }
    }
    int ans = 0 ;
    for ( i = 1 ; i <= n ; i ++ ) {
        for ( j = 1 ; j <= m ; j ++ ) {
            if ( ( j + k - 1 ) <= m ) {
                if ( rw[ i ][ j - 1 ] == rw[ i ][ j + k - 1 ] ) { ans ++ ; }
            }
            if ( ( i + k - 1 ) <= n ) {
                if ( cl[ i - 1 ][ j ] == cl[ i + k - 1 ][ j ] ) { ans ++ ; }
            }
        }
    }
    if ( k == 1 ) { ans /= 2 ; }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}