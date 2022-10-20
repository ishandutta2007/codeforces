#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair < int , int > pii ;
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 3007 ;

int n ;
int a[ MAXN ] ;

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    int ans = a[ n ] - a[ 1 ] ;
    for ( int i = 1 ; i < n ; ++ i ) {
        ans = max ( ans , a[ n ] - a[ i ] ) ;
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        ans = max ( ans , a[ i ] - a[ 1 ] ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        ans = max ( ans , a[ i ] - a[ i + 1 ] ) ;
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