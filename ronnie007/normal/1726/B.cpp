#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7 ;

int n , sm ;
int a[ MAXN ] ;

void solve ( ) {
    cin >> n >> sm ;
    if ( n > sm ) {
        cout << "No\n" ;
        return ;
    }
    if ( n == 1 ) {
        cout << "Yes\n" ;
        cout << sm << "\n" ;
        return ;
    }
    if ( n == 2 ) {
        if ( ( sm % 2 ) == 0 ) {
            cout << "Yes\n" ;
            cout << sm / 2 << " " << sm / 2 << "\n" ;
        }
        else {
            cout << "No\n" ;
        }
        return ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = 1 ;
    }
    sm -= n ;
    if ( ( n % 2 ) == 1 ) {
        int hh = ( sm / 3 ) ;
        a[ n ] += hh , a[ n - 1 ] += hh , a[ n - 2 ] += hh ;
        int rem = sm - 3 * hh ;
        a[ n ] += rem ;
    }
    else {
        if ( ( sm % 2 ) == 1 ) {
            cout << "No\n" ;
            return ;
        }
        int hh = sm / 2 ;
        a[ n ] += hh , a[ n - 1 ] += hh ;
    }
    cout << "Yes\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << a[ i ] << " " ;
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