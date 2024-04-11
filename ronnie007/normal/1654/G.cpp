#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n ;
int a[ MAXN ] ;
bool has_eq[ MAXN ] , used[ MAXN ] ;
int subtree[ MAXN ] , tot ; 
vector < int > v[ MAXN ] ;

int mn_val[ MAXN ] ;


void init ( int vertex , int prv ) {
    ++ tot , subtree[ vertex ] = 1 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv || used[ x ] == true ) { continue ; }
        init ( x , vertex ) ;
        subtree[ vertex ] += subtree[ x ] ;
    }
}
int get_cen ( int vertex , int prv ) {
    for ( auto x : v[ vertex ] ) {
        if ( x == prv || used[ x ] == true ) { continue ; }
        if ( 2 * subtree[ x ] > tot ) {
            return get_cen ( x , vertex ) ;
        }
    }
    return vertex ;
}

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = MAXN ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IL == IR ) {
            if ( val == MAXN ) { tr[ where ] = val ; }
            else { tr[ where ] = min ( tr[ where ] , val ) ; }
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
        if ( IL > IR || CURL > CURR ) { return MAXN ; }
        if ( IR < CURL || CURR < IL ) { return MAXN ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ; 
    }
};

Tree w ;

void dfs_up ( int vertex , int prv , int sm , int mn ) {
    if ( mn == sm ) {
        int lft = -mn ;
        mn_val[ vertex ] = min ( mn_val[ vertex ] , w.query ( 1 , 1 , n , 1 , lft + 1 ) ) ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv || used[ x ] == true ) { continue ; }
        if ( a[ x ] < a[ vertex ] ) { continue ; }
        int coef = -1 ;
        if ( a[ x ] == a[ vertex ] ) { coef = 1 ; }
        dfs_up ( x , vertex , sm + coef , min ( mn , sm + coef ) ) ;
    }
}

void dfs_down ( int vertex , int prv , int sm , int mn ) {
    if ( has_eq[ vertex ] == true ) {
        int need = -mn ;
        w.update ( 1 , 1 , n , need + 1 , a[ vertex ] ) ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv || used[ x ] == true ) { continue ; }
        if ( a[ x ] > a[ vertex ] ) { continue ; }
        int coef = 1 ;
        if ( a[ x ] == a[ vertex ] ) { coef = -1 ; }
        dfs_down ( x , vertex , sm + coef , min ( mn , sm + coef ) ) ;        
    }
}

void dfs_rem ( int vertex , int prv , int sm , int mn ) {
    if ( has_eq[ vertex ] == true ) {
        int need = -mn ;
        w.update ( 1 , 1 , n , need + 1 , MAXN ) ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv || used[ x ] == true ) { continue ; }
        if ( a[ x ] > a[ vertex ] ) { continue ; }
        int coef = 1 ;
        if ( a[ x ] == a[ vertex ] ) { coef = -1 ; }
        dfs_rem ( x , vertex , sm + coef , min ( mn , sm + coef ) ) ;        
    }
}

void decompose ( int vertex ) {
    tot = 0 ;
    init ( vertex , -1 ) ;
    vertex = get_cen ( vertex , -1 ) ;
    used[ vertex ] = true ;
    int sz = v[ vertex ].size ( ) ;
    int st = 0 , en = sz ;
    for ( int step = 1 ; step >= -1 ; step -= 2 ) { 
        if ( has_eq[ vertex ] == true ) {
            w.update ( 1 , 1 , n , 1 , a[ vertex ] ) ;
        }
        for ( int i = st ; i != en ; i += step ) {
            int x = v[ vertex ][ i ] ;
            if ( used[ x ] == true ) { continue ; }
            int coef = 0 ;
            if ( a[ x ] >= a[ vertex ] ) {
                coef = -1 ;
                if ( a[ x ] == a[ vertex ] ) { coef = 1 ; }
                dfs_up ( x , vertex , coef , min ( coef , 0 ) ) ;
            }
            if ( a[ x ] <= a[ vertex ] ) { 
                coef = 1 ;
                if ( a[ x ] == a[ vertex ] ) { coef = -1 ; }
                dfs_down ( x , vertex , coef , min ( coef , 0 ) ) ;
            }
        }
        mn_val[ vertex ] = min ( mn_val[ vertex ] , w.query ( 1 , 1 , n , 1 , 1 ) ) ;
        for ( int i = st ; i != en ; i += step ) {
            int x = v[ vertex ][ i ] ;
            if ( used[ x ] == true ) { continue ; }
            if ( a[ x ] > a[ vertex ] ) { continue ; }
            int coef = 1 ;
            if ( a[ x ] == a[ vertex ] ) { coef = -1 ; }
            dfs_rem ( x , vertex , coef , min ( coef , 0 ) ) ;
        }
        if ( has_eq[ vertex ] == true ) {
            w.update ( 1 , 1 , n , 1 , MAXN ) ; 
        }
        st = sz - 1 , en = -1 ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( used[ x ] == true ) { continue ; }
        decompose ( x ) ;
    }
}

queue < int > q ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = MAXN ; 
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int val ; cin >> val ;
        if ( val == 1 ) {
            q.push ( i ) , a[ i ] = 0 ;
        }
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ; cin >> x >> y ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    while ( q.empty ( ) == false ) {
        int x = q.front ( ) ;
        q.pop ( ) ;
        for ( auto y : v[ x ] ) {
            if ( a[ y ] == MAXN ) {
                a[ y ] = a[ x ] + 1 ;
                q.push ( y ) ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( auto j : v[ i ] ) {
            if ( a[ i ] == a[ j ] ) {
                has_eq[ i ] = true ;
                break ;
            }
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        mn_val[ i ] = a[ i ] ;
    }
    w.init ( 1 , 1 , n ) ;
    decompose ( 1 ) ;

    for ( int i = 1 ; i <= n ; ++ i ) {
        cout << a[ i ] + ( a[ i ] - mn_val[ i ] ) << " " ;
    }
    cout << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t = 1 ;
    // cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}