#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 5e6 + 7 ;

int n , m ;
int f[ MAXN ] ;
int dp[ MAXN ] , cnt[ MAXN ] ;

void solve ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m + 1 ; ++ i ) {
        f[ i ] = false ;
        cnt[ i ] = 0 , dp[ i ] = m + 1 ; 
    }
    for ( int i = 1 , x ; i <= n ; ++ i ) {
        cin >> x ;
        ++ f[ x ] ;
    }
    int r = m + 1 ;
    cnt[ m + 1 ] = n ;
    int ans = MAXN ;
    for ( int l = m ; l >= 1 ; -- l ) {
        cnt[ dp[ l ] ] -= f[ l ] ;
        dp[ l ] = l ;
        cnt[ dp[ l ] ] += f[ l ] ;
        for ( ll x = 1LL * l * l ; x <= m ; x += l ) {
            cnt[ dp[ x ] ] -= f[ x ] ;
            dp[ x ] = min ( dp[ x ] , dp[ x / l ] ) ;
            cnt[ dp[ x ] ] += f[ x ] ;
        }
        while ( cnt[ r ] == 0 ) { -- r ; }
        if ( r <= m ) { ans = min ( ans , r - l ) ; }
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