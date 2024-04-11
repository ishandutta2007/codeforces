#include<bits/stdc++.h>
using namespace std ;

#define MAXN 2007

int n ;
string a , b ;

int suff1[ MAXN ][ 27 ] ;
int suff2[ MAXN ][ 27 ] ;
int dp[ MAXN ][ MAXN ] ;

void input ( ) {
    cin >> n ;
    cin >> a >> b ;
    for ( int i = 0 ; i < 26 ; ++ i ) {
        suff1[ n + 1 ][ i ] = suff2[ n + 1 ][ i ] = 0 ;
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = 0 ; j < 26 ; ++ j ) {
            suff1[ i ][ j ] = suff1[ i + 1 ][ j ] ;
            suff2[ i ][ j ] = suff2[ i + 1 ][ j ] ;
        }
        ++ suff1[ i ][ ( a[ i - 1 ] - 'a' ) ] ;
        ++ suff2[ i ][ ( b[ i - 1 ] - 'a' ) ] ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i < 26 ; ++ i ) {
        if ( suff1[ 1 ][ i ] != suff2[ 1 ][ i ] ) {
            cout << "-1\n" ;
            return ;
        }
    }
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j <= n ; ++ j ) {
            dp[ i ][ j ] = MAXN ;
        }
    }
    dp[ 0 ][ 0 ] = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        for ( int j = i ; j <= n ; ++ j ) {
            if ( i > 0 && a[ i - 1 ] == b[ j - 1 ] ) {
                dp[ i ][ j ] = min ( dp[ i ][ j ] , dp[ i - 1 ][ j - 1 ] ) ;
            }
            if ( j > 0 ) {
                int val = ( b[ j - 1 ] - 'a' ) ;
                if ( suff1[ i + 1 ][ val ] > suff2[ j + 1 ][ val ] ) {
                    dp[ i ][ j ] = min ( dp[ i ][ j ] , dp[ i ][ j - 1 ] ) ;
                }
            }
            if ( i > 0 ) {
                dp[ i ][ j ] = min ( dp[ i ][ j ] , dp[ i - 1 ][ j ] + 1 ) ;
            }
        }
    }
    cout << dp[ n ][ n ] << "\n" ;
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