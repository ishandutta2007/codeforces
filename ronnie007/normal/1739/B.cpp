#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef unsigned long long ull ;
typedef pair < int , int > pii ;
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 107 ;

int n ;
ll a[ MAXN ] ;

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
    ll x = a[ 1 ] ;
    for ( int i = 2 ; i <= n ; ++ i ) {
        if ( a[ i ] == 0 ) { continue ; }
        if ( x - a[ i ] >= 0 ) {
            cout << "-1\n" ;
            return ;
        }
        x += a[ i ] ;
    }
    x = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        x += a[ i ] ;
        cout << x << " " ;
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