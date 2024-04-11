#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n , m ;
int c1 , c2 ;

string a[ MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    cin >> c1 >> c2 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    if ( 2 * c1 <= c2 ) {
        int cnt = 0 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            for ( int j = 0 ; j < m ; ++ j ) {
                if ( a[ i ][ j ] == '.' ) { ++ cnt ; }
            }
        }
        cout << cnt * c1 << "\n" ;
    }
    else {
        int ans = 0 ;
        for ( int i = 0 ; i < n ; ++ i ) {
            int f = 0 ;
            for ( int j = 0 ; j < m ; ++ j ) {
                if ( a[ i ][ j ] == '.' ) { ++ f ; }
                else {
                    ans += ( f / 2 ) * c2 ;
                    ans += ( f % 2 ) * c1 ;
                    f = 0 ;
                }
            }
            ans += ( f / 2 ) * c2 ;
            ans += ( f % 2 ) * c1 ;
        }
        cout << ans << "\n" ;
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