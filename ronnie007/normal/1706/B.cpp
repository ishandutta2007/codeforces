#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7 ;

int n ;
int a[ MAXN ] ;
int dp[ MAXN ][ 2 ] ;

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 0 ; j < 2 ; ++ j ) {
            dp[ i ][ j ] = 0 ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int wh = ( i % 2 ) ;
        dp[ a[ i ] ][ wh ] = max ( dp[ a[ i ] ][ wh ] , 1 + dp[ a[ i ] ][ wh ^ 1 ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << max ( dp[ i ][ 0 ] , dp[ i ][ 1 ] ) << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}