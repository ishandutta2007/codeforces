#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
string a ;

int ans ;

int dp[ 2 * MAXN ][ 2 ][ 3 ] ;

int cost ( int pos , int type ) {
    if ( a[ pos - 1 ] == 'L' && type == 1 ) { return 1 ; }
    if ( a[ pos - 1 ] == 'R' && type == 0 ) { return 1 ; }
    return 0 ;
}

void proc ( int f1 , int f2 ) {
    int lst ;
    lst = 1 ;
    if ( f2 == f1 ) { lst = 2 ; }

    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 1 ; t <= 2 ; ++ t ) {
                dp[ i ][ j ][ t ] = MAXN ; 
            }
        }
    }
    dp[ 2 ][ f2 ][ lst ] = cost ( 1 , f1 ) + cost ( 2 , f2 ) ;

    for ( int i = 2 ; i < n ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            for ( int t = 1 ; t <= 2 ; ++ t ) {
                for ( int nw = 0 ; nw < 2 ; ++ nw ) {
                    if ( nw == j && t == 2 ) { continue ; }
                    int coef = 1 ;
                    if ( nw == j ) { ++ coef ; }
                    dp[ i + 1 ][ nw ][ coef ] = min ( dp[ i + 1 ][ nw ][ coef ] , dp[ i ][ j ][ t ] + cost ( i + 1 , nw ) ) ;
                }
            }
        }
    }
    for ( int j = 0 ; j < 2 ; ++ j ) {
        for ( int t = 1 ; t <= 2 ; ++ t ) {
            if ( j == f1 && t + lst >= 3 ) { continue ; }
            ans = min ( ans , dp[ n ][ j ][ t ] ) ;
        }
    }
}

void input ( ) {
    cin >> n ;
    cin >> a ;
}

void solve ( ) {
    ans = MAXN ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            proc ( i , j ) ;
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