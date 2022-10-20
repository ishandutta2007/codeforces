#include<bits/stdc++.h>
using namespace std ;

#define MAXN 37

int n , m ;
int a[ MAXN ][ MAXN ] ;

map < int , int > w[ 3 * MAXN ] ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            cin >> a[ i ][ j ] ;
        }
    }
}

void solve ( ) {
    int dist = n + m - 2 ;
    for ( int i = 0 ; i <= dist ; ++ i ) {
        w[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            int aux = i + j - 2 ;
            if ( aux > dist - aux ) {
                aux = dist - aux ;
            }
            if ( aux == dist - aux ) { continue ; }
            w[ aux ][ a[ i ][ j ] ] += 1 ;
        }
    }
    int ans = 0 ;
    for ( int i = 0 ; 2 * i < dist ; ++ i ) {
        ans += min ( w[ i ][ 0 ] , w[ i ][ 1 ] ) ;
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