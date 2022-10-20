#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

int n , c , q ;
string s ;
pair < ll , ll > a[ 42 ] ;

void solve ( ) {
    cin >> n >> c >> q ;
    cin >> s ;
    for ( int i = 1 ; i <= c ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
    }
    while ( q -- ) {
        ll wh ; cin >> wh ;
        while ( wh > n ) {
            ll aux = n ;
            for ( int i = 1 ; i <= c ; ++ i ) {
                ll len = a[ i ].second - a[ i ].first + 1 ;
                if ( aux + len >= wh ) {
                    ll act = wh - aux - 1 + a[ i ].first ;
                    wh = act ;
                    break ;
                }
                else { aux += len ; }
            }
        }
        cout << s[ wh - 1 ] << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}