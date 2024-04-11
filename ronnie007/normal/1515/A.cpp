#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 107

int n , sr ;
int a[ MAXN ] ;

void input ( ) {
    cin >> n >> sr ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}

void solve ( ) {
    int sm = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        sm += a[ i ] ;
    }
    if ( sm == sr ) {
        cout << "NO\n" ;
        return ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    int aux = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        aux += a[ i ] ;
        if ( aux == sr ) {
            swap ( a[ i ] , a[ n ] ) ;
            break ;
        }
    }
    cout << "YES\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << a[ i ] << " " ;
    }
    cout << "\n" ;
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