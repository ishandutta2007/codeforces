#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<string>
#include<map>
#include<queue>
#include<stack>
#include<iomanip>
#include<set>
using namespace std ;

#define MAXN 1000007

struct node {
    int sm ;
    int mxsuff ;
    node ( ) { sm = mxsuff = 0 ; }
    node ( int _sm ) { sm = _sm ; mxsuff = ( sm > 0 ) ? sm : 0 ; }
};

node merge ( node p1 , node p2 ) {
    node ret = node ( 0 ) ;
    ret.sm = ( p1.sm + p2.sm ) ;
    ret.mxsuff = p2.mxsuff ;
    if ( ret.mxsuff < p2.sm + p1.mxsuff ) {
        ret.mxsuff = p2.sm + p1.mxsuff ;
    }
    return ret ;
}

node aux ;

class Tree {
    public :
    node tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = node ( 0 ) ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }

    void update ( int where , int IL , int IR , int pos , int add ) {
        if ( pos < IL ) { return ; }
        if ( IR < pos ) { return ; }
        if ( IL == IR ) {
            tr[ where ].sm += add ;
            tr[ where ].mxsuff = ( tr[ where ].sm > 0 ) ? tr[ where ].sm : 0 ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , add ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , add ) ;
        }
        tr[ where ] = merge ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            if ( tr[ where ].mxsuff + aux.sm > 0 ) {
                return IL ;
            }
            else { return -1 ; }
        }
        node rem = aux ;
        aux = merge ( tr[ 2 * where + 1 ] , aux ) ;
        int mid = ( IL + IR ) / 2 ;
        if ( aux.mxsuff <= 0 ) {
            return query ( 2 * where , IL , mid ) ;
        }
        else {
            aux = rem ;
            return query ( 2 * where + 1 , mid + 1 , IR ) ;
        }
    }
};

Tree w ;
int n , m ;
int a[ MAXN ] ;
int b[ MAXN ] ;
#define lim 1000000

void input ( ) {
    w.init ( 1 , 1 , lim ) ;
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
        w.update ( 1 , 1 , lim , a[ i ] , 1 ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d" , &b[ i ] ) ;
        w.update ( 1 , 1 , lim , b[ i ] , -1 ) ;
    }
}

void solve ( ) {
    int q ;
    scanf ( "%d" , &q ) ;
    while ( q != 0 ) {
        -- q ;
        int type , x , y ;
        scanf ( "%d%d%d" , &type , &x , &y ) ;
        if ( type == 1 ) {
            w.update ( 1 , 1 , lim , a[ x ] , -1 ) ;
            a[ x ] = y ;
            w.update ( 1 , 1 , lim , a[ x ] , 1 ) ;
        }
        else {
            w.update ( 1 , 1 , lim , b[ x ] , 1 ) ;
            b[ x ] = y ;
            w.update ( 1 , 1 , lim , b[ x ] , -1 ) ;
        }
        aux = node ( 0 ) ;
        printf ( "%d\n" , w.query ( 1 , 1 , lim ) ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}