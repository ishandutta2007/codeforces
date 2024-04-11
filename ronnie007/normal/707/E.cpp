#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 2007

int n , m , k ;
struct tuhla {
    int x , y ;
    int cost ;
    tuhla ( ) { x = y = cost = 0 ; }
    tuhla ( int _x , int _y , int _cost ) {
        x = _x ;
        y = _y ;
        cost = _cost ;
    }
};
vector < tuhla > v[ MAXN ] ;

vector < long long > pref[ MAXN ] ;
pair < int , int > id[ MAXN ][ MAXN ] ;

int used[ MAXN ] ;

char cm[ 7 ] ;

int stx , sty , enx , eny ;

vector < int > p[ MAXN ] ;

bool check ( tuhla u ) {
    if ( stx <= u.x && u.x <= enx && sty <= u.y && u.y <= eny ) { return true ; }
    return false ;
}

long long calc ( ) {
    int i , j ;
    vector < pair < int , int > > aux ;
    for ( i = 1 ; i <= k ; i ++ ) {
        p[ i ].clear ( ) ;
    }
    for ( i = stx - 1 ; i <= enx + 1 ; i ++ ) {
        aux.push_back ( make_pair ( i , sty - 1 ) ) ;
        aux.push_back ( make_pair ( i , eny + 1 ) ) ;
    }
    for ( i = sty ; i <= eny ; i ++ ) {
        aux.push_back ( make_pair ( stx - 1 , i ) ) ;
        aux.push_back ( make_pair ( enx + 1 , i ) ) ;
    }
    int sz = aux.size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        pair < int , int > h = id[ aux[ i ].first ][ aux[ i ].second ] ;
        p[ h.first ].push_back ( h.second + 1 ) ;
    }
    long long ret = 0 ;
    for ( i = 1 ; i <= k ; i ++ ) {
        if ( used[ i ] == 0 ) { continue ; }
        sort ( p[ i ].begin ( ) , p[ i ].end ( ) ) ;
        sz = p[ i ].size ( ) ;
        if ( sz == 0 ) {
            if ( check ( v[ i ][ 0 ] ) == true ) {
                ret += pref[ i ][ v[ i ].size ( ) ] ;
            }
            continue ;
        }
        int lst = 0 ;
        for ( j = 0 ; j < sz ; j ++ ) {
            if ( check ( v[ i ][ lst ] ) == true ) {
                ret += pref[ i ][ p[ i ][ j ] - 1 ] - pref[ i ][ lst ] ;
            }
            lst = p[ i ][ j ] ;
        }
        if ( lst < v[ i ].size ( ) && check ( v[ i ][ lst ] ) == true ) {
            ret += pref[ i ][ v[ i ].size ( ) ] - pref[ i ][ lst ] ;
        }
    }
    return ret ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &k ) ;
    int i , j ;
    for ( i = 1 ; i <= k ; i ++ ) {
        int sz ;
        scanf ( "%d" , &sz ) ;
        pref[ i ].push_back ( 0 ) ;
        for ( j = 0 ; j < sz ; j ++ ) {
            int x , y , cost ;
            scanf ( "%d%d%d" , &x , &y , &cost ) ;
            v[ i ].push_back ( tuhla ( x , y , cost ) ) ;
            pref[ i ].push_back ( pref[ i ][ j ] + cost ) ;
            id[ x ][ y ] = make_pair ( i , j ) ;
        }
        used[ i ] = 1 ;
    }
}

void solve ( ) {
    int q ;
    scanf ( "%d\n" , &q ) ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "%s" , &cm ) ;
        if ( cm[ 0 ] == 'S' ) {
            int x ;
            scanf ( "%d" , &x ) ;
            used[ x ] ^= 1 ;
        }
        else {
            scanf ( "%d%d%d%d" , &stx , &sty , &enx , &eny ) ;
            printf ( "%I64d\n" , calc ( ) ) ;
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