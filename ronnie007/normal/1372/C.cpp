#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

int pref[ MAXN ] ;
int suff[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    pref[ 0 ] = suff[ n + 1 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        pref[ i ] = pref[ i - 1 ] + ( a[ i ] == i ) ;
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        suff[ i ] = suff[ i + 1 ] + ( a[ i ] == i ) ;
    }
    if ( pref[ n ] == n ) {
        cout << "0\n" ;
        return ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ] != i ) {
            int j = i ;
            while ( j < n && a[ j + 1 ] != j + 1 ) { ++ j ; }
            ++ j ;
            if ( suff[ j ] == n - j + 1 ) {
                cout << "1\n" ;
                return ;
            }
            break ;
        }
    }
    cout << "2\n" ;
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