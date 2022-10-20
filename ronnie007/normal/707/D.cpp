#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<math.h>
#include<queue>
using namespace std ;

#define MAXN 100007
int n , m , q ;
vector < int > v[ MAXN ] ;
struct tuhla {
    int type ;
    int x , y ;
};

tuhla a[ MAXN ] ;

class Tree {
    public :
    int tr[ 3007 ] ;
    int lazy[ 3007 ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = lazy[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ] = ( IR - IL + 1 ) - tr[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] ^= 1 ;
            lazy[ 2 * where + 1 ] ^= 1 ;
        }
        lazy[ where ] = 0 ;
    }
    int update ( int where , int IL , int IR , int pos , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( IR < pos || pos < IL ) { return -1 ; }
        if ( IL == IR ) {
            int ret = tr[ where ] ;
            tr[ where ] = val ;
            return ret ;
        }
        int mid = ( IL + IR ) / 2 ;
        int ret = update ( 2 * where , IL , mid , pos , val ) ;
        ret = max ( ret , update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ) ;
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
        return ret ;
    }
};
Tree w[ 1007 ] ;
int tot = 0 ;
int ans[ MAXN ] ;

void dfs ( int vertex ) {
    int lstval = -1 ;
    if ( a[ vertex ].type != 4 ) {
        tot -= w[ a[ vertex ].x ].tr[ 1 ] ;
    }
    if ( a[ vertex ].type == 1 ) {
        lstval = w[ a[ vertex ].x ].update ( 1 , 1 , m , a[ vertex ].y , 1 ) ;
    }
    else if ( a[ vertex ].type == 2 ) {
        lstval = w[ a[ vertex ].x ].update ( 1 , 1 , m , a[ vertex ].y , 0 ) ;
    }
    else if ( a[ vertex ].type == 3 ) {
        w[ a[ vertex ].x ].lazy[ 1 ] ^= 1 ;
        w[ a[ vertex ].x ].push_lazy ( 1 , 1 , m ) ;
    }
    if ( a[ vertex ].type != 4 ) {
        tot += w[ a[ vertex ].x ].tr[ 1 ] ;
    }
    ans[ vertex ] = tot ;

    int i , sz ;
    sz = v[ vertex ].size ( ) ;
    for ( i = 0 ; i < sz ; i ++ ) {
        dfs ( v[ vertex ][ i ] ) ;
    }
    if ( a[ vertex ].type != 4 ) {
        tot -= w[ a[ vertex ].x ].tr[ 1 ] ;
    }
    if ( a[ vertex ].type == 1 ) {
        w[ a[ vertex ].x ].update ( 1 , 1 , m , a[ vertex ].y , lstval ) ;
    }
    else if ( a[ vertex ].type == 2 ) {
        w[ a[ vertex ].x ].update ( 1 , 1 , m , a[ vertex ].y , lstval ) ;
    }
    else if ( a[ vertex ].type == 3 ) {
        w[ a[ vertex ].x ].lazy[ 1 ] ^= 1 ;
        w[ a[ vertex ].x ].push_lazy ( 1 , 1 , m ) ;
    }
    if ( a[ vertex ].type != 4 ) {
        tot += w[ a[ vertex ].x ].tr[ 1 ] ;
    }
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &q ) ;
    int i ;
    for ( i = 1 ; i <= q ; i ++ ) {
        scanf ( "%d" , &a[ i ].type ) ;
        if ( a[ i ].type == 1 ) {
            scanf ( "%d%d" , &a[ i ].x , &a[ i ].y ) ;
            v[ i - 1 ].push_back ( i ) ;
        }
        else if ( a[ i ].type == 2 ) {
            scanf ( "%d%d" , &a[ i ].x , &a[ i ].y ) ;
            v[ i - 1 ].push_back ( i ) ;
        }
        else if ( a[ i ].type == 3 ) {
            scanf ( "%d" , &a[ i ].x ) ;
            v[ i - 1 ].push_back ( i ) ;
        }
        else {
            scanf ( "%d" , &a[ i ].x ) ;
            v[ a[ i ].x ].push_back ( i ) ;
        }
    }
}

void solve ( ) {
    int i ;
    w[ 0 ].init ( 1 , 1 , m ) ;
    for ( i = 1 ; i <= n ; i ++ ) {
        w[ i ].init ( 1 , 1 , m ) ;
    }
    dfs ( 0 ) ;
    for ( i = 1 ; i <= q ; i ++ ) {
        printf ( "%d\n" , ans[ i ] ) ;
    }
}

int main ( ) {
    ///ios::sync_with_stdio ( false ) ;
    ///cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}