#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1000007

int n , m , k ;
int col[ MAXN ] ;
bool fl[ MAXN ] ;

map < pair < int , int > , vector < pair < int , int > > > w ;

namespace DSU {
    int prv[ MAXN ] ;
    int rnk[ MAXN ] ;
    int lim ;
    struct tuhla {
        int x1 , x2 ;
        int prv1 , rnk1 ;
        int prv2 , rnk2 ;
        tuhla ( int _x1 , int _x2 ) {
            x1 = _x1 ; x2 = _x2 ;
            prv1 = prv[ x1 ] ; rnk1 = rnk[ x1 ] ;
            prv2 = prv[ x2 ] ; rnk2 = rnk[ x2 ] ;
        }
    };
    stack < tuhla > s ;
    void init ( int _lim ) {
        lim = _lim ;
        for ( int i = 1 ; i <= 2 * lim ; ++ i ) {
            prv[ i ] = -1 ;
            rnk[ i ] = 0 ;
        }
    }
    int find ( int x ) {
        while ( prv[ x ] != -1 ) { x = prv[ x ] ; }
        return x ;
    }
    bool unite ( int x , int y ) {
        int k1 = find ( x ) ;
        int k2 = find ( y ) ;
        if ( k1 == k2 ) { return false ; }
        s.push ( tuhla ( k1 , k2 ) ) ;
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
        return true ;
    }
    void undo ( ) {
        tuhla aux = s.top ( ) ;
        s.pop ( ) ;
        prv[ aux.x1 ] = aux.prv1 ;
        rnk[ aux.x1 ] = aux.rnk1 ;

        prv[ aux.x2 ] = aux.prv2 ;
        rnk[ aux.x2 ] = aux.rnk2 ;
    }
    pair < bool , int > f ( int x , int y ) {
        if ( find ( x ) == find ( y ) ) {
            return { false , 0 } ;
        }
        int ret = 0 ;
        ret += unite ( x , y + lim ) ;
        ret += unite ( x + lim , y ) ;
        return { true , ret } ;
    }
};

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &col[ i ] ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        if ( col[ x ] > col[ y ] ) { swap ( x , y ) ; }
        w[ { col[ x ] , col[ y ] } ].push_back ( { x , y } ) ;
    }
}

void solve ( ) {
    DSU :: init ( n ) ;
    long long ans = 1LL * k * ( k - 1 ) / 2 ;
    int lft = k ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        for ( auto e : w[ { i , i } ] ) {
            auto ret = DSU :: f ( e.first , e.second ) ;
            if ( ret.first == false ) {
                ans -= -- lft ;
                fl[ i ] = true ;
                break ;
            }
        }
    }
    for ( auto data : w ) {
        auto hh = data.first ;
        if ( hh.first == hh.second ) { continue ; }
        if ( fl[ hh.first ] == true || fl[ hh.second ] == true ) { continue ; }
        int cnt = 0 ;
        for ( auto e : w[ hh ] ) {
            auto ret = DSU :: f ( e.first , e.second ) ;
            if ( ret.first == false ) {
                -- ans ;
                break ;
            }
            else { cnt += ret.second ; }
        }
        while ( cnt > 0 ) {
            -- cnt ;
            DSU :: undo ( ) ;
        }
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}