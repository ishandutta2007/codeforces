#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1507

int n ;
string a ;

int ans[ MAXN ][ 28 ] ;

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    int i , j , t ;
    for ( j = 0 ; j < 26 ; j ++ ) {
        for ( i = 0 ; i < n ; i ++ ) {
            int br = 0 ;
            for ( t = i ; t < n ; t ++ ) {
                if ( ( a[ t ] - 'a' ) != j ) {
                    br ++ ;
                }
                if ( ans[ br ][ j ] < ( t - i + 1 ) ) {
                    ans[ br ][ j ] = ( t - i + 1 ) ;
                }
            }
        }
    }
    for ( j = 0 ; j < 26 ; j ++ ) {
        for ( i = 1 ; i <= n ; i ++ ) {
            if ( ans[ i ][ j ] < ans[ i - 1 ][ j ] ) {
                ans[ i ][ j ] = ans[ i - 1 ][ j ] ;
            }
        }
    }
    int q ;
    cin >> q ;
    while ( q != 0 ) {
        q -- ;
        int x , y ;
        char c ;
        cin >> x >> c ;
        y = ( c - 'a' ) ;
        cout << ans[ x ][ y ] << "\n" ;
    }
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}