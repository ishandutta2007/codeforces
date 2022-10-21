#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m , q ;

int a[ 11 ][ MAXN ] ;

struct node {
    long long ans ;
    int l[ 11 ] ;
    int r[ 11 ] ;
    node ( ) {
        ans = 0 ;
        for ( int i = 1 ; i <= n ; ++ i ) {
            l[ i ] = r[ i ] = 0 ;
        }
    }
    node ( int col ) {
        l[ 1 ] = r[ 1 ] = 1 ;
        ans = 1 ;
        for ( int i = 2 ; i <= n ; ++ i ) {
            if ( a[ i ][ col ] != a[ i - 1 ][ col ] ) {
                l[ i ] = l[ i - 1 ] + 1 ;
                r[ i ] = l[ i - 1 ] + 1 ;
                ++ ans ;
            }
            else {
                l[ i ] = l[ i - 1 ] ;
                r[ i ] = l[ i - 1 ] ;
            }
        }
    }
};


int prv[ 44 ] ;
int rnk[ 44 ] ;
int pos[ 44 ] ;

int find ( int x ) {
    if ( prv[ x ] == -1 ) { return x ; }
    int y = find ( prv[ x ] ) ;
    prv[ x ] = y ;
    return y ;
}

bool unite ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    if ( k1 != k2 ) {
        if ( rnk[ k1 ] >= rnk[ k2 ] ) {
            rnk[ k1 ] += ( rnk[ k1 ] == rnk[ k2 ] ) ;
            prv[ k2 ] = k1 ;
        }
        else {
            prv[ k1 ] = k2 ;
        }
        return true ;
    }
    return false ;
}

int hh1[ 11 ] ;
int hh2[ 11 ] ;

node merge ( node &p1 , node &p2 , int col ) {
    if ( p1.ans == 0 ) { return p2 ; }
    if ( p2.ans == 0 ) { return p1 ; }
    node ret ;
    ret.ans = p1.ans + p2.ans ;
    int mx1 = 0 ;
    int mx2 = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        mx1 = max ( mx1 , p1.l[ i ] ) ;
        mx1 = max ( mx1 , p1.r[ i ] ) ;

        mx2 = max ( mx2 , p2.l[ i ] ) ;
        mx2 = max ( mx2 , p2.r[ i ] ) ;
    }
    for ( int i = 1 ; i <= mx1 + mx2 ; ++ i ) {
        prv[ i ] = -1 ;
        rnk[ i ] = 0 ;
        pos[ i ] = 0 ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i ][ col - 1 ] == a[ i ][ col ] ) {
            ret.ans -= unite ( p1.r[ i ] , p2.l[ i ] + mx1 ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        hh1[ i ] = find ( p1.l[ i ] ) ;
        hh2[ i ] = find ( mx1 + p2.r[ i ] ) ;
    }
    int id = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int aux = find ( hh1[ i ] ) ;
        if ( pos[ aux ] == 0 ) {
            pos[ aux ] = ++ id ;
        }
        ret.l[ i ] = pos[ aux ] ;

        aux = find ( hh2[ i ] ) ;
        if ( pos[ aux ] == 0 ) {
            pos[ aux ] = ++ id ;
        }
        ret.r[ i ] = pos[ aux ] ;
    }
    return ret ;
}

node ret ;

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = node ( IL ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] , mid + 1 ) ;
    }
    void query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            ret = merge ( ret , tr[ where ] , IL ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        query ( 2 * where , IL , mid , CURL , CURR ) ;
        query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
}

void solve ( ) {
    w.init ( 1 , 1 , m ) ;
    while ( q -- ) {
        int l , r ;
        scanf ( "%d%d" , &l , &r ) ;
        ret = node ( ) ;
        w.query ( 1 , 1 , m , l , r ) ;
        printf ( "%I64d\n" , ret.ans ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}