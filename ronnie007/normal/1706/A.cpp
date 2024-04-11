#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , m ;
bool a[ 107 ] ;

void solve ( ) {
    cin >> n >> m ;
    for ( int i = 0 ; i < m ; ++ i ) {
        a[ i ] = false ;
    }
    for ( int i = 1 , x ; i <= n ; ++ i ) {
        cin >> x ;
        if ( x > m - x + 1 ) { x = m - x + 1 ; }
        if ( a[ x - 1 ] == false ) { a[ x - 1 ] = true ; }
        else {
            a[ m - x ] = true ;
        }
    }
    for ( int i = 0 ; i < m ; ++ i ) {
        if ( a[ i ] == true ) { cout << "A" ; }
        else { cout << "B" ; }
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