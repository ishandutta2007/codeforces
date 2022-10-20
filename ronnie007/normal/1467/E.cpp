#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007
#define MAGIC 1000
#define LOG 20

int n ;
int a[ MAXN ] ;
int freq[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;
int lvl[ MAXN ] ;
vector < int > v[ MAXN ] ;

vector < int > occ[ MAXN ] ;

int mxval ;


void input ( ) {
    set < int > s ;
    map < int , int > w ;
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        s.insert ( a[ i ] ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    int id = 0 ;
    for ( auto it : s ) {
        w[ it ] = ++ id ;
    }
    mxval = id ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ] = w[ a[ i ] ] ;
        occ[ a[ i ] ].push_back ( i ) ;
        ++ freq[ a[ i ] ] ;
    }
}

int tpsz ;
int st[ MAXN ] ;
int en[ MAXN ] ;
bool bad[ MAXN ] ;

class Tree {
public :
    bool tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = false ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            tr[ where ] = true ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
    bool query ( int where , int IL , int IR , int pos ) {
        if ( tr[ where ] == true ) { return true ; }
        if ( IL == IR ) { return false ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) { return query ( 2 * where , IL , mid , pos ) ; }
        else { return query ( 2 * where + 1 , mid + 1 , IR , pos ) ; }
    }
};
Tree w ;

void init ( int vertex , int prv ) {
    st[ vertex ] = ++ tpsz ;
    for ( int i = 1 ; i < LOG ; ++ i ) {
        LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        lvl[ x ] = lvl[ vertex ] + 1 ;
        LCA[ x ][ 0 ] = vertex ;
        init ( x , vertex ) ;
    }
    en[ vertex ] = tpsz ;
}

bool is_parent ( int x , int y ) {
    return ( st[ x ] <= st[ y ] && en[ y ] <= en[ x ] ) ;
}

int move_up ( int x , int cnt ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( cnt >= ( 1 << i ) ) {
            cnt -= ( 1 << i ) ;
            x = LCA[ x ][ i ] ;
        }
    }
    return x ;
}

void solve_light ( int id ) {
    int sz = occ[ id ].size ( ) ;
    for ( int i = 0 ; i < sz ; ++ i ) {
        for ( int j = i + 1 ; j < sz ; ++ j ) {
            int x = occ[ id ][ i ] ;
            int y = occ[ id ][ j ] ;
            if ( is_parent ( x , y ) == true ) {
                int aux = move_up ( y , lvl[ y ] - lvl[ x ] - 1 ) ;
                w.update ( 1 , 1 , n , 1 , st[ aux ] - 1 ) ;
                w.update ( 1 , 1 , n , en[ aux ] + 1 , n ) ;
                w.update ( 1 , 1 , n , st[ y ] , en[ y ] ) ;
            }
            else if ( is_parent ( y , x ) == true ) {
                int aux = move_up ( x , lvl[ x ] - lvl[ y ] - 1 ) ;
                w.update ( 1 , 1 , n , 1 , st[ aux ] - 1 ) ;
                w.update ( 1 , 1 , n , en[ aux ] + 1 , n ) ;
                w.update ( 1 , 1 , n , st[ x ] , en[ x ] ) ;
            }
            else {
                w.update ( 1 , 1 , n , st[ x ] , en[ x ] ) ;
                w.update ( 1 , 1 , n , st[ y ] , en[ y ] ) ;                
            }
        }
    }
}

int mx_down[ MAXN ] ;
int mx_up[ MAXN ] ;

void dfs_down ( int vertex , int prv , int id ) {
    int coef = 0 ;
    if ( a[ vertex ] == id ) { ++ coef ; }
    mx_down[ vertex ] = coef ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dfs_down ( x , vertex , id ) ;
        mx_down[ vertex ] = max ( mx_down[ vertex ] , mx_down[ x ] + coef ) ;
    }
}

void dfs_up ( int vertex , int prv , int up , int id ) {
    int coef = 0 ;
    if ( a[ vertex ] == id ) { ++ coef ; }
    mx_up[ vertex ] += coef ;
    int mx1 , mx2 ;
    mx1 = mx2 = -1 ;
    int id1 , id2 ;
    id1 = id2 = 0 ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        if ( mx1 < mx_down[ x ] ) {
            mx2 = mx1 ;
            id2 = id1 ;
            mx1 = mx_down[ x ] ;
            id1 = x ;
        }
        else if ( mx2 < mx_down[ x ] ) {
            mx2 = mx_down[ x ] ;
            id2 = x ;
        }
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        int sr = coef ;
        if ( x == id1 ) { sr += mx2 ; }
        else { sr += mx1 ; }
        sr = max ( sr , up + coef ) ;

        mx_up[ x ] = sr ;
        dfs_up ( x , vertex , sr , id ) ;
    }
}

void solve_heavy ( int id ) {
    dfs_down ( 1 , -1 , id ) ;
    mx_up[ 1 ] = 0 ;
    dfs_up ( 1 , -1 , 0 , id ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mx_down[ i ] > 1 || mx_up[ i ] > 1 ) { bad[ i ] = true ; }
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    init ( 1 , -1 ) ;
    for ( int i = 1 ; i <= mxval ; ++ i ) {
        if ( freq[ i ] > MAGIC ) {
            solve_heavy ( i ) ;
        }
        else {
            solve_light ( i ) ;
        }
    }
    int ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( bad[ i ] == false && w.query ( 1 , 1 , n , st[ i ] ) == false ) { ++ ans ; }
    }
    printf ( "%d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}