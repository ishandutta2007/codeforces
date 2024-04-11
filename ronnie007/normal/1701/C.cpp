#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 2e5 + 7 ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , m ;
int a[ MAXN ] ;
int lft[ MAXN ] ;


bool f ( int sr ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        lft[ i ] = sr ;
    }
    ll ch = 0 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( lft[ a[ i ] ] > 0 ) {
            -- lft[ a[ i ] ] ;
        }
        else { -- ch ; }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        ch += ( lft[ i ] / 2 ) ;
    }
    return ( ch >= 0 ) ;
}

void solve ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> a[ i ] ;
    }
    int l , r , mid ;
    l = 1 ; r = 2 * m ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( f ( mid ) == true ) { r = mid ; }
        else { l = mid ; }
    }
    while ( f ( l ) == false ) { ++ l ; }
    cout << l << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}