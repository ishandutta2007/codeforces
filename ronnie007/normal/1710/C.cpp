#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

const int MOD = 998244353 ;
const int MAXN = 2e5 + 7 ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
string a ;
ll pw[ MAXN ] ;


ll dp[ MAXN ][ 8 ][ 8 ] ;

void solve ( ) {
    cin >> a ;
    int n = a.size ( ) ;
    dp[ 0 ][ 7 ][ 0 ] = 1 ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int mx = ( a[ i ] - '0' ) ;
        for ( int j = 0 ; j < 8 ; ++ j ) {
            for ( int t = 0 ; t < 8 ; ++ t ) {
                if ( dp[ i ][ j ][ t ] == 0 ) { continue ; }
                for ( int nx = 0 ; nx < 2 ; ++ nx ) {
                    if ( ( j & 4 ) > 0 && nx > mx ) { continue ; }
                    for ( int ny = 0 ; ny < 2 ; ++ ny ) {
                        if ( ( j & 2 ) > 0 && ny > mx ) { continue ; }
                        for ( int nz = 0 ; nz < 2 ; ++ nz ) {
                            if ( ( j & 1 ) > 0 && nz > mx ) { continue ; }

                            int nwmask = 0 ;
                            if ( ( j & 4 ) > 0 && nx == mx ) { nwmask += 4 ; }
                            if ( ( j & 2 ) > 0 && ny == mx ) { nwmask += 2 ; }
                            if ( ( j & 1 ) > 0 && nz == mx ) { nwmask += 1 ; }

                            int tot = ( nx ^ ny ^ nz ) ;
                            int nwt = 0 ;
                            // x , y 
                            if ( ( t & 4 ) > 0 ) { nwt += 4 ; }
                            else if ( ( tot ^ nx ) == 1 && ( tot ^ ny ) == 1 && ( tot ^ nz ) == 0 ) { nwt += 4 ; }

                            if ( ( t & 2 ) > 0 ) { nwt += 2 ; }
                            else if ( ( tot ^ nx ) == 1 && ( tot ^ ny ) == 0 && ( tot ^ nz ) == 1 ) { nwt += 2 ; }

                            if ( ( t & 1 ) > 0 ) { nwt += 1 ; }
                            else if ( ( tot ^ nx ) == 0 && ( tot ^ ny ) == 1 && ( tot ^ nz ) == 1 ) { nwt += 1 ; }

                            dp[ i + 1 ][ nwmask ][ nwt ] = ( dp[ i + 1 ][ nwmask ][ nwt ] + dp[ i ][ j ][ t ] ) % MOD ;
                        }
                    }
                }
            }
        }
    }
    ll ans = 0 ;
    for ( int i = 0 ; i < 8 ; ++ i ) {
        ans = ( ans + dp[ n ][ i ][ 7 ] ) % MOD ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}