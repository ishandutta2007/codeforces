#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n , k ;
int a[ MAXN ] ;
int b[ MAXN ] ;

void input ( ) {
    cin >> n >> k ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
    }
}

void solve ( ) {
    if ( a[ 1 ] == 0 ) { cout << "NO\n" ; return ; }
    if ( a[ k ] == 1 ) { cout << "YES\n" ; return ; }
    if ( b[ k ] == 0 ) { cout << "NO\n" ; return ; }
    for ( int i = k ; i <= n ; ++ i ) {
        if ( a[ i ] == 0 ) { continue ; }
        if ( b[ i ] == 1 ) {
            cout << "YES\n" ;
            return ;
        }
    }
    cout << "NO\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}