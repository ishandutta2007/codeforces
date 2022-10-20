#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n[ 3 ] ;
int a[ 3 ][ MAXN ] ;

long long tot[ 3 ] ;

void input ( ) {
    for ( int i = 0 ; i < 3 ; ++ i ) {
        cin >> n[ i ] ;
    }
    for ( int i = 0 ; i < 3 ; ++ i ) {
        for ( int j = 0 ; j < n[ i ] ; ++ j ) {
            cin >> a[ i ][ j ] ;
            tot[ i ] += a[ i ][ j ] ;
        }
        sort ( a[ i ] , a[ i ] + n[ i ] ) ;
    }
}

void solve ( ) {
    long long ans = 0 ;
    long long aux = tot[ 0 ] + tot[ 1 ] + tot[ 2 ] ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        ans = max ( ans , aux - tot[ i ] * 2 ) ;
    }
    for ( int i = 0 ; i < 3 ; ++ i ) {
        for ( int j = i + 1 ; j < 3 ; ++ j ) {
            ans = max ( ans , aux - a[ i ][ 0 ] * 2 - a[ j ][ 0 ] * 2 ) ;
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}