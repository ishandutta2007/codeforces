#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair < int , int > pii ;
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7 ;

int n ;
pair < int , ll > a[ MAXN ] ;
vector < ll > v[ 2 ] ;


void solve ( ) {
    cin >> n ;
    v[ 0 ].clear ( ) ; v[ 1 ].clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].fi ;
    }
    ll ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].se ;
        ans += a[ i ].se ;
        v[ a[ i ].fi ].emplace_back ( a[ i ].se ) ;
    }
    int aux = min ( (int)v[ 0 ].size ( ) , (int)v[ 1 ].size ( ) ) ;
    sort ( v[ 0 ].begin ( ) , v[ 0 ].end ( ) , greater < ll > ( ) ) ;
    sort ( v[ 1 ].begin ( ) , v[ 1 ].end ( ) , greater < ll > ( ) ) ;
    if ( 2 * aux == n ) {
        ans += max ( v[ 0 ].back ( ) , v[ 1 ].back ( ) ) ;
        -- aux ;
    }
    for ( int i = 0 ; i < aux ; ++ i ) {
        ans += v[ 0 ][ i ] ;
        ans += v[ 1 ][ i ] ;
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