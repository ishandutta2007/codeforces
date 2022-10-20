#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 2e5 + 7 ;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;
bool used[ MAXN ] ;

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        used[ i ] = false ;
    }
    cout << "2\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) {
            int x = i ;
            while ( x <= n ) {
                cout << x << " " ;
                used[ x ] = true ;
                x *= 2 ;
            }
        }
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