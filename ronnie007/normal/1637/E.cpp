#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007

int n , m ;
int a[ MAXN ] ;
pair < int , int > b[ MAXN ] ;

map < int , int > w ;
set < int > seen ;
set < int > s ;
vector < int > v ;

vector < int > aux[ MAXN ] ;

set < pair < int , int > > bad ;

void input ( ) {
    cin >> n >> m ;
    w.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        ++ w[ a[ i ] ] ;
        aux[ i ].clear ( ) ;
    }
    s.clear ( ) ; seen.clear ( ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        s.insert ( w[ a[ i ] ] ) ;
        if ( seen.find ( a[ i ] ) == seen.end ( ) ) {
            aux[ w[ a[ i ] ] ].push_back ( a[ i ] ) ;
            seen.insert ( a[ i ] ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        sort ( aux[ i ].begin ( ) , aux[ i ].end ( ) ) ;
    }
    v.clear ( ) ;
    for ( auto x : s ) {
        v.push_back ( x ) ;
    }
    bad.clear ( ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> b[ i ].first >> b[ i ].second ;
        bad.insert ( { b[ i ].first , b[ i ].second } ) ;
        bad.insert ( { b[ i ].second , b[ i ].first } ) ;
    }
}

void solve ( ) {
    int sz = v.size ( ) ;
    long long ans = 0 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        for ( auto x : aux[ v[ i ] ] ) {
            for ( int j = i ; j < sz ; ++ j ) {
                int lst = aux[ v[ j ] ].size ( ) - 1 ;
                while ( lst >= 0 ) {
                    if ( aux[ v[ j ] ][ lst ] != x && bad.find ( { x , aux[ v[ j ] ][ lst ] } ) == bad.end ( ) ) {
                        break ;
                    }
                    -- lst ;
                }
                if ( lst >= 0 ) {
                    long long sr = 1LL * ( x + aux[ v[ j ] ][ lst ] ) * ( v[ i ] + v[ j ] ) ;
                    ans = max ( ans , sr ) ;
                }
            }
        }
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    /// t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}