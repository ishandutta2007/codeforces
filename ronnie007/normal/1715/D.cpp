#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MAXN = 2e5 + 7 ;

int n , q ;
int ans[ MAXN ] ;

vector < pair < int , int > > v[ MAXN ] ;

bool hh[ MAXN ][ 31 ][ 2 ] ;

void solve ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        int x , y , val ;
        cin >> x >> y >> val ;
        if ( x > y ) { swap ( x , y ) ; }
        if ( x != y ) { 
            for ( int j = 0 ; j < 30 ; ++ j ) {
                if ( ( val & ( 1 << j ) ) == 0 ) {
                    hh[ x ][ j ][ 0 ] = hh[ y ][ j ][ 0 ] = true ;
                }
            }
            v[ x ].push_back ( { y , val } ) ;
        }
        else {
            for ( int j = 0 ; j < 30 ; ++ j ) {
                if ( ( val & ( 1 << j ) ) == 0 ) {
                    hh[ x ][ j ][ 0 ] = true ;
                }
                else {
                    hh[ x ][ j ][ 1 ] = true ;
                }
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 29 ; j >= 0 ; -- j ) {
            if ( hh[ i ][ j ][ 1 ] == true ) {
                ans[ i ] += ( 1 << j ) ;
                continue ;
            }
            if ( hh[ i ][ j ][ 0 ] == true ) {
                for ( auto [ wh , val ] : v[ i ] ) {
                    if ( ( val & ( 1 << j ) ) == 0 ) { continue ; }
                    hh[ wh ][ j ][ 1 ] = true ;
                }
                continue ;
            }
            bool ok = true ;
            for ( auto [ wh , val ] : v[ i ] ) {
                if ( ( val & ( 1 << j ) ) == 0 ) { continue ; }
                if ( hh[ wh ][ j ][ 0 ] == true ) {
                    ok = false ;
                    break ;
                }
            }
            if ( ok == true ) {
                for ( auto [ wh , val ] : v[ i ] ) {
                    if ( ( val & ( 1 << j ) ) == 0 ) { continue ; }
                    hh[ wh ][ j ][ 1 ] = true ;
                }
                hh[ i ][ j ][ 0 ] = true ;
            }
            else {
                ans[ i ] += ( 1 << j ) ;
                hh[ i ][ j ][ 1 ] = true ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}