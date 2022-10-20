#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 100007 ;

int n ;
int a[ MAXN ] , aux[ MAXN ] ;
int ans[ MAXN ] ;
bool used[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        aux[ i ] = a[ i ] ;
    }
}

void solve ( ) {
    while ( 1 ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            used[ i ] = false ;
        }
        int x = 1 ;
        while ( used[ x ] == false ) {
            used[ x ] = true ;
            x = aux[ x ] ;
        }
        bool fl = false ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            if ( used[ i ] == false ) { continue ; }
            for ( int j = 1 ; j <= n ; ++ j ) {
                if ( used[ j ] == true ) { continue ; }
                if ( abs ( aux[ i ] - aux[ j ] ) != 1 ) { continue ; }
                swap ( aux[ i ] , aux[ j ] ) ;
                fl = true ;
                if ( fl == true ) { break ; }
            }
            if ( fl == true ) { break ; }
        }
        if ( fl == false ) { break ; }
    }
    ans[ n ] = 1 ;
    for ( int i = n - 1 ; i >= 1 ; -- i ) {
        ans[ i ] = aux[ ans[ i + 1 ] ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ] << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    /// freopen ( "in.txt" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}