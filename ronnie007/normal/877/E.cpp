#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std ;

#define MAXN 200007

int n ;
vector < int > v[ MAXN ] ;
int p[ MAXN ] ;

vector < int > ord ;
int st[ MAXN ] ;
int en[ MAXN ] ;


class Tree {
    public :
    int br0[ 5 * MAXN ] ;
    int br1[ 5 * MAXN ] ;
    int lazy[ 5 * MAXN ] ;
    void combine ( int where ) {
        br0[ where ] = br0[ 2 * where ] + br0[ 2 * where + 1 ] ;
        br1[ where ] = br1[ 2 * where ] + br1[ 2 * where + 1 ] ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        swap ( br0[ where ] , br1[ where ] ) ;
        if ( IL != IR ) {
            lazy[ 2 * where ] ^= lazy[ where ] ;
            lazy[ 2 * where + 1 ] ^= lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void init ( int where , int IL , int IR ) {
        lazy[ where ] = 0 ;
        if ( IL == IR ) {
            int id = ord[ IL - 1 ] ;
            br0[ where ] = br1[ where ] = 0 ;
            if ( p[ id ] == 0 ) { br0[ where ] ++ ; }
            else { br1[ where ] ++ ;}
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        combine ( where ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] ^= 1 ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        combine ( where ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return br1[ where ] ;
        }
        int mid = ( IL + IR ) / 2 ;
        return ( query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void dfs ( int vertex , int prv ) {
    ord.push_back ( vertex ) ;
    st[ vertex ] = ord.size ( ) ;
    int sz = v[ vertex ].size ( ) ;
    int i ;
    for ( i = 0 ; i < sz ; i ++ ) {
        if ( v[ vertex ][ i ] == prv ) { continue ; }
        dfs ( v[ vertex ][ i ] , vertex ) ;
    }
    en[ vertex ] = ord.size ( ) ;
}

void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 2 ; i <= n ; i ++ ) {
        int x ;
        cin >> x ;
        v[ x ].push_back ( i ) ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        cin >> p[ i ] ;
    }
}

void solve ( ) {
    dfs ( 1 , -1 ) ;
    w.init ( 1 , 1 , n ) ;
    int q ;
    cin >> q ;
    string x ;
    int y ;
    while ( q != 0 ) {
        q -- ;
        cin >> x >> y ;
        if ( x == "pow" ) {
            w.update ( 1 , 1 , n , st[ y ] , en[ y ] ) ;
        }
        else {
            cout << w.query ( 1 , 1 , n , st[ y ] , en[ y ] ) << "\n" ;
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