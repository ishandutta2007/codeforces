#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , k ;
vector < int > v[ MAXN ] ;

int col[ MAXN ] ;
int dep[ MAXN ] ;
int mx[ MAXN ][ 3 ] ;
int lst[ MAXN ] ;
int diam_len ;

void dfs_col ( int vertex , int prv , int aux ) {
    col[ vertex ] = aux ;
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dfs_col ( x , vertex , 3 - aux ) ;
    }
}

void dfs_init ( int vertex , int prv ) {
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dep[ x ] = dep[ vertex ] + 1 ;
        dfs_init ( x , vertex ) ;
    }
}

void dfs ( int vertex , int prv ) {
    for ( int i = 0 ; i < 3 ; ++ i ) { mx[ vertex ][ i ] = -2 * MAXN ; }
    auto upd = [ & ] ( int x ) {
        if ( mx[ vertex ][ 0 ] < x ) {
            mx[ vertex ][ 2 ] = mx[ vertex ][ 1 ] ;
            mx[ vertex ][ 1 ] = mx[ vertex ][ 0 ] ;
            mx[ vertex ][ 0 ] = x ;
        }
        else if ( mx[ vertex ][ 1 ] < x ) {
            mx[ vertex ][ 2 ] = mx[ vertex ][ 1 ] ;
            mx[ vertex ][ 1 ] = x ;
        }
        else if ( mx[ vertex ][ 2 ] < x ) {
            mx[ vertex ][ 2 ] = x ;
        }
    };
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        dep[ x ] = dep[ vertex ] + 1 ;
        lst[ x ] = vertex ;
        dfs ( x , vertex ) ;
        upd ( mx[ x ][ 0 ] + 1 ) ;
    }
    if ( mx[ vertex ][ 0 ] < 0 ) { mx[ vertex ][ 0 ] = 0 ; }
}

void rec_fill ( int vertex , int prv , int dir ) {
    col[ vertex ] = col[ prv ] + dir ;
    if ( col[ vertex ] > k ) { col[ vertex ] = 1 ; }
    if ( col[ vertex ] <= 0 ) { col[ vertex ] = k ; }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        rec_fill ( x , vertex , dir ) ;
    }
}

void mark_col ( int vertex , int prv ) {
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        if ( col[ x ] == 0 ) {
            if ( dep[ vertex ] <= ( diam_len  / 2 ) ) {
                rec_fill ( x , vertex , 1 ) ;
            }
            else {
                rec_fill ( x , vertex , -1 ) ;
            }
        }
        else { mark_col ( x , vertex ) ; }
    }
}


void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ; scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
}

void solve ( ) {
    if ( k == 2 ) {
        dfs_col ( 1 , -1 , 1 ) ;
        printf ( "Yes\n" ) ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            printf ( "%d " , col[ i ] ) ;
        }
        printf ( "\n" ) ;
        return ;
    }
    dfs_init ( 1 , -1 ) ;
    int root = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( dep[ i ] > dep[ root ] ) { root = i ; }
    }
    dep[ root ] = 0 ;
    dfs ( root , -1 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( mx[ i ][ 1 ] + mx[ i ][ 2 ] + 1 >= k ) {
            printf ( "No\n" ) ;
            return ;
        }
        if ( mx[ i ][ 0 ] + mx[ i ][ 1 ] + 1 >= k && mx[ i ][ 1 ] + dep[ i ] + 1 >= k ) {
            printf ( "No\n" ) ;
            return ;
        }
    }
    int target = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( dep[ i ] > dep[ target ] ) { target = i ; }
    }
    diam_len = dep[ target ] ;
    int dummy = target , tp = 1 ;
    while ( dummy != 0 ) {
        col[ dummy ] = tp ++ ;
        if ( tp > k ) { tp = 1 ; }
        dummy = lst[ dummy ] ;
    }
    mark_col ( root , -1 ) ;
    printf ( "Yes\n" ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        printf ( "%d " , col[ i ] ) ;
    }
    printf ( "\n" ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}