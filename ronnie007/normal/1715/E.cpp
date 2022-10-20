#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;


// https://github.com/kth-competitive-programming/kactl/blob/main/kactl.pdf

struct Line {
    mutable ll k , m , p ;
    bool operator < ( const Line& o ) const { return k > o.k ; }
    bool operator < ( ll x ) const { return p < x ; }
};
 
struct LineContainer : multiset < Line , less < > > {
    static const ll inf = LLONG_MAX ;
    ll div ( ll a , ll b ) {
        return a / b - ( ( a ^ b ) < 0 && a % b ) ;
    }
    bool isect ( iterator x , iterator y ) {
        if ( y == end ( ) ) { return x->p = inf , 0 ; }
        if ( x->k == y->k ) { x->p = x->m < y->m ? inf : -inf ; }
        else { x->p = div ( y->m - x->m , x->k - y->k ) ; }
        return x->p >= y->p ;
    }
    void add ( ll k , ll m ) {
        auto z = insert ( { k , m , 0 } ) , y = z ++ , x = y ;
        while ( isect ( y , z ) ) { z = erase ( z ) ; }
        if ( x != begin ( ) && isect ( -- x , y ) ) {
            isect ( x , y = erase ( y ) ) ;
        }
        while ( ( y = x ) != begin ( ) && ( -- x )->p >= y->p ) {
            isect ( x , erase ( y ) ) ;
        }
    }
    ll query ( ll x ) {
        assert ( !empty ( ) ) ;
        auto l = *lower_bound ( x ) ;
        return l.k * x + l.m ;
    }
};


const int MAXN = 1e5 + 7 ;
const ll inf = 1e17 ;

int n , m , k ;
ll dp[ 22 ][ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;


priority_queue < pair < ll , int > > q ;

void advance ( int lvl ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( dp[ lvl ][ i ] != inf ) {
            q.push ( { -dp[ lvl ][ i ] , i } ) ;
        }
    }
    while ( q.empty ( ) == false ) {
        auto [ cost , x ] = q.top ( ) ;
        q.pop ( ) ;
        cost = -cost ;
        if ( cost != dp[ lvl ][ x ] ) { continue ; }
        for ( auto [ y , c ] : v[ x ] ) {
            if ( dp[ lvl ][ y ] > dp[ lvl ][ x ] + c ) {
                dp[ lvl ][ y ] = dp[ lvl ][ x ] + c ;
                q.push ( { -dp[ lvl ][ y ] , y } ) ;
            }
        }
    }
}

void solve ( ) {
    cin >> n >> m >> k ;
    for ( int i = 1 , x , y , z ; i <= m ; ++ i ) {
        cin >> x >> y >> z ;
        v[ x ].push_back ( { y , z } ) ;
        v[ y ].push_back ( { x , z } ) ;
    }
    for ( int j = 0 ; j <= k ; ++ j ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            dp[ j ][ i ] = inf ;
        }
    }
    dp[ 0 ][ 1 ] = 0 ;
    advance ( 0 ) ;
    for ( int lvl = 1 ; lvl <= k ; ++ lvl ) {
        LineContainer w ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            w.add ( - 2 * i , 1LL * i * i + dp[ lvl - 1 ][ i ] ) ;
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            dp[ lvl ][ i ] = w.query ( i ) + 1LL * i * i ;
        }
        advance ( lvl ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        ll ans = inf ;
        for ( int lvl = 0 ; lvl <= k ; ++ lvl ) {
            ans = min ( ans , dp[ lvl ][ i ] ) ;
        }
        cout << ans << " " ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}