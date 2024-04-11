#include<bits/stdc++.h>
using namespace std ;

#define MAXN 500007

int n , q ;
string a ;

// pref/suff cons
// 0 -- <
// 1 -- >

// pref/suff mx
// pref 0 -- ...<<<<<<<>>>
// pref 1 -- ...>>>>>>><<
// suff 0 -- <<<>>>>>>>...
// suff 1 -- >>><<<<<<<...



struct node {
    int mx[ 2 ] ;
    int mxpref[ 2 ] ;
    int mxsuff[ 2 ] ;
    int len ;
    int prefcons[ 2 ] ;
    int suffcons[ 2 ] ;
    node ( ) {
        len = 0 ;
        for ( int i = 0 ; i < 2 ; ++ i ) {
            mx[ i ] = 0 ;
            mxpref[ i ] = 0 ;
            mxsuff[ i ] = 0 ;
            prefcons[ i ] = 0 ;
            suffcons[ i ] = 0 ;
        }
    }
};

node unite ( node p1 , node p2 ) {
    node ret = node ( ) ;
    ret.len = p1.len + p2.len ;
    for ( int i = 0 ; i < 2 ; ++ i ) {
        ret.prefcons[ i ] = p1.prefcons[ i ] + ( p1.prefcons[ i ] == p1.len ) * p2.prefcons[ i ] ;
        ret.suffcons[ i ] = p2.suffcons[ i ] + ( p2.suffcons[ i ] == p2.len ) * p1.suffcons[ i ] ;
    }
    for ( int i = 0 ; i < 2 ; ++ i ) {
        ret.mxpref[ i ] = p1.mxpref[ i ] + ( p1.mxpref[ i ] == p1.len ) * p2.prefcons[ i ^ 1 ] ;
        if ( p1.prefcons[ i ] == p1.len ) {
            ret.mxpref[ i ] = max ( ret.mxpref[ i ] , p2.mxpref[ i ] + p1.len ) ;
        }
        ret.mxsuff[ i ] = p2.mxsuff[ i ] + ( p2.mxsuff[ i ] == p2.len ) * p1.suffcons[ i ] ;
        if ( p2.suffcons[ i ^ 1 ] == p2.len ) {
            ret.mxsuff[ i ] = max ( ret.mxsuff[ i ] , p2.len + p1.mxsuff[ i ] ) ;
        }
    }
    for ( int i = 0 ; i < 2 ; ++ i ) {
        ret.mx[ i ] = max ( p1.mx[ i ] , p2.mx[ i ] ) ;
        ret.mx[ i ] = max ( ret.mx[ i ] , p1.mxsuff[ i ] + p2.prefcons[ i ^ 1 ] ) ;
        ret.mx[ i ] = max ( ret.mx[ i ] , p2.mxpref[ i ] + p1.suffcons[ i ] ) ;
        ret.mx[ i ] = max ( ret.mx[ i ] , ret.mxpref[ i ] ) ;
        ret.mx[ i ] = max ( ret.mx[ i ] , ret.mxsuff[ i ] ) ;        
    }
    return ret ;
}

node ans ;

class Tree {
public : 
    node tr[ 4 * MAXN ] ;
    bool lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == false ) { return ; }
        lazy[ where ] = false ;
        swap ( tr[ where ].mx[ 0 ] , tr[ where ].mx[ 1 ] ) ;
        swap ( tr[ where ].mxpref[ 0 ] , tr[ where ].mxpref[ 1 ] ) ;
        swap ( tr[ where ].mxsuff[ 0 ] , tr[ where ].mxsuff[ 1 ] ) ;
        
        swap ( tr[ where ].prefcons[ 0 ] , tr[ where ].prefcons[ 1 ] ) ;
        swap ( tr[ where ].suffcons[ 0 ] , tr[ where ].suffcons[ 1 ] ) ;
        if ( IL != IR ) {
            lazy[ 2 * where ] ^= 1 ;
            lazy[ 2 * where + 1 ] ^= 1 ;
        }
    }

    // pref/suff cons
    // 0 -- <
    // 1 -- >

    // pref/suff mx
    // pref 0 -- ...<<<<<<<>>>
    // pref 1 -- ...>>>>>>><<
    // suff 0 -- <<<>>>>>>>...
    // suff 1 -- >>><<<<<<<...
    
    void init ( int where , int IL , int IR ) {
        tr[ where ].len = ( IR - IL + 1 ) ;
        lazy[ where ] = false ;
        if ( IL == IR ) {
            tr[ where ].mx[ 0 ] = tr[ where ].mx[ 1 ] = 1 ;
            if ( a[ IL - 1 ] == '>' ) {
                tr[ where ].mxpref[ 1 ] = tr[ where ].mxsuff[ 0 ] = 1 ;
                tr[ where ].mxpref[ 0 ] = tr[ where ].mxsuff[ 1 ] = 1 ;

                tr[ where ].prefcons[ 0 ] = tr[ where ].suffcons[ 0 ] = 0 ;
                tr[ where ].prefcons[ 1 ] = tr[ where ].suffcons[ 1 ] = 1 ;
            }
            else if ( a[ IL - 1 ] == '<' ) {
                tr[ where ].mxpref[ 1 ] = tr[ where ].mxsuff[ 0 ] = 1 ;
                tr[ where ].mxpref[ 0 ] = tr[ where ].mxsuff[ 1 ] = 1 ;
                
                tr[ where ].prefcons[ 0 ] = tr[ where ].suffcons[ 0 ] = 1 ;
                tr[ where ].prefcons[ 1 ] = tr[ where ].suffcons[ 1 ] = 0 ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1  , mid + 1 , IR ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] = true ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void query ( int where , int IL , int IR , int CURL , int CURR ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            ans = unite ( ans , tr[ where ] ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        query ( 2 * where , IL , mid , CURL , CURR ) ;
        query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};
Tree w ;

void input ( ) {
    cin >> n >> q ;
    cin >> a ;
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    int l , r ;
    while ( q -- ) {
        cin >> l >> r ;
        w.update ( 1 , 1 , n , l , r ) ;
        ans = node ( ) ;
        w.query ( 1 , 1 , n , l , r ) ;
        /**
        for ( int i = 0 ; i < 2 ; ++ i ) {
            if ( ans.mx[ 1 ] < ans.prefcons[ i ] ) { ans.mx[ 1 ] = ans.prefcons[ i ] ; }
            if ( ans.mx[ 1 ] < ans.prefcons[ i ] ) { ans.mx[ 1 ] = ans.suffcons[ i ] ; }
        }
        **/
        cout << ans.mx[ 1 ] << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}