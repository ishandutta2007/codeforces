#include<bits/stdc++.h>
using namespace std ;

#define MAXN 10007

int n ;
int a[ MAXN ] , b[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        b[ i ] = a[ i ] ;
    }
}

void solve ( ) {
    sort ( b + 1 , b + n + 1 ) ;
    int cnt = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cnt += ( a[ i ] != b[ i ] ) ;
    }
    if ( cnt != 0 ) { cout << "YES\n" ; }
    else { cout << "NO\n" ; }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// t = 1 ;
    /// scanf ( "%d" , &t ) ;
    cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}