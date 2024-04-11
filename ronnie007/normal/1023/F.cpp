#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007
#define LOG 19
#define inf 1000000007

int n , k , m ;
vector < pair < int , int > > v[ MAXN ] ;

struct tuhla {
    int x , y , z ;
};
tuhla a[ MAXN ] ;

int subtree[ MAXN ] ;
int heavy[ MAXN ] ;
int lvl[ MAXN ] ;
int pos_in_tree[ MAXN ] ;
int root[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;

bool fl ;
long long ans ;

class dsu {
public :
    int prv[ MAXN ] ;
    int rnk[ MAXN ] ;
    void init ( int n ) {
        for ( int i = 1 ; i <= n ; ++ i ) {
            prv[ i ] = -1 ;
            rnk[ i ] = 0 ;
        }
    }
    int find ( int x ) {
        if ( prv[ x ] == -1 ) { return x ; }
        int y = find ( prv[ x ] ) ;
        prv[ x ] = y ;
        return y ;
    }
    void unite ( int x , int y , int z ) {
        int k1 = find ( x ) ;
        int k2 = find ( y ) ;
        if ( k1 != k2 ) {
            v[ x ].push_back ( { y , z } ) ;
            v[ y ].push_back ( { x , z } ) ;
            if ( rnk[ k1 ] >= rnk[ k2 ] ) {
                rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
                prv[ k2 ] = k1 ;
            }
            else {
                prv[ k1 ] = k2 ;
            }
        }
    }
};
dsu q ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = inf ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            tr[ where ] = min ( tr[ where ] , val ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
    }
    int query ( int where , int IL , int IR , int pos ) {
        if ( IL == IR ) { return tr[ where ] ; }
        int sr = tr[ where ] ;
        int ret = inf ;
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            ret = query ( 2 * where , IL , mid , pos ) ;
        }
        else {
            ret = query ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        return min ( ret , sr ) ;
    }
};

Tree w ;

void dfs ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    subtree[ vertex ] = 1 ;
    int mx = 0 ;
    for ( int i = 1 ; i < LOG ; ++ i ) {
        LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        if ( h == prv ) { continue ; }
        lvl[ h ] = lvl[ vertex ] + 1 ;
        LCA[ h ][ 0 ] = vertex ;
        dfs ( h , vertex ) ;
        subtree[ vertex ] += subtree[ h ] ;
        if ( mx < subtree[ h ] ) {
            mx = subtree[ h ] ;
            heavy[ vertex ] = h ;
        }
    }
}

int get_LCA ( int x , int y ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( lvl[ x ] - (1<<i) >= lvl[ y ] ) {
            x = LCA[ x ][ i ] ;
        }
        if ( lvl[ y ] - (1<<i) >= lvl[ x ] ) {
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

void upd ( int vertex , int sr , int val ) {
    if ( lvl[ vertex ] < sr ) { return ; }
    while ( lvl[ vertex ] >= sr ) {
        int hh = root[ vertex ] ;
        if ( lvl[ hh ] >= sr ) {
            w.update ( 1 , 1 , n , pos_in_tree[ hh ] , pos_in_tree[ vertex ] , val ) ;
            vertex = LCA[ hh ][ 0 ] ;
        }
        else {
            int len = lvl[ vertex ] - sr ;
            w.update ( 1 , 1 , n , pos_in_tree[ vertex ] - len , pos_in_tree[ vertex ] , val ) ;
            return ;
        }
    }
}

void get_ans ( int vertex , int prv ) {
    int sz = v[ vertex ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        int h = v[ vertex ][ i ].first ;
        int c = v[ vertex ][ i ].second ;
        if ( h == prv ) { continue ; }
        if ( c == inf ) {
            int ret = w.query ( 1 , 1 , n , pos_in_tree[ h ] ) ;
            if ( ret == inf ) { fl = true ; }
            else { ans += ret ; }
        }
        get_ans ( h , vertex ) ;
    }
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &k , &m ) ;
    q.init ( n ) ;
    for ( int i = 1 ; i <= k ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        q.unite ( x , y , inf ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].z ) ;
        q.unite ( a[ i ].x , a[ i ].y , a[ i ].z ) ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    int id = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( heavy[ LCA[ i ][ 0 ] ] != i ) {
            int x = i ;
            while ( x > 0 ) {
                root[ x ] = i ;
                pos_in_tree[ x ] = ++ id ;
                x = heavy[ x ] ;
            }
        }
    }
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        int aux = get_LCA ( a[ i ].x , a[ i ].y ) ;
        upd ( a[ i ].x , lvl[ aux ] + 1 , a[ i ].z ) ;
        upd ( a[ i ].y , lvl[ aux ] + 1 , a[ i ].z ) ;
    }
    get_ans ( 1 , -1 ) ;
    if ( fl == true ) { printf ( "-1\n" ) ; }
    else { printf ( "%I64d\n" , ans ) ; }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}