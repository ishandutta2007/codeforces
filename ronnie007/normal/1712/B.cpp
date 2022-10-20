#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;

void solve ( ) {
    cin >> n ;
    if ( ( n % 2 ) == 1 ) {
        cout << "1 " ;
        for ( int i = 2 ; i < n ; i += 2 ) {
            cout << i + 1 << " " << i << " " ;
        }
        cout << "\n" ;
    }
    else {
        for ( int i = 1 ; i < n ; i += 2 ) {
            cout << i + 1 << " " << i << " " ;
        }
        cout << "\n" ;        
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}