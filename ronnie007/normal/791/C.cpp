#include<bits/stdc++.h>
using namespace std ;

#define MAXN 57

int n , k ;
string a[ MAXN ] ;

int ans[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    int i ;
    for ( i = 1 ; i <= n - k + 1 ; i ++ ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int i , j , t ;
    for ( i = 1 ; i <= k - 1 ; i ++ ) {
        ans[ i ] = i ;
    }
    if ( a[ 1 ] == "YES" ) {
        ans[ k ] = k ;
    }
    else {
        ans[ k ] = 1 ;
    }
    for ( i = k + 1 ; i <= n ; i ++ ) {
        if ( a[ i - k + 1 ] == "YES" ) {
            for ( j = 1 ; j <= 51 ; j ++ ) {
                for ( t = i - k + 1 ; t < i ; t ++ ) {
                    if ( ans[ t ] == j ) { break ; }
                }
                if ( t == i ) { ans[ i ] = j ; break ; }
            }
        }
        else {
            ans[ i ] = ans[ i - k + 1 ] ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( ans[ i ] <= 26 ) {
            cout << (char('A' + ( ans[ i ] - 1 ) )) << " " ;
        }
        else {
            cout << (char('A' + ( ans[ i ] - 27 ) )) << "a " ;
        }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}