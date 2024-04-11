#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
#include<stack>
using namespace std ;

#define MAXN 1000007

int n ;
int type[ MAXN ] ;
int f1[ MAXN ] ;
int f2[ MAXN ] ;
int val[ MAXN ] ;
int nxt[ MAXN ] ;

int final_ans[ MAXN ] ;


vector < int > leaves ;

int par[ MAXN ] ;

int vis[ MAXN ][ 2 ] ;
bool hh[ MAXN ] ;
int init_val[ MAXN ] ;

int find ( int x ) {
    if ( par[ x ] == -1 ) { return x ; }
    int y = find ( par[ x ] ) ;
    par[ x ] = y ;
    return y ;
}

void UNITE ( int x , int y ) {
    int k1 = find ( x ) ;
    int k2 = find ( y ) ;
    par[ k1 ] = k2 ;
}

struct tuhla {
    int vertex ;
    int col ;
    int id ;
    tuhla ( ) { vertex = col = id = 0 ; }
    tuhla ( int _vertex , int _col , int _id ) {
        vertex = _vertex ;
        col = _col ;
        id = _id ;
    }
};

void dfs ( int vertex ) {
    if ( type[ vertex ] == 0 ) { init_val[ vertex ] = val[ vertex ] ; }
    else if ( type[ vertex ] == 1 ) {
        dfs ( val[ vertex ] ) ;
        init_val[ vertex ] = (init_val[ val[ vertex ] ]^1) ;
    }
    else {
        dfs ( f1[ vertex ] ) ;
        dfs ( f2[ vertex ] ) ;
        int p1 = init_val[ f1[ vertex ] ] ;
        int p2 = init_val[ f2[ vertex ] ] ;
        if ( type[ vertex ] == 2 ) { init_val[ vertex ] = ( p1 & p2 ) ; }
        if ( type[ vertex ] == 3 ) { init_val[ vertex ] = ( p1 | p2 ) ; }
        if ( type[ vertex ] == 4 ) { init_val[ vertex ] = ( p1 ^ p2 ) ; }
    }
}


void input ( ) {
    cin >> n ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        string str ;
        cin >> str ;
        if ( str == "IN" ) {
            type[ i ] = 0 ;
            cin >> val[ i ] ;
            leaves.push_back ( i ) ;
        }
        else if ( str == "NOT" ) {
            type[ i ] = 1 ;
            cin >> val[ i ] ;
            nxt[ val[ i ] ] = i ;
        }
        else {
            if ( str == "AND" ) { type[ i ] = 2 ; }
            if ( str == "OR" ) { type[ i ] = 3 ; }
            if ( str == "XOR" ) { type[ i ] = 4 ; }
            cin >> f1[ i ] >> f2[ i ] ;
            nxt[ f1[ i ] ] = nxt[ f2[ i ] ] = i ;
        }
    }
}

void solve ( ) {
    dfs ( 1 ) ;
    queue < tuhla > q ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        hh[ i ] = false ;
        par[ i ] = -1 ;
    }
    int sz = leaves.size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        q.push ( tuhla ( leaves[ i ] , (val[ leaves[ i ] ]^1) , leaves[ i ] ) ) ;
    }
    while ( q.empty ( ) == false ) {
        tuhla u = q.front ( ) ;
        q.pop ( ) ;
        tuhla nw ;
        nw.id = u.id ;
        if ( nxt[ u.vertex ] != 0 ) {
            nw.vertex = nxt[ u.vertex ] ;
            if ( type[ nxt[ u.vertex ] ] == 1 ) {
                nw.col = ( u.col ^ 1 ) ;
            }
            else {
                int p1 , p2 ;
                if ( f1[ nxt[ u.vertex ] ] == u.vertex ) { p1 = u.col ; }
                else { p1 = init_val[ f1[ nxt[ u.vertex ] ] ] ; }

                if ( f2[ nxt[ u.vertex ] ] == u.vertex ) { p2 = u.col ; }
                else { p2 = init_val[ f2[ nxt[ u.vertex ] ] ] ; }
                if ( type[ nxt[ u.vertex ] ] == 2 ) { nw.col = ( p1 & p2 ) ; }
                if ( type[ nxt[ u.vertex ] ] == 3 ) { nw.col = ( p1 | p2 ) ; }
                if ( type[ nxt[ u.vertex ] ] == 4 ) { nw.col = ( p1 ^ p2 ) ; }
            }
            if ( vis[ nw.vertex ][ nw.col ] == 0 ) {
                vis[ nw.vertex ][ nw.col ] = nw.id ;
                q.push ( nw ) ;
            }
            else {
                par[ u.id ] = vis[ nw.vertex ][ nw.col ] ;
            }
        }
        else {
            if ( u.vertex == 1 ) { final_ans[ u.id ] = u.col ; }
            else { final_ans[ u.id ] = init_val[ 1 ] ; }
        }
    }
    for ( i = 0 ; i < sz ; i ++ ) {
        cout << final_ans[ find ( leaves[ i ] ) ] ;
    }
    cout << "\n" ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}