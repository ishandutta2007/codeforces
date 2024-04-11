#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 2e5 + 7 ; 
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n ;
int a[ MAXN ] ;

void solve ( ) {
    cin >> n ;
    ll ans = 0 ;
    int fst = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        if ( i < n ) { 
            ans += a[ i ] ;
        }
        if ( a[ i ] > 0 && fst < 0 ) { fst = i ; }
    }
    if ( fst > 0 ) {
        for ( int j = fst + 1 ; j < n ; ++ j ) {
            ans += ( a[ j ] == 0 ) ;
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}