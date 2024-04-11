#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 2007
#define MOD 1000000007

int n , k , L ;
struct point {
    int x , y , c ;
};
point a[ MAXN ] ;
int revx[ MAXN ] ;
int revy[ MAXN ] ;

vector < int > v[ MAXN ] ;
vector < int > cols[ MAXN ] ;

int nxt[ MAXN ] ;
int prv[ MAXN ] ;


int MAX_X , MAX_Y ;

void input ( ) {
    cin >> n >> k >> L ;
    set < int > srtx , srty ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ].x >> a[ i ].y >> a[ i ].c ;
        srtx.insert ( a[ i ].x ) ;
        srty.insert ( a[ i ].y ) ;
    }
    map < int , int > aux ;
    for ( auto x : srtx ) {
        aux[ x ] = ++ MAX_X ;
        revx[ MAX_X ] = x ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ].x = aux[ a[ i ].x ] ;
    }
    aux.clear ( ) ;
    for ( auto y : srty ) {
        aux[ y ] = ++ MAX_Y ;
        revy[ MAX_Y ] = y ;
    }    
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ].y = aux[ a[ i ].y ] ;
    }
    auto cmp = [ & ] ( point p1 , point p2 ) {
        return ( p1.y < p2.y ) ;
    };
    sort ( a + 1 , a + n + 1 , cmp ) ;

    for ( int i = 1 ; i <= n ; ++ i ) {
        v[ a[ i ].y ].push_back ( i ) ;
        cols[ a[ i ].x ].push_back ( i ) ;
    }

    revx[ MAX_X + 1 ] = revy[ MAX_Y + 1 ] = L ;
    revx[ 0 ] = revy[ 0 ] = -1 ;
}

map < int , int > aux[ MAXN ] ;
int col_cnt[ MAXN ] ;

int init_vals[ MAXN ] ;

class Tree {
public :
    long long tr[ 4 * MAXN ] ;
    int mx[ 4 * MAXN ] ;
    int mn[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void unite_root ( int where ) {
        tr[ where ] = ( tr[ 2 * where ] + tr[ 2 * where + 1 ] ) % MOD ;
        mx[ where ] = max ( mx[ 2 * where ] , mx[ 2 * where + 1 ] ) ;
        mn[ where ] = min ( mn[ 2 * where ] , mn[ 2 * where + 1 ] ) ;
    }
    
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = -1 ;
        if ( IL == IR ) {
            tr[ where ] = L - revx[ init_vals[ IL ] ] ;
            tr[ where ] = ( tr[ where ] * ( revx[ IR ] - revx[ IL - 1 ] ) ) % MOD ;
            mn[ where ] = mx[ where ] = revx[ init_vals[ IL ] ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite_root ( where ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] != -1 ) {
            tr[ where ] = ( 1LL * ( revx[ IR ] - revx[ IL - 1 ] ) * ( L - lazy[ where ] ) ) % MOD ;
            mn[ where ] = mx[ where ] = lazy[ where ] ;
            if ( IL != IR ) {
                lazy[ 2 * where ] = lazy[ where ] ;
                lazy[ 2 * where + 1 ] = lazy[ where ] ;
            }
            lazy[ where ] = -1 ;
        }
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int sr ) {
        push_lazy ( where , IL , IR ) ;
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( mn[ where ] >= sr ) { return ; }
        if ( CURL <= IL && IR <= CURR && mx[ where ] <= sr ) {
            lazy[ where ] = sr ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , sr ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , sr ) ;
        unite_root ( where ) ;
    }
    long long query ( ) { return tr[ 1 ] ; }
};

Tree w ;


void solve ( ) {
    long long ans = 0 ;
    for ( int down = 1 ; down <= MAX_Y ; ++ down ) {
        for ( int i = 1 ; i <= k ; ++ i ) {
            aux[ i ].clear ( ) ;
            col_cnt[ i ] = 0 ;
        }
        int aux_pos = 1 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            while ( a[ aux_pos ].y < a[ i ].y ) {
                if ( a[ aux_pos ].y >= down ) {
                    aux[ a[ aux_pos ].c ][ a[ aux_pos ].x ] = aux_pos ;
                }
                ++ aux_pos ;
            }
            if ( a[ i ].y < down ) { continue ; }
            auto it = aux[ a[ i ].c ].lower_bound ( a[ i ].x ) ;
            if ( it == aux[ a[ i ].c ].end ( ) ) {
                nxt[ i ] = -1 ;
            }
            else {
                nxt[ i ] = it->second ;
            }
            it = aux[ a[ i ].c ].upper_bound ( a[ i ].x ) ;
            if ( it == aux[ a[ i ].c ].begin ( ) ) {
                prv[ i ] = -1 ;
            }
            else {
                -- it ;
                prv[ i ] = it->second ;
            }
        }
        int en = 0 ;
        int act = 0 ;
        for ( int i = 1 ; i <= MAX_X ; ++ i ) {
            while ( en < MAX_X && act < k ) {
                ++ en ;
                for ( auto pos : cols[ en ] ) {
                    if ( a[ pos ].y >= down ) {
                        ++ col_cnt[ a[ pos ].c ] ;
                        if ( col_cnt[ a[ pos ].c ] == 1 ) { ++ act ; }
                    }
                }
            }
            if ( act == k ) { init_vals[ i ] = en ; }
            else { init_vals[ i ] = MAX_X + 1 ; }
            for ( auto pos : cols[ i ] ) {
                if ( a[ pos ].y >= down ) {
                    -- col_cnt[ a[ pos ].c ] ;
                    if ( col_cnt[ a[ pos ].c ] == 0 ) { -- act ; }
                }
            }
        }
        w.init ( 1 , 1 , MAX_X ) ;
        for ( int up = MAX_Y ; up >= down ; -- up ) {
            long long aux = w.query ( ) ;
            aux = ( aux * ( ( 1LL * ( revy[ up + 1 ] - revy[ up ] ) * ( revy[ down ] - revy[ down - 1 ] ) ) % MOD ) ) % MOD ;
            ans = ( ans + aux ) % MOD ;
            for ( auto i : v[ up ] ) {
                int st , en , nwval ;
                en = a[ i ].x ;
                if ( prv[ i ] == -1 ) {
                    st = 1 ;
                }
                else {
                    st = a[ prv[ i ] ].x + 1 ;
                }

                if ( nxt[ i ] == -1 ) {
                    nwval = L ;
                }
                else {
                    nwval = revx[ a[ nxt[ i ] ].x ] ;
                }
                w.update ( 1 , 1 , MAX_X , st , en , nwval ) ;
            }
        }
    }
    cout << ans << "\n" ;
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