#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

map < vector < int > , bool > ban ;
map < vector < int > , bool > used ;

int n ;
vector < int > v[ 11 ] ;

struct el {
    int cost ;
    vector < int > aux ;
    el ( ) {
        cost = 0 ;
        aux.clear ( ) ;
    }
    bool operator < ( el other ) const {
        return cost < other.cost ;
    }
};


void input ( ) {
    cin >> n ;
    for ( int i = 0 ; i < n ; ++ i ) {
        int sz ; cin >> sz ;
        v[ i ].resize ( sz ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            cin >> v[ i ][ j ] ;
        }
    }
    int m ; cin >> m ;
    vector < int > aux ;
    aux.resize ( n ) ;
    for ( int i = 0 ; i < m ; ++ i ) {
        for ( int j = 0 ; j < n ; ++ j ) {
            cin >> aux[ j ] ;
            -- aux[ j ] ;
        }
        ban[ aux ] = true ;
    }
}

priority_queue < el > q ;

void solve ( ) {
    el init = el ( ) ;
    for ( int i = 0 ; i < n ; ++ i ) {
        init.aux.push_back ( (int)v[ i ].size ( ) - 1 ) ;
        init.cost += v[ i ].back ( ) ;
    }
    q.push ( init ) ;
    while ( q.empty ( ) == false ) {
        el x = q.top ( ) ;
        q.pop ( ) ;
        if ( ban[ x.aux ] == false ) {
            for ( int i = 0 ; i < n ; ++ i ) {
                cout << x.aux[ i ] + 1 << " " ; 
            }
            cout << "\n" ;
            return ;
        }
        for ( int i = 0 ; i < n ; ++ i ) {
            if ( x.aux[ i ] > 0 ) {
                x.cost -= v[ i ][ x.aux[ i ] ] ;
                -- x.aux[ i ] ;
                x.cost += v[ i ][ x.aux[ i ] ] ;

                if ( used[ x.aux ] == false ) { 
                    used[ x.aux ] = true ;
                    q.push ( x ) ;
                }

                x.cost -= v[ i ][ x.aux[ i ] ] ;
                ++ x.aux[ i ] ;
                x.cost += v[ i ][ x.aux[ i ] ] ;
            }
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}