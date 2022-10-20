#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
string a ;

int dp[ MAXN ][ 2 ][ 2 ] ;

void input ( ) {
    cin >> a ;
    n = a.size ( ) ;
}

void solve ( ) {
    if ( n == 1 ) {
        cout << "0\n" ;
        return ;
    }
    if ( n == 2 ) {
        if ( a[ 0 ] == a[ 1 ] ) {
            cout << "1\n" ;
            return ;
        }
        else {
            cout << "0\n" ;
            return ;
        }
    }
    for ( int i = 0 ; i <= n + 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                dp[ i ][ j ][ t ] = MAXN ; 
            }
        }
    }
    
    for ( int j = 0 ; j < 2 ; ++ j ) {
        for ( int t = 0 ; t < 2 ; ++ t ) {
            if ( j == 0 && t == 0 && a[ 0 ] == a[ 1 ] ) { continue ; }
            dp[ 1 ][ j ][ t ] = j + t ; 
        }
    }
    for ( int i = 1 ; i < n - 1 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 0 ; t < 2 ; ++ t ) {
                if ( dp[ i ][ j ][ t ] == MAXN ) { continue ; }
                for ( int z = 0 ; z < 2 ; ++ z ) {
                    if ( j == 0 && z == 0 && a[ i - 1 ] == a[ i + 1 ] ) { continue ; }
                    if ( t == 0 && z == 0 && a[ i ] == a[ i + 1 ] ) { continue ; }
                    dp[ i + 1 ][ t ][ z ] = min ( dp[ i + 1 ][ t ][ z ] , dp[ i ][ j ][ t ] + z ) ;
                }
            }
        }
    }
    int ans = MAXN ;
    for ( int j = 0 ; j < 2 ; ++ j ) {
        for ( int t = 0 ; t < 2 ; ++ t ) {
            ans = min ( ans , dp[ n - 1 ][ j ][ t ] ) ;
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}