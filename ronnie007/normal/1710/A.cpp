#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef unsigned long long ull ;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7 ;

ll n , m , k ;
ll a[ MAXN ] ;

void solve ( ) {
    cin >> n >> m >> k ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        cin >> a[ i ] ;
    }
    for ( int cnt = 0 ; cnt < 2 ; ++ cnt ) {
        ll sm = 0 ;
        ll mx = 0 ;
        for ( int i = 1 ; i <= k ; ++ i ) {
            ll aux = ( a[ i ] / n ) ;
            if ( aux >= 2 ) { sm += aux ; }
            mx = max ( mx , aux ) ;
        }
        if ( sm >= m ) {
            if ( mx == 2 && ( m % 2 ) == 1 ) {
                swap ( n , m ) ;
                continue ;
            }
            cout << "Yes\n" ;
            return ;
        }
        swap ( n , m ) ;
    }
    cout << "No\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}