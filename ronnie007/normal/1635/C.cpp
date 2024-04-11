#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    if ( a[ n - 1 ] > a[ n ] ) {
        cout << "-1\n" ;
        return ;
    }
    if ( a[ n ] >= 0 ) {
        cout << n - 2 << "\n" ;
        for ( int i = n - 2 ; i >= 1 ; -- i ) {
            cout << i << " " << i + 1 << " " << n << "\n" ;
        }
        return ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        if ( a[ i ] > a[ i + 1 ] ) {
            cout << "-1\n" ;
            return ;
        }
    }
    cout << "0\n" ;
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