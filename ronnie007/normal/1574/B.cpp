#include<bits/stdc++.h>
using namespace std ;

int m , a[ 3 ] ;

void input ( ) {
    cin >> a[ 0 ] >> a[ 1 ] >> a[ 2 ] >> m ;
    sort ( a , a + 3 ) ;
}

void solve ( ) {
    int n = a[ 0 ] + a[ 1 ] + a[ 2 ] ;
    int mx = 0 ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        mx += max ( a[ i ] - 1 , 0 ) ;
    }
    if ( mx < m ) {
        cout << "NO\n" ;
        return ;
    }
    int mn = a[ 2 ] - ( a[ 0 ] + a[ 1 ] ) - 1 ;
    if ( mn > m ) {
        cout << "NO\n" ;
        return ;
    }
    cout << "YES\n" ;
}

int main ( ) {
    //freopen ( "dictionary.in" , "r" , stdin ) ;
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}