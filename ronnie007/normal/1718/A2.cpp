#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef unsigned long long ull ;
#define fi first
#define se second
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 1e5 + 7 ;

int n ;
int a[ MAXN ] ;
int dp[ MAXN ] ;
map < int , int > w ;

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    w.clear ( ) ;
    w[ 0 ] = dp[ 0 ] = 1 ;
    int hh = 0 ;
    int ret = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ i ] = 0 ;
        hh ^= a[ i ] ;
        if ( w[ hh ] > 0 ) {
            dp[ i ] = w[ hh ] + 1 ;
        }
        dp[ i ] = max ( dp[ i ] , dp[ i - 1 ] ) ;
        w[ hh ] = dp[ i ] ;
    }
    -- dp[ n ] ;
    cout << n - dp[ n ] << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}