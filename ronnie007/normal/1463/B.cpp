#include<bits/stdc++.h>
using namespace std ;

#define MAXN 57

int n ;
int a[ MAXN ] ;

long long cnt[ 2 ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    cnt[ 0 ] = cnt[ 1 ] = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt[ ( i & 1 ) ] += ( a[ i ] - 1 ) ;
    }
    int opt = 0 ;
    if ( cnt[ 1 ] < cnt[ 0 ] ) { opt = 1 ; }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( ( i & 1 ) == opt ) { cout << "1 " ; }
        else { cout << a[ i ] << " " ; }
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}