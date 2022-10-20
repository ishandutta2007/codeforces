#include<bits/stdc++.h>
using namespace std ;

#define MAXN 107

int n , d ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n >> d ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    sort ( a + 1 , a + n + 1 ) ;
    if ( a[ n ] <= d ) {
        cout << "YES\n" ;
        return ;
    }
    if ( a[ 1 ] + a[ 2 ] <= d ) {
        cout << "YES\n" ;
        return ;
    }
    cout << "NO\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
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