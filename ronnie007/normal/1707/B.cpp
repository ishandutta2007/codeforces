#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int MAXN = 5e5 + 7 ;

int n ;
int a[ MAXN ] ;
int cnt[ MAXN ] ;

vector < pair < int , int > > v[ 2 ] ;
vector < int > aux ;

void solve ( ) {
    cin >> n ;
    v[ 0 ].clear ( ) , v[ 1 ].clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ cnt[ a[ i ] ] ;
    }
    int prv = 0 , nxt = 1 ; 
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( i == 1 || a[ i ] != a[ i - 1 ] ) {
            v[ prv ].push_back ( { a[ i ] , cnt[ a[ i ] ] } ) ;
        }
    }

    for ( int i = 1 ; i < n ; ++ i ) {
        int sz = v[ prv ].size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            cnt[ 0 ] += ( v[ prv ][ i ].second - 1 ) ;
        }
        aux.clear ( ) ;
        for ( int i = 1 ; i < sz ; ++ i ) {
            ++ cnt[ v[ prv ][ i ].first - v[ prv ][ i - 1 ].first ] ;
            aux.push_back ( v[ prv ][ i ].first - v[ prv ][ i - 1 ].first ) ;
        }
        for ( int i = 0 ; i < sz ; ++ i ) {
            cnt[ v[ prv ][ i ].first ] -= v[ prv ][ i ].second ;
        }
        if ( cnt[ 0 ] > 0 ) {
            v[ nxt ].push_back ( { 0 , cnt[ 0 ] } ) ;
        }
        sort ( aux.begin ( ) , aux.end ( ) ) ;
        sz = aux.size ( ) ;
        for ( int i = 0 ; i < sz ; ++ i ) {
            if ( i == 0 || aux[ i ] != aux[ i - 1 ] ) {
                v[ nxt ].push_back ( { aux[ i ] , cnt[ aux[ i ] ] } ) ;
            }
        }
        v[ prv ].clear ( ) ;
        prv ^= 1 , nxt ^= 1 ;
    }
    -- cnt[ v[ prv ][ 0 ].first ] ;
    cout << v[ prv ][ 0 ].first << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}