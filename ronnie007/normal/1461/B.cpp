#include<bits/stdc++.h>
using namespace std ;

#define MAXN 507

int n , m ;
string a[ MAXN ] ;
int pref[ MAXN ][ MAXN ] ;

int ans ;

void input ( ) {
    cin >> n >> m ;
    a[ 0 ].clear ( ) ;
    for ( int i = 0 ; i <= m ; ++ i ) {
        a[ 0 ] += '.' ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        a[ i ] = '.' + a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            pref[ i ][ j ] = ( pref[ i ][ j - 1 ] + ( a[ i ][ j ] == '*' ) ) ;
        }
    }
}

void solve ( ) {
    ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            for ( int add = 0 ; add <= n ; ++ add ) {
                if ( i + add > n ) { break ; }
                if ( j - add < 1 || j + add > m ) { break ; }
                if ( pref[ i + add ][ j + add ] - pref[ i + add ][ j - add - 1 ] != 2 * add + 1 ) { break ; }
                ++ ans ;
            }
        }
    }
    cout << ans << "\n" ;
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