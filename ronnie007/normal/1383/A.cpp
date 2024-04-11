#include<bits/stdc++.h>
using namespace std ;

int n ;
string a , b ;
bool fl[ 27 ][ 27 ] ;
int prv[ 27 ] ;
int ans = 0 ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void unite ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        ++ ans ;
        prv[ k1 ] = k2 ;
    }
}

void input ( ) {
    cin >> n ;
    cin >> a >> b ;
}

void solve ( ) {
    for ( int i = 0 ; i <= 23 ; ++ i ) {
        for ( int j = 0 ; j <= 23 ; ++ j ) {
            fl[ i ][ j ] = false ;
        }
    }
    for ( int i = 0 ; i < n ; ++ i ) {
        if ( a[ i ] > b[ i ] ) {
            cout << "-1\n" ;
            return ;
        }
        fl[ ( a[ i ] - 'a' ) ][ ( b[ i ] - 'a' ) ] = true ;
    }
    for ( int i = 0 ; i <= 23 ; ++ i ) {
        prv[ i ] = -1 ;
    }
    ans = 0 ;
    for ( int len = 1 ; len <= 20 ; ++ len ) {
        for ( int i = 0 ; i + len <= 20 ; ++ i ) {
            if ( fl[ i ][ i + len ] == true ) {
                unite ( i , i + len ) ;
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