#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#define MAXN 300007
#define LOG 20

int n , q ;
int a[ MAXN ] ;
int code[ MAXN ] ;
vector < int > v[ MAXN ] ;

struct query {
    int x , y ;
    int lca ;
    int l , r ;
    int mid ;
};
query qlist[ MAXN ] ;

int ans[ MAXN ] ;

int lvl[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;
int tpsz ;
int st[ MAXN ] ;
int en[ MAXN ] ;
int ret[ MAXN ] ;
vector < int > val_list[ MAXN ] ;

int pre_xor[ MAXN ] ;


void dfs ( int vertex , int prv ) {
    st[ vertex ] = ++ tpsz ;
    for ( int i = 1 ; i < LOG ; ++ i ) {
        LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        lvl[ x ] = lvl[ vertex ] + 1 ;
        LCA[ x ][ 0 ] = vertex ;
        dfs ( x , vertex ) ;
    }
    en[ vertex ] = tpsz ;
}

int get_LCA ( int x , int y ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( lvl[ x ] - ( 1 << i ) >= lvl[ y ] ) {
            x = LCA[ x ][ i ] ;
        }
        if ( lvl[ y ] - ( 1 << i ) >= lvl[ x ] ) {
            y = LCA[ y ][ i ] ;
        }
    }
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( LCA[ x ][ i ] != LCA[ y ][ i ] ) {
            x = LCA[ x ][ i ] ;
            y = LCA[ y ][ i ] ;
        }
    }
    if ( x != y ) { x = LCA[ x ][ 0 ] ; }
    return x ;
}


class Tree {
public :
    int tr[ MAXN ] ;
    void init ( ) {
        for ( int i = 0 ; i <= n ; ++ i ) { tr[ i ] = 0 ; }
    }
    void update ( int where , long long val ) {
        for ( ; where <= n ; where += ( where & -where ) ) {
            tr[ where ] ^= val ;
        }
    }
    int query ( int where ) {
        long long ans = 0 ;
        for ( ; where >= 1 ; where -= ( where & -where ) ) {
            ans ^= tr[ where ] ;
        }
        return ans ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        val_list[ a[ i ] ].push_back ( i ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        code[ i ] = rng ( ) ;
    }
}

vector < int > to_solve[ MAXN ] ;

void solve ( ) {
    dfs ( 1 , -1 ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        scanf ( "%d%d%d%d" , &qlist[ i ].x , &qlist[ i ].y , &qlist[ i ].l , &qlist[ i ].r ) ;
        qlist[ i ].lca = get_LCA ( qlist[ i ].x , qlist[ i ].y ) ;
    }
    w.init ( ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        ret[ i ] = 0 ;
        to_solve[ qlist[ i ].l - 1 ].push_back ( i ) ;
        to_solve[ qlist[ i ].r ].push_back ( i ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( auto x : val_list[ i ] ) {
            w.update ( st[ x ] , code[ i ] ) ;
            if ( en[ x ] + 1 <= n ) {
                w.update ( en[ x ] + 1 , code[ i ] ) ;
            }
        }
        for ( auto x : to_solve[ i ] ) {
            int aux = w.query ( st[ qlist[ x ].x ] ) ^ w.query ( st[ qlist[ x ].y ] ) ;
            if ( a[ qlist[ x ].lca ] <= i ) {
                aux ^= code[ a[ qlist[ x ].lca ] ] ;
            }
            if ( i + 1 == qlist[ x ].l ) {
                pre_xor[ x ] = aux ;
            }
            ret[ x ] ^= aux ;
        }
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( ret[ i ] == 0 ) {
            ans[ i ] = -1 ;
        }
    }
    w.init ( ) ;
    for ( int cnt = 0 ; cnt < 20  ; ++ cnt ) {
        w.init ( ) ;
        for ( int i = 0 ; i <= n ; ++ i ) {
            to_solve[ i ].clear ( ) ;
        }
        for ( int i = 1 ; i <= q ; ++ i ) {
            ret[ i ] = pre_xor[ i ] ;
            if ( ans[ i ] == -1 ) { continue ; }
            if ( qlist[ i ].l == qlist[ i ].r ) { continue ; }
            qlist[ i ].mid = ( qlist[ i ].l + qlist[ i ].r ) / 2 ;
            to_solve[ qlist[ i ].mid ].push_back ( i ) ;
        }
        for ( int i = 1 ; i <= n ; ++ i ) {
            for ( auto x : val_list[ i ] ) {
                w.update ( st[ x ] , code[ i ] ) ;
                if ( en[ x ] + 1 <= n ) {
                    w.update ( en[ x ] + 1 , code[ i ] ) ;
                }
            }
            for ( auto x : to_solve[ i ] ) {
                int aux = w.query ( st[ qlist[ x ].x ] ) ^ w.query ( st[ qlist[ x ].y ] ) ;
                if ( a[ qlist[ x ].lca ] <= i ) {
                    aux ^= code[ a[ qlist[ x ].lca ] ] ;
                }
                ret[ x ] ^= aux ;
            }
        }
        for ( int i = 1 ; i <= q ; ++ i ) {
            if ( ans[ i ] == -1 ) { continue ; }
            if ( qlist[ i ].l == qlist[ i ].r ) { continue ; }
            if ( ret[ i ] == 0 ) { qlist[ i ].l = qlist[ i ].mid + 1 ; }
            else { qlist[ i ].r = qlist[ i ].mid ; }
        }
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( ans[ i ] == -1 ) { printf ( "-1\n" ) ; }
        else { printf ( "%d\n" , qlist[ i ].l ) ; }
    }
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