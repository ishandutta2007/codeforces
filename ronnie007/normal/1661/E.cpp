#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int MAXN = 6e5 + 7 ; 

int n ;
string a[ 3 ] ;

int prv[ 17 ] ;

int get ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = get ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}
int unite ( int x , int y ) {
    int k1 = get ( x ) , k2 = get ( y ) ;
    if ( k1 != k2 ) {
        prv[ k1 ] = k2 ;
        return 1 ;
    }
    return 0 ;
}


struct node {
    int l[ 3 ] , r[ 3 ] ;
    int comps , len ;
    node ( ) {
        for ( int i = 0 ; i < 3 ; ++ i ) {
            l[ i ] = r[ i ] = 0 ;
        }
        comps = len = 0 ;
    }
};
set < int > s ;
map < int , int > aux ;

int aux_l[ 3 ] , aux_r[ 3 ] ;

node op_ret ;

void merge ( node &p1 , node &p2 ) {
    if ( p1.len == 0 ) { op_ret = p2 ; return ; }
    if ( p2.len == 0 ) { op_ret = p1 ; return ; }
    op_ret = node ( ) ;
    op_ret.len = p1.len + p2.len ;
    op_ret.comps = p1.comps + p2.comps ;
    int mx1 = 0 , mx2 = 0 ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        mx1 = max ( mx1 , p1.l[ i ] ) ;
        mx1 = max ( mx1 , p1.r[ i ] ) ;
        mx2 = max ( mx2 , p2.l[ i ] ) ;
        mx2 = max ( mx2 , p2.r[ i ] ) ;
    }
    for ( int i = 0 ; i <= mx1 + mx2 ; ++ i ) {
        prv[ i ] = -1 ;
    }
    for ( int i = 0 ; i < 3 ; ++ i ) {
        if ( p1.r[ i ] != 0 && p2.l[ i ] != 0 ) {
            op_ret.comps -= unite ( p1.r[ i ] , mx1 + p2.l[ i ] ) ;
        }
    }
    int tp = 0 ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        if ( p1.l[ i ] != 0 ) {
            op_ret.l[ i ] = 0 ;
            for ( int j = 0 ; j < i ; ++ j ) {
                if ( p1.l[ j ] > 0 && get ( p1.l[ j ] ) == get ( p1.l[ i ] ) ) {
                    op_ret.l[ i ] = op_ret.l[ j ] ;
                    break ;
                }
            }
            if ( op_ret.l[ i ] == 0 ) {
                op_ret.l[ i ] = ++ tp ;
            }
        }
        else { op_ret.l[ i ] = 0 ; }
    }
    for ( int i = 0 ; i < 3 ; ++ i ) {
        if ( p2.r[ i ] != 0 ) {
            op_ret.r[ i ] = 0 ;
            for ( int j = 0 ; j < 3 ; ++ j ) {
                if ( p1.l[ j ] > 0 && get ( mx1 + p2.r[ i ] ) == get ( p1.l[ j ] ) ) {
                    op_ret.r[ i ] = op_ret.l[ j ] ;
                    break ;
                }
            }
            if ( op_ret.r[ i ] == 0 ) {
                for ( int j = 0 ; j < i ; ++ j ) {
                    if ( p2.r[ j ] > 0 && get ( mx1 + p2.r[ i ] ) == get ( mx1 + p2.r[ j ] ) ) {
                        op_ret.r[ i ] = op_ret.r[ j ] ;
                        break ;
                    }
                }
            }
            if ( op_ret.r[ i ] == 0 ) {
                op_ret.r[ i ] = ++ tp ;
            }
        }
        else { op_ret.r[ i ] = 0 ; }
    }
}

node ret ;

class Tree {
public :
    node tr[ 2 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            int tp = 0 ;
            for ( int i = 0 ; i < 3 ; ++ i ) {
                if ( a[ i ][ IL - 1 ] == '1' ) {
                    if ( i > 0 && a[ i - 1 ][ IL - 1 ] == '1' ) {
                        tr[ where ].l[ i ] = tr[ where ].l[ i - 1 ] ;
                        tr[ where ].r[ i ] = tr[ where ].r[ i - 1 ] ;
                    }
                    else {
                        tr[ where ].l[ i ] = tr[ where ].r[ i ] = ++ tp ;
                    }
                }
            }
            tr[ where ].comps = tp ;
            tr[ where ].len = 1 ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
        tr[ where ] = op_ret ;
    }
    void query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            node cpy = ret ;
            merge ( cpy , tr[ where ] ) ;
            ret = op_ret ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        query ( 2 * where , IL , mid , CURL , CURR ) ;
        query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};

Tree w ;

void solve ( ) {
    cin >> n ;
    for ( int i = 0 ; i < 3 ; ++ i ) {
        cin >> a[ i ] ;
    }
    w.init ( 1 , 1 , n ) ;
    int q ; cin >> q ;
    while ( q -- ) {
        int l , r ;
        cin >> l >> r ;
        ret = node ( ) ;
        w.query ( 1 , 1 , n , l , r ) ;
        cout << ret.comps << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ; // cin >> t ; 
    while ( t -- ) { solve ( ) ; }
    return 0 ;
}