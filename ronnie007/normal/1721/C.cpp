#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7 ;

int n ;
int a[ MAXN ] , b[ MAXN ] ;
int ans[ MAXN ] ;
multiset < int > s ;

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    s.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
        s.insert ( b[ i ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        auto it = s.lower_bound ( a[ i ] ) ;
        cout << (*it) - a[ i ] << " " ;
    }
    cout << "\n" ;
    for ( int i = n ; i >= 1 ; -- i ) {
        auto it = s.end ( ) ;
        -- it ;
        ans[ i ] = (*it) - a[ i ] ;
        it = s.lower_bound ( a[ i ] ) ;
        s.erase ( it ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ] << " " ;
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