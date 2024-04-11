#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 5e5 + 7 ;

int n ;
int b[ MAXN ] ;
pair < int , int > hh[ MAXN ] ;
vector < pair < int , int > > nw[ MAXN ] ;
int ans[ MAXN ] ;

priority_queue < pair < int , int > > q ;

void solve ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        nw[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> b[ i ] ;
        if ( b[ i ] == 0 ) {
            hh[ i ] = { i + 1 , n } ;
        }
        else {
            hh[ i ].second = i / b[ i ] ;
            hh[ i ].first = ( i / ( b[ i ] + 1 ) ) + 1 ;
        }
        nw[ hh[ i ].first ].push_back ( { hh[ i ].second , i } ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( auto [ en , id ] : nw[ i ] ) {
            q.push ( { -en , id } ) ;
        }
        auto [ tp , wh ] = q.top ( ) ;
        q.pop ( ) ;
        ans[ wh ] = i ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << ans[ i ] << " " ;
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