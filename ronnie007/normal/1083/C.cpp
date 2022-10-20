#include<bits/stdc++.h>
using namespace std ;

#define MAXN 400007
#define LOG 20

int n ;
int a[ MAXN ] ;
int rv[ MAXN ] ;

vector < int > v[ MAXN ] ;
int lvl[ MAXN ] ;
int st[ MAXN ] ;
int en[ MAXN ] ;

int tpsz ;

pair < int , int > prec[ LOG ][ MAXN ] ;
int pw[ MAXN ] ;

void dfs ( int vertex ) {
    st[ vertex ] = ++ tpsz ;
    prec[ 0 ][ tpsz ] = { lvl[ vertex ] , vertex } ;
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        lvl[ v[ vertex ][ i ] ] = lvl[ vertex ] + 1 ;
        dfs ( v[ vertex ][ i ] ) ;
        ++ tpsz ;
        prec[ 0 ][ tpsz ] = { lvl[ vertex ] , vertex } ;
    }
    en[ vertex ] = tpsz ;
}

bool parent ( int x , int y ) {
    if ( st[ x ] <= st[ y ] && en[ y ] <= en[ x ] ) { return true ; }
    return false ;
}

struct node {
    bool fl ;
    int x , y ;
    node ( ) { fl = false ; x = y = 0 ; }
    node ( int _id ) {
        fl = true ;
        x = y = _id ;
    }
};

int get_LCA ( int x , int y ) {
    if ( st[ x ] > st[ y ] ) { swap ( x , y ) ; }
    int len = st[ y ] - st[ x ] + 1 ;
    pair < int , int > sr1 = prec[ pw[ len ] ][ st[ x ] ] ;
    pair < int , int > sr2 = prec[ pw[ len ] ][ st[ y ] - (1<<pw[ len ]) + 1 ] ;
    if ( sr1 > sr2 ) { sr1 = sr2 ; }
    return sr1.second ;
}

int get_dist ( int x , int y ) {
    int u = get_LCA ( x , y ) ;
    return lvl[ x ] + lvl[ y ] - 2 * lvl[ u ] ;
}

vector < int > pts ;

node merge ( node p1 , node p2 ) {
    if ( p1.x == 0 ) { return p2 ; }
    if ( p2.x == 0 ) { return p1 ; }
    node ret = node ( ) ;
    ret.x = ret.y = n + 1 ;
    if ( p1.fl == false || p2.fl == false ) {
        ret.fl = false ;
        return ret ;
    }
    pts.clear ( ) ;
    pts.push_back ( p1.x ) ;
    pts.push_back ( p1.y ) ;
    pts.push_back ( p2.x ) ;
    pts.push_back ( p2.y ) ;
    sort ( pts.begin ( ) , pts.end ( ) ) ;
    do {
        if ( get_dist ( pts[ 0 ] , pts[ 3 ] ) == get_dist ( pts[ 0 ] , pts[ 1 ] ) + get_dist ( pts[ 1 ] , pts[ 2 ] ) + get_dist ( pts[ 2 ] , pts[ 3 ] ) ) {
            ret.fl = true ;
            ret.x = pts[ 0 ] ;
            ret.y = pts[ 3 ] ;
            return ret ;
        }
    } while ( next_permutation ( pts.begin ( ) , pts.end ( ) ) ) ;
    ret.fl = false ;
    ret.x = ret.y = n + 1 ;
    return ret ;
}

node hh , dummy ;

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = node ( rv[ IL - 1 ] ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = node ( val ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR ) {
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        dummy = merge ( hh , tr[ 2 * where ] ) ;
        if ( dummy.fl == true ) {
            hh = dummy ;
            return query ( 2 * where + 1 , mid + 1 , IR ) ;
        }
        return query ( 2 * where , IL , mid ) ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        rv[ a[ i ] ] = i ;
    }
    for ( int i = 2 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        v[ x ].push_back ( i ) ;
    }
    dfs ( 1 ) ;
    for ( int i = 1 ; i < LOG ; ++ i ) {
        for ( int j = 1 ; j + (1<<i) <= tpsz + 1 ; ++ j ) {
            prec[ i ][ j ] = min ( prec[ i - 1 ][ j ] , prec[ i - 1 ][ j + (1<<(i-1)) ] ) ;
        }
    }
    int sr = 1 ;
    int id = 0 ;
    for ( int i = 1 ; i <= tpsz ; ++ i ) {
        while ( 2 * sr < i ) {
            sr *= 2 ; ++ id ;
        }
        pw[ i ] = id ;
    }
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    int q ;
    int type , x , y ;
    scanf ( "%d" , &q ) ;
    while ( q -- ) {
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            scanf ( "%d%d" , &x , &y ) ;
            swap ( a[ x ] , a[ y ] ) ;
            w.update ( 1 , 1 , n , a[ x ] + 1 , x ) ;
            w.update ( 1 , 1 , n , a[ y ] + 1 , y ) ;
        }
        else {
            hh = node ( ) ;
            if ( w.tr[ 1 ].fl == true ) {
                printf ( "%d\n" , n ) ;
                continue ;
            }
            printf ( "%d\n" , w.query ( 1 , 1 , n ) - 1 ) ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}