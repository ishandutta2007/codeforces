#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair < int , int > pii ;
#define fi first
#define se second
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 2e5 + 7 ;

int n ;
int b[ MAXN ] ;
int a[ MAXN ] ;

vector < int > v[ MAXN ] ;

priority_queue < pii > q[ 2 ] ;

void solve ( ) {
    cin >> n ;
    for ( int i = 0 ; i <= n + 1 ; ++ i ) {
        v[ i ].clear ( ) ;
    }
    for ( int id = 0 ; id < 2 ; ++ id ) { 
        while ( q[ id ].empty ( ) == false ) {
            q[ id ].pop ( ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
        v[ b[ i ] ].emplace_back ( i ) ;
    }
    if ( v[ 0 ].empty ( ) == false ) {
        for ( auto x : v[ 0 ] ) {
            q[ 1 ].push ( { -v[ x ].size ( ) , x } ) ;
        }
    }
    if ( v[ n + 1 ].empty ( ) == false ) {
        for ( auto x : v[ n + 1 ] ) {
            q[ 0 ].push ( { -v[ x ].size ( ) , x } ) ;
        }
    }
    int tp = 0 , k = 0 ;
    while ( tp < n ) {
        int id = 0 ;
        if ( q[ 1 ].empty ( ) == false ) { id = 1 ; }
        while ( q[ id ].empty ( ) == false ) {
            auto [ foo , x ] = q[ id ].top ( ) ;
            q[ id ].pop ( ) ;
            a[ ++ tp ] = x ;
            if ( id == 0 ) { ++ k ; }
            if ( v[ x ].empty ( ) == false ) {
                for ( auto y : v[ x ] ) {
                    q[ id ^ 1 ].push ( { -v[ y ].size ( ) , y } ) ;
                }
            }
        }
    }
    cout << k << "\n" ;
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