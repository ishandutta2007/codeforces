#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
const int MAXN = 1e5 + 7 ; 

int n ;
int a[ MAXN ] ;
ll dp[ MAXN ][ 2 ] ;

int eval ( int x ) {
    int ret = max ( a[ x - 1 ] - a[ x ] + 1 , a[ x + 1 ] - a[ x ] + 1 ) ;
    ret = max ( ret , 0 ) ;
    return ret ;
}

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    if ( ( n % 2 ) == 1 ) {
        ll ans = 0 ;
        for ( int i = 2 ; i < n ; i += 2 ) {
            ans += eval ( i ) ;
        }
        cout << ans << "\n" ;
        return ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        dp[ i ][ 0 ] = dp[ i ][ 1 ] = 1e15 ; 
    }
    dp[ 0 ][ 0 ] = 0 ;
    for ( int i = 2 ; i < n ; ++ i ) {
        int mx = ( i - 1 ) / 2 ;
        int add = eval ( i ) ;
        for ( int j = mx ; j >= mx - 5 ; -- j ) {
            if ( j < 0 ) { continue ; }
            for ( int t = 0 ; t < 2 ; ++ t ) {
                for ( int z = 1 ; z >= 0 ; -- z ) {
                    if ( t == 1 && z == 1 ) { continue ; }
                    dp[ j + z ][ z ] = min ( dp[ j + z ][ z ] , dp[ j ][ t ] + ( add * ( z == 1 ) ) ) ;
                }
            }
        }
    }
    cout << min ( dp[ ( n - 2 ) / 2 ][ 0 ] , dp[ ( n - 2 ) / 2 ][ 1 ] ) << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}