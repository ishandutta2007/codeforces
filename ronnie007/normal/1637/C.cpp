#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
long long a[ MAXN ] ;


void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    if ( n == 3 ) {
        if ( a[ 2 ] % 2 == 1 ) {
            cout << "-1\n" ;
        }
        else {
            cout << a[ 2 ] / 2 << "\n" ;
        }
        return ;
    }
    int cnt = 0 ;
    for ( int i = 2 ; i < n ; ++ i ) {
        if ( a[ i ] > 1 ) { ++ cnt ; }
    }
    if ( cnt == 0 ) {
        cout << "-1\n" ;
        return ;
    }
    for ( int i = 2 ; i < n ; ++ i ) {
        ans += ( a[ i ] / 2 ) ;
        if ( a[ i ] % 2 == 1 ) { ++ ans ; }
    }
    cout << ans << "\n" ;
}


int main ( ) {
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