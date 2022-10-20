#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 600007

int n , m ;
vector < pair < int , int > > v[ MAXN ] ;

struct interval {
    int pos , l , r ;
};
interval rem[ MAXN ] ;
set < int > s ;
map < int , int > rv ;

int mxval ;
int lst[ MAXN ] ;
bool used[ MAXN ] ;

class Tree {
public :
    pair < int , int > tr[ 4 * MAXN ] ;
    pair < int , int > lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        if ( tr[ where ].first < lazy[ where ].first ) {
            tr[ where ] = lazy[ where ] ;
        }
        if ( IL != IR ) {
            if ( lazy[ 2 * where ].first < lazy[ where ].first ) {
                lazy[ 2 * where ] = lazy[ where ] ;
            }
            if ( lazy[ 2 * where + 1 ].first < lazy[ where ].first ) {
                lazy[ 2 * where + 1 ] = lazy[ where ] ;
            }            
        }
        lazy[ where ] = { 0 , 0 } ;
    }
    
    void init ( int where , int IL , int IR ) {
        tr[ where ] = lazy[ where ] = { 0 , 0 } ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int nw , int id ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] = { nw , id } ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , nw , id ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , nw , id ) ;
        if ( tr[ 2 * where ].first > tr[ 2 * where + 1 ].first ) {
            tr[ where ] = tr[ 2 * where ] ;
        }
        else {
            tr[ where ] = tr[ 2 * where + 1 ] ; 
        }
    }
    pair < int , int > query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return { 0 , 0 } ; }
        if ( IR < CURL || CURR < IL ) { return { 0 , 0 } ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        pair < int , int > ret1 = query ( 2 * where , IL , mid , CURL , CURR ) ;
        pair < int , int > ret2 = query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        if ( ret1.first < ret2.first ) { return ret2 ; }
        return ret1 ;
    }
};
Tree w ;

void input ( ) {
    cin >> n >> m ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        cin >> rem[ i ].pos >> rem[ i ].l >> rem[ i ].r ;
        s.insert ( rem[ i ].l ) ;
        s.insert ( rem[ i ].r ) ;
    }
    for ( auto it : s ) {
        rv[ it ] = ++ mxval ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        rem[ i ].l = rv[ rem[ i ].l ] ;
        rem[ i ].r = rv[ rem[ i ].r ] ;
        v[ rem[ i ].pos ].push_back ( { rem[ i ].l , rem[ i ].r } ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , mxval ) ;
    int ans = 0 ;
    int st = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int hh = 0 ;
        int pos = 0 ;
        for ( auto [ l , r ] : v[ i ] ) {
            pair < int , int > ret = w.query ( 1 , 1 , mxval , l , r ) ;
            if ( hh < ret.first ) {
                hh = ret.first ;
                pos = ret.second ;
            }
        }
        lst[ i ] = pos ;
        ++ hh ;
        if ( ans < hh ) {
            ans = hh ;
            st = i ;
        }
        for ( auto [ l , r ] : v[ i ] ) {
            w.update ( 1 , 1 , mxval , l , r , hh , i ) ;
        }
    }
    while ( st > 0 ) {
        used[ st ] = true ;
        st = lst[ st ] ;
    }
    cout << n - ans << "\n" ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( used[ i ] == false ) {
            cout << i << " " ;
        }
    }
    cout << "\n" ;
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