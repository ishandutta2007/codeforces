#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair < int , int > pii ;
#define fi first
#define se second
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , m ;

void solve ( ) {
    cin >> n >> m ;
    if ( n > m ) { swap ( n , m ) ; }
    int ans = 2 * ( n - 1 ) + ( m - 1 ) ;
    if ( m >= 2 ) { ++ ans ; }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}