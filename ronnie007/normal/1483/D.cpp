#include<bits/stdc++.h>
using namespace std ;

// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 602

long long inf = 1e15 ;

int n , m ;
struct edge {
    int x , y ;
    long long len ;
};
edge a[ MAXN * MAXN ] ;

bool fl[ MAXN * MAXN ] ;

long long dist[ MAXN ][ MAXN ] ;
vector < pair < int , long long > > qlist[ MAXN ] ;


long long mx[ MAXN ] ;

void calc ( int ori ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        mx[ i ] = -inf ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( auto [ to , cost ] : qlist[ ori ] ) {
            mx[ i ] = max ( mx[ i ] , cost - dist[ i ][ to ] ) ;
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( mx[ a[ i ].y ] >= a[ i ].len + dist[ ori ][ a[ i ].x ] ) {
            fl[ i ] = true ;
        }
        if ( mx[ a[ i ].x ] >= a[ i ].len + dist[ ori ][ a[ i ].y ] ) {
            fl[ i ] = true ;
        }
    }
}

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( i != j ) {
                dist[ i ][ j ] = inf ;
            }
            else { dist[ i ][ j ] = 0 ; }
        }
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> a[ i ].x >> a[ i ].y >> a[ i ].len ;
        dist[ a[ i ].x ][ a[ i ].y ] = dist[ a[ i ].y ][ a[ i ].x ] = min ( dist[ a[ i ].x ][ a[ i ].y ] , a[ i ].len ) ;
    }
    int p ; cin >> p ;
    for ( int i = 1 ; i <= p ; ++ i ) {
        int x , y ; long long len ;
        cin >> x >> y >> len ;
        qlist[ x ].push_back ( { y , len } ) ;
    }
}

void solve ( ) {
    for ( int k = 1 ; k <= n ; ++ k ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( int j = 1 ; j <= n ; ++ j ) {
                if ( dist[ i ][ j ] > dist[ i ][ k ] + dist[ k ][ j ] ) {
                    dist[ i ][ j ] = dist[ i ][ k ] + dist[ k ][ j ] ;
                }
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        calc ( i ) ;
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        ans += fl[ i ] ;
    }
    cout << ans << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}