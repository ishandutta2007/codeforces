#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , q ;
string a ;

int pat[ 4 ] = { 2 , 0 , 1 , 7 } ;

struct node {
    int f[ 5 ][ 5 ] ;
    node ( ) {
        for ( int i = 0 ; i < 5 ; ++ i ) {
            for ( int j = 0 ; j < 5 ; ++ j ) {
                if ( i != j ) {
                    f[ i ][ j ] = MAXN ;
                }
                else {
                    f[ i ][ j ] = 0 ;
                }
            }
        }
    }
};

node unite ( node p1 , node p2 ) {
    node ret ;
    for ( int i = 0 ; i < 5 ; ++ i ) {
        for ( int j = i ; j < 5 ; ++ j ) {
            ret.f[ i ][ j ] = MAXN ;
            for ( int t = i ; t <= j ; ++ t ) {
                ret.f[ i ][ j ] = min ( ret.f[ i ][ j ] , p1.f[ i ][ t ] + p2.f[ t ][ j ] ) ;
            }
        }
    }
    return ret ;
}

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            for ( int i = 0 ; i < 5 ; ++ i ) {
                for ( int j = 0 ; j < 5 ; ++ j ) {
                    tr[ where ].f[ i ][ j ] = MAXN ;
                    if ( i == j ) {
                        if ( i >= 3 && a[ IL - 1 ] == '6' ) {
                            tr[ where ].f[ i ][ j ] = 1 ; 
                        }
                        else {
                            if ( a[ IL - 1 ] - '0' == pat[ i ] ) {
                                tr[ where ].f[ i ][ j ] = 1 ;
                            }
                            else {
                                tr[ where ].f[ i ][ j ] = 0 ;
                            }
                        }
                    }
                    if ( j == i + 1 && a[ IL - 1 ] - '0' == pat[ i ] ) {
                        tr[ where ].f[ i ][ j ] = 0 ;
                    }
                }
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return node ( ) ; }
        if ( CURR < IL || IR < CURL ) { return node ( ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return unite ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    cin >> n >> q ;
    cin >> a ;
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    while ( q -- ) {
        int l , r ;
        cin >> l >> r ;
        node ret = w.query ( 1 , 1 , n , l , r ) ;
        if ( ret.f[ 0 ][ 4 ] >= MAXN ) { cout << "-1\n" ; }
        else { cout << ret.f[ 0 ][ 4 ] << "\n" ; }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}