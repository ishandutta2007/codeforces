#include<bits/stdc++.h>
using namespace std ;

#pragma GCC optimize ("O3")

#define MAXN 200007
#define MAXVAL 5050007
#define MXDIST 15


int n , q ;
int a[ MAXN ] ;

int ans[ MAXVAL ] ;

int mnpos[ MAXN ][ MXDIST ] ;

int query_ret[ MXDIST ] ;

vector < int > divs[ MAXVAL ] ;
vector < int > act[ MAXVAL ] ;
mt19937 rng ( time ( 0 ) ) ;


struct treap {
    int key , prior ;
    int node_val ;
    int mn ;
    treap *pl , *pr ;
    treap ( ) {
        key = 0 ;
        prior = 0 ;
        node_val = mn = MAXVAL ;
        pl = pr = NULL ;
    }
    treap ( int _key , int _val ) {
        key = _key ;
        prior = rng ( ) ;
        node_val = mn = _val ;
        pl = pr = NULL ;
    }
};

void upd ( treap *w ) {
    if ( w == NULL ) { return ; }
    w->mn = w->node_val ;
    if ( w->pl != NULL ) {
        w->mn = min ( w->mn , w->pl->mn ) ;
    }
    if ( w->pr != NULL ) {
        w->mn = min ( w->mn , w->pr->mn ) ;
    }
}

treap *root[ MAXVAL ] ;

void split ( treap *w , treap* (&l) , treap* (&r) , int sr ) {
    if ( w == NULL ) { l = NULL ; r = NULL ; return ; }
    if ( w->key <= sr ) {
        split ( w->pr , w->pr , r , sr ) ;
        l = w ;
        upd ( l ) ;
    }
    else {
        split ( w->pl , l , w->pl , sr ) ;
        r = w ;
        upd ( r ) ;
    }
}

static void merge ( treap* (&w) , treap *l , treap *r ) {
    if ( l == NULL ) { w = r ; return ; }
    if ( r == NULL ) { w = l ; return ; }
    if ( l->prior >= r->prior ) {
        merge ( l->pr , l->pr , r ) ;
        w = l ;
        upd ( w ) ;
    }
    else {
        merge ( r->pl , l , r->pl ) ;
        w = r ;
        upd ( w ) ;
    }
}

static void obtain ( treap *w , int sr , int &ref) {
    if ( w == NULL ) { return ; }
    if ( w->key > sr ) { obtain ( w->pl , sr , ref ) ; }
    else {
        ref = min ( ref , w->node_val ) ;
        if ( w->pl != NULL ) {
            ref = min ( ref , w->pl->mn ) ;
        }
        obtain ( w->pr , sr , ref ) ;
        return ;
    }
}

void add ( int pos , int val , int id ) {
    treap *aux = new treap ( pos , val ) ;
    merge ( root[ id ] , aux , root[ id ] ) ;
}

void init ( ) {
    for ( int i = 2 ; i < MAXVAL ; ++ i ) {
        if ( divs[ i ].size ( ) != 0 ) { continue ; }
        for ( int j = i ; j < MAXVAL ; j += i ) {
            divs[ j ].push_back ( i ) ;
        }
    }
    for ( int i = 2 ; i < MAXVAL ; ++ i ) {
        int sz = divs[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            int aux = i ;
            int cnt = 0 ;
            while ( ( aux % divs[ i ][ j ] ) == 0 ) {
                aux /= divs[ i ][ j ] ;
                ++ cnt ;
            }
            if ( ( cnt % 2 ) == 1 ) {
                act[ i ].push_back ( divs[ i ][ j ] ) ;
            }
        }
    }
}

static int f ( int i , int en , int rbound , int lbound ) {
    int sz = act[ a[ i ] ].size ( ) ;
    int ret = rbound ;
    for ( int j = (1<<sz) - 1 ; j >= 0 ; -- j ) {
        int val = 1 ;
        int sub = 0 ;
        for ( int t = 0 ; t < sz ; ++ t ) {
            if ( ( j & (1<<t) ) > 0 ) { val *= act[ a[ i ] ][ t ] ; ++ sub ; }
        }
        if ( sz - 2 * sub > ret ) { continue ; }
        int p = MXDIST ;
        obtain ( root[ val ] , en , p ) ;
        ret = min ( ret , sz + p - 2 * sub ) ;
        if ( ret == lbound ) { break ; }
    }
    return ret ;
}

static void rec ( int i , int l , int r , int l_bound , int r_bound ) {
    if ( l > r ) { return ; }
    if ( l_bound == r_bound ) { return ; }

    int mid = ( l + r ) / 2 ;
    int aux = f ( i , mid , r_bound , l_bound ) ;
    mnpos[ i ][ aux ] = min ( mnpos[ i ][ aux ] , mid ) ;
    
    rec ( i , l , mid - 1 , aux , r_bound ) ;
    rec ( i , mid + 1 , r , l_bound , aux ) ;
}

class Tree {
public :
    int tr[ 4 * MAXN ][ MXDIST ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            for ( int i = 0 ; i < MXDIST ; ++ i ) {
                tr[ where ][ i ] = mnpos[ IL ][ i ] ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        for ( int i = 0 ; i < MXDIST ; ++ i ) {
            tr[ where ][ i ] = min ( tr[ 2 * where ][ i ] , tr[ 2 * where + 1 ][ i ] ) ;
        }
    }
    void query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return  ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            for ( int i = 0 ; i < MXDIST ; ++ i ) {
                query_ret[ i ] = min ( query_ret[ i ] , tr[ where ][ i ] ) ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( CURL <= mid ) {
            query ( 2 * where , IL , mid , CURL , CURR ) ;
        }
        if ( mid < CURR ) {
            query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        }
    }
};
Tree w ;

int ZX[ MAXVAL ][ 8 ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i < MAXVAL ; ++ i ) {
        root[ i ] = NULL ;
    }
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( int j = 0 ; j < MXDIST ; ++ j ) {
            mnpos[ i ][ j ] = MAXN ; 
        }
        /**
        rec ( i , i + 1 , n , 0 , MXDIST ) ;
        int sz = act[ a[ i ] ].size ( ) ;
        for ( int j = 0 ; j < (1<<sz) ; ++ j ) {
            int val = 1 ;
            for ( int t = 0 ; t < sz ; ++ t ) {
                if ( ( j & (1<<t) ) > 0 ) { val *= act[ a[ i ] ][ t ] ; }
            }
            add ( i , sz , val ) ;
        }
        **/
        int sz = act[ a[ i ] ].size ( ) ;
        for ( int j = 0 ; j < (1<<sz ) ; ++ j ) {
            int val = 1 ;
            int sub = 0 ;
            for ( int t = 0 ; t < sz ; ++ t ) {
                if ( ( j & (1<<t) ) > 0 ) { val *= act[ a[ i ] ][ t ] ; ++ sub ; }
            }
            for ( int t = 0 ; t <= 7 ; ++ t ) {
                if ( ZX[ val ][ t ] != 0 ) {
                    int id = sz + t - 2 * sub ;
                    mnpos[ i ][ id ] = min ( mnpos[ i ][ id ] , ZX[ val ][ t ] ) ;
                }
            }
            ZX[ val ][ sz ] = i ;
        }
    }
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        int l , r ;
        scanf ( "%d%d" , &l , &r ) ;
        for ( int j = 0 ; j <= MXDIST ; ++ j ) {
            query_ret[ j ] = MAXN ;
        }
        w.query ( 1 , 1 , n , l , r ) ;
        for ( int j = 0 ; j < MXDIST ; ++ j ) {
            if ( query_ret[ j ] <= r ) { printf ( "%d\n" , j ) ; break ; }
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    init ( ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}