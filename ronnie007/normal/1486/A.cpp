#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) { cin >> a[ i ] ; }
}

void solve ( ) {
    long long aux = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        aux += a[ i ] ;
        if ( aux < ( i - 1 ) ) {
            cout << "NO\n" ;
            return ;
        }
        aux -= ( i - 1 ) ;
    }
    cout << "YES\n" ;
}

int main ( ) {
    // ios_base :: sync_with_stdio ( false ) ;
    // cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    cin >> t ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}