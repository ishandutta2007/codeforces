#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair < int , int > pii ;
#define fi first
#define se second
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 1e5 + 7 ;

ll n , k , cnt , sm ;
ll ans[ MAXN ] ;

void solve ( ) {
    cin >> n >> k >> cnt >> sm ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        ans[ i ] = 0 ;
    }
    ans[ 1 ] = k * cnt ;
    if ( ans[ 1 ] > sm ) {
        cout << "-1\n" ;
        return ;
    }
    sm -= ans[ 1 ] ;
    ll mx = k - 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( sm >= mx ) {
            ans[ i ] += mx ;
            sm -= mx ;
        }
        else {
            ans[ i ] += sm ;
            sm = 0 ;
        }
    }
    if ( sm > 0 ) {
        cout << "-1\n" ;
        return ;
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