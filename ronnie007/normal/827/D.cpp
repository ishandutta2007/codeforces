#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define LOG 19

int n , m ;
struct edge {
    int x , y ;
    int len ;
    int lca_ver ;
    int id ;
    bool operator < ( edge other ) {
        return len < other.len ;
    }
};
int ans[ MAXN ] ;
edge a[ MAXN ] ;
vector < pair < int , int > > v[ MAXN ] ;
vector < pair < int , int > > other[ MAXN ] ;

bool in_mst[ MAXN ] ;

int st[ MAXN ] ;
int en[ MAXN ] ;

int prv[ MAXN ] ;
int rnk[ MAXN ] ;
int subtree[ MAXN ] ;

int LCA[ MAXN ][ LOG ] ;
int mx[ MAXN ][ LOG ] ;
int lvl[ MAXN ] ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

void UNITE ( edge aux , int id ) {
    int k1 = find ( aux.x ) ;
    int k2 = find ( aux.y ) ;
    if ( k1 != k2 ) {
        in_mst[ id ] = true ;
        v[ aux.x ].push_back ( { aux.y , id } ) ;
        v[ aux.y ].push_back ( { aux.x , id } ) ;
        
        if ( rnk[ k1 ] < rnk[ k2 ] ) {
            prv[ k1 ] = k2 ;
        }
        else if ( rnk[ k1 ] > rnk[ k2 ] ) {
            prv[ k2 ] = k1 ;
        }
        else {
            prv[ k1 ] = k2 ;
            ++ rnk[ k2 ] ;
        }
    }
    else {
        other[ aux.x ].push_back ( { aux.y , id } ) ;
        other[ aux.y ].push_back ( { aux.x , id } ) ;
    }
}

int total_tm ;

void dfs ( int vertex , int prv ) {
    st[ vertex ] = ++ total_tm ;
    subtree[ vertex ] = 1 ;
    int sz = v[ vertex ].size ( ) ;
    if ( prv > -1 ) {
        for ( int i = 1 ; i < LOG ; ++ i ) {
            LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
            mx[ vertex ][ i ] = max ( mx[ vertex ][ i - 1 ] , mx[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ) ;
        }
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int id = v[ vertex ][ i ].second ;
        if ( h == prv ) { continue ; }
        lvl[ h ] = lvl[ vertex ] + 1 ;
        LCA[ h ][ 0 ] = vertex ;
        mx[ h ][ 0 ] = a[ id ].len ;
        dfs ( h , vertex ) ;
        subtree[ vertex ] += subtree[ h ] ;
    }
    en[ vertex ] = total_tm ;
}

int get ( int x , int y ) {
    int ret = -1 ;
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( lvl[ x ] - (1<<i) >= lvl[ y ] ) {
            ret = max ( ret , mx[ x ][ i ] ) ;
            x = LCA[ x ][ i ] ;
        }
        if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
            ret = max ( ret , mx[ y ][ i ] ) ;
            y = LCA[ y ][ i ] ;
        }
    }
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( LCA[ x ][ i ] != LCA[ y ][ i ] ) {
            ret = max ( ret , mx[ x ][ i ] ) ;
            ret = max ( ret , mx[ y ][ i ] ) ;
            x = LCA[ x ][ i ] ;
            y = LCA[ y ][ i ] ;
        }
    }
    if ( x != y ) {
        ret = max ( ret , mx[ x ][ 0 ] ) ;
        ret = max ( ret , mx[ y ][ 0 ] ) ;
    }
    return ret ;
}

#define inf 1000000007

class Tree {
public :
    int tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = inf ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            if ( val == inf || val < tr[ where ] ) {
                tr[ where ] = val ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return inf ; }
        if ( IR < CURL || CURR < IL ) { return inf ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

Tree w ;

void proc_edges ( int vertex , bool fl ) {
    int sz = other[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = other[ vertex ][ i ].first ;
        int len = a[ other[ vertex ][ i ].second ].len ;
        if ( fl == true ) {
            w.update ( 1 , 1 , n , st[ h ] , len ) ;
        }
        else {
            w.update ( 1 , 1 , n , st[ h ] , inf ) ;
        }
    }
}

void proc_subtree ( int vertex , int prv , bool fl ) {
    int sz = v[ vertex ].size ( ) ;
    proc_edges ( vertex , fl ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        if ( v[ vertex ][ i ].first == prv ) { continue ; }
        proc_subtree ( v[ vertex ][ i ].first , vertex , fl ) ;
    }
}

void calc ( int vertex , int prv , bool fl ) {
    int sz = v[ vertex ].size ( ) ;
    int lg = -1 ;
    int ver_id = -1 ;
    int edge_id = -1 ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int id = v[ vertex ][ i ].second ;
        if ( id == prv ) { continue ; }
        if ( lg < subtree[ h ] ) {
            lg = subtree[ h ] ;
            ver_id = h ;
            edge_id = id ;
        }
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int id = v[ vertex ][ i ].second ;
        if ( id == prv ) { continue ; }
        if ( id == edge_id ) { continue ; }
        calc ( h , id , false ) ;
    }
    if ( edge_id > -1 ) {
        calc ( ver_id , edge_id , true ) ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int id = v[ vertex ][ i ].second ;
        if ( id == prv ) { continue ; }
        if ( id == edge_id ) { continue ; }
        proc_subtree ( h , vertex , true ) ;
    }
    proc_edges ( vertex , true ) ;
    ans[ a[ prv ].id ] = min ( w.query ( 1 , 1 , n , 1 , st[ vertex ] - 1 ) , w.query ( 1 , 1 , n , en[ vertex ] + 1 , n ) ) - 1 ;
    if ( fl == false ) {
        proc_subtree ( vertex , LCA[ vertex ][ 0 ] , false ) ;
    }
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].len ) ;
        a[ i ].id = i ;
    }
    sort ( a + 1 , a + m + 1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
    }
}

void solve ( ) {
    for ( int i = 1 ; i <= m ; ++ i ) {
        UNITE ( a[ i ] , i ) ;
    }
    dfs ( 1 , -1 ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( in_mst[ i ] == false ) {
            ans[ a[ i ].id ] = get ( a[ i ].x , a[ i ].y ) - 1 ;
        }
    }
    w.init ( 1 , 1 , n ) ;
    calc ( 1 , -1 , true ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        if ( ans[ i ] == inf - 1 ) { ans[ i ] = -1 ; }
        printf ( "%d " , ans[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}