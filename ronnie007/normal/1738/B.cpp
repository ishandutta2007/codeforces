#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair < int , int > pii ;
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7 ;

int n , k ;
ll pref[ MAXN ] ;
ll a[ MAXN ] ;

void solve ( ) {
    cin >> n >> k ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        pref[ i ] = a[ i ] = 0 ;
    }
    for ( int i = n - k + 1 ; i <= n ; ++ i ) {
        cin >> pref[ i ] ;
    }
    if ( k == 1 ) {
        cout << "Yes\n" ;
        return ; 
    }
    for ( int i = n ; i > n - k + 1 ; -- i ) {
        a[ i ] = pref[ i ] - pref[ i - 1 ] ;
    }
    for ( int i = n ; i > n - k + 2 ; -- i ) {
        if ( a[ i ] < a[ i - 1 ] ) {
            cout << "No\n" ;
            return ;
        }
    }
    ll mx = a[ n - k + 2 ] ;
    if ( ( n - k + 1 ) * mx < pref[ n - k + 1 ] ) {
        cout << "No\n" ;
        return ;
    }
    cout << "Yes\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}