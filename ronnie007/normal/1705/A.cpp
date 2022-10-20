#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MAXN = 3007 ;

int n , diff ;
int a[ MAXN ] ;

void solve ( ) {
    cin >> n >> diff ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        cin >> a[ i ] ;
    }
    sort ( a + 1 , a + 2 * n + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ n + i ] - a[ i ] < diff ) {
            cout << "NO\n" ;
            return ;
        }
    }
    cout << "YES\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}