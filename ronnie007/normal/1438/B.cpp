#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    set < int > s ;
    s.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( s.find ( a[ i ] ) != s.end ( ) ) { cout << "YES\n" ; return ; }
        s.insert ( a[ i ] ) ;
    }
    cout << "NO\n" ;
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