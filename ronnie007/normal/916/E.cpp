#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007
#define LOG 18

int n , q ;
int a[ MAXN ] ;
vector < int > v[ MAXN ] ;

int lvl[ MAXN ] ;
int LCA[ MAXN ][ LOG ] ;
int tpsz ;
int st[ MAXN ] ;
int en[ MAXN ] ;
int ord[ MAXN ] ;

class Tree {
public :
    long long tr[ 4 * MAXN ] ;
    long long lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ] += lazy[ where ] * ( IR - IL + 1 ) ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void unite ( int where ) {
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = 0 ;
        if ( IL == IR ) {
            tr[ where ] = a[ ord[ IL ] ] ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR || IL > IR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        unite ( where ) ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR || IL > IR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};

Tree w ;

void dfs ( int vertex , int prv ) {
    st[ vertex ] = ++ tpsz ;
    ord[ tpsz ] = vertex ;
    if ( prv > -1 ) {
        for ( int i = 1 ; i < LOG ; ++ i ) {
            LCA[ vertex ][ i ] = LCA[ LCA[ vertex ][ i - 1 ] ][ i - 1 ] ;
        }
    }
    for ( auto x : v[ vertex ] ) {
        if ( x == prv ) { continue ; }
        lvl[ x ] = lvl[ vertex ] + 1 ;
        LCA[ x ][ 0 ] = vertex ;
        dfs ( x , vertex ) ;
    }
    en[ vertex ] = tpsz ;
}

int get_LCA ( int x , int y ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( lvl[ x ] - ( 1 << i ) >= lvl[ y ] ) {
            x = LCA[ x ][ i ] ;
        }
        if ( lvl[ y ] - ( 1 << i ) >= lvl[ x ] ) {
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

int jump ( int x , int len ) {
    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
        if ( len >= ( 1 << i ) ) {
            x = LCA[ x ][ i ] ;
            len -= ( 1 << i ) ;
        }
    }
    return x ;
}

bool contains ( int x , int y ) {
    return ( st[ x ] <= st[ y ] && en[ y ] <= en[ x ] ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i < n ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ x ].push_back ( y ) ;
        v[ y ].push_back ( x ) ;
    }
    dfs ( 1 , -1 ) ;
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    int type ;
    int h1 , h2 , x ;
    int root = 1 ;
    while ( q -- ) {
        scanf ( "%d" , &type ) ;
        if ( type == 1 ) {
            scanf ( "%d" , &root ) ;
        }
        else if ( type == 2 ) {
            scanf ( "%d%d%d" , &h1 , &h2 , &x ) ;
            int aux = get_LCA ( h1 , h2 ) ;
            if ( contains ( root , aux ) == true ) {
                if ( aux != root ) { 
                    w.update ( 1 , 1 , n , st[ aux ] , en[ aux ] , x ) ;
                }
                else {
                    w.update ( 1 , 1 , n , 1 , n , x ) ;
                }
            }
            else {
                if ( contains ( root , h1 ) == true || contains ( root , h2 ) == true ) {
                    w.update ( 1 , 1 , n , 1 , n , x ) ;
                }
                else {
                    int dummy = root ;
                    for ( int i = LOG - 1 ; i >= 0 ; -- i ) {
                        if ( lvl[ dummy ] >= ( 1 << i ) ) {
                            if ( contains ( LCA[ dummy ][ i ] , h1 ) == false &&
                                 contains ( LCA[ dummy ][ i ] , h2 ) == false ) {
                                dummy = LCA[ dummy ][ i ] ;
                            }
                        }
                    }
                    int cand = LCA[ dummy ][ 0 ] ;
                    if ( contains ( cand , aux ) == true && cand != aux ) {
                        w.update ( 1 , 1 , n , st[ aux ] , en[ aux ] , x ) ;
                    }
                    else {
                        w.update ( 1 , 1 , n , 1 , st[ dummy ] - 1 , x ) ;
                        w.update ( 1 , 1 , n , en[ dummy ] + 1 , n , x ) ;
                    }
                }
            }
        }
        else {
            scanf ( "%d" , &x ) ;
            if ( x == root ) {
                printf ( "%lld\n" , w.query ( 1 , 1 , n , 1 , n ) ) ;
            }
            else { 
                if ( contains ( root , x ) == true ) {
                    printf ( "%lld\n" , w.query ( 1 , 1 , n , st[ x ] , en[ x ] ) ) ;
                }
                else {
                    if ( contains ( x , root ) == false ) {
                        printf ( "%lld\n" , w.query ( 1 , 1 , n , st[ x ] , en[ x ] ) ) ;
                    }
                    else {
                        int aux = jump ( root , lvl[ root ] - lvl[ x ] - 1 ) ;
                        printf ( "%lld\n" , w.query ( 1 , 1 , n , 1 , n ) - w.query ( 1 , 1 , n , st[ aux ] , en[ aux ] ) ) ;
                    }
                }
            }
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