#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 1007

int n , d ;
pair < int , int > a[ MAXN ] ;

class dsu {
public :
    int prv[ MAXN ] ;
    int rnk[ MAXN ] ;
    int sz[ MAXN ] ;
    void init ( int n ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            prv[ i ] = -1 ;
            sz[ i ] = 1 ;
            rnk[ i ] = 0 ;
        }
    }
    
    int get ( int x ) {
        if ( prv[ x ] == -1 ) { return x ; }
        int y = get ( prv[ x ] ) ;
        prv[ x ] = y ;
        return y ;
    }
    
    bool unite ( int x , int y ) {
        int k1 = get ( x ) ;
        int k2 = get ( y ) ;
        if ( k1 != k2 ) {
            if ( rnk[ k1 ] >= rnk[ k2 ] ) {
                rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
                sz[ k1 ] += sz[ k2 ] ;
                prv[ k2 ] = k1 ;
            }
            else {
                sz[ k2 ] += sz[ k1 ] ;
                prv[ k1 ] = k2 ;
            }
            return true ;
        }
        return false ;
    }
};

dsu w ;



void input ( ) {
    cin >> n >> d ;
    for ( int i = 1 ; i <= d ; ++ i ) {
        cin >> a[ i ].first >> a[ i ].second ;
    }
}   

void solve ( ) {
    for ( int i = 1 ; i <= d ; ++ i ) {
        w.init ( n ) ;
        int hh = i + 1 ;
        for ( int j = 1 ; j <= i ; ++ j ) {
            hh -= w.unite ( a[ j ].first , a[ j ].second ) ;
        }
        multiset < int > s ;
        for ( int j = 1 ; j <= n ; ++ j ) {
            if ( w.prv[ j ] == -1 ) {
                s.insert ( w.sz[ j ] ) ;
            }
        }
        int ans = 0 ;
        for ( auto it = s.rbegin ( ) ; it != s.rend ( ) ; ++ it ) {
            -- hh ;
            ans += (*it) ;
            if ( hh == 0 ) { break ; }
        }
        -- ans ;
        cout << ans << "\n" ;
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