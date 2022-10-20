#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

int n , m ;
int a[ MAXN ] ;
int b[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    cin >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> b[ i ] ;
    }
}

void solve ( ) {
    int ans = 0 ;
    int aux1 = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        aux1 += a[ i ] ;
        int aux2 = 0 ;
        for ( int j = 0 ; j <= m ; ++ j ) {
            aux2 += b[ j ] ;
            ans = max ( ans , aux1 + aux2 ) ;
        }
    }
    cout << ans << "\n" ;
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