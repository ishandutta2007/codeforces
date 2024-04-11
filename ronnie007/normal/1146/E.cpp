#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cmath>
#include<map>
#include<stack>
#include<set>
#include<queue>
#include<cstdlib>
using namespace std ;

#define MAXN 200007
#define OFFSET 100000

int n , q ;
int a[ MAXN ] ;

struct node {
    int lo , hi ;
    int lazy ;
};

class Tree {
    public :
    node tr[ 10 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ].lo = ( IL - OFFSET ) ;
        tr[ where ].hi = ( IR - OFFSET ) ;
        tr[ where ].lazy = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        unite ( where , IL , IR ) ;
    }
    void push_lazy ( int where , int IL , int IR ) {
        swap ( tr[ where ].lo , tr[ where ].hi ) ;
        tr[ where ].lo *= -1 ;
        tr[ where ].hi *= -1 ;
        if ( IL != IR ) {
            tr[ 2 * where ].lazy ^= 1 ;
            tr[ 2 * where + 1 ].lazy ^= 1 ;
        }
        tr[ where ].lazy = 0 ;
    }
    void unite ( int where , int IL , int IR ) {
        tr[ where ].lo = min ( tr[ 2 * where ].lo , tr[ 2 * where + 1 ].lo ) ;
        tr[ where ].hi = max ( tr[ 2 * where ].hi , tr[ 2 * where + 1 ].hi ) ;
    }
    void update ( int where , int IL , int IR , int sr , bool bigger ) {
        if ( tr[ where ].lazy == true ) {
            push_lazy ( where , IL , IR ) ;
        }
        if ( bigger == true && tr[ where ].hi <= sr ) { return ; }
        if ( bigger == false && tr[ where ].lo >= sr ) { return ; }
        if ( bigger == true && sr < tr[ where ].lo ) {
            tr[ where ].lazy ^= 1 ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        if ( bigger == false && sr > tr[ where ].hi ) {
            tr[ where ].lazy ^= 1 ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , sr , bigger ) ;
        update ( 2 * where + 1 , mid + 1 , IR , sr , bigger ) ;
        unite ( where , IL , IR ) ;
    }
    int query ( int where , int IL , int IR , int pos ) {
        if ( tr[ where ].lazy == true ) {
            push_lazy ( where , IL , IR ) ;
        }
        if ( IL == IR ) {
            return tr[ where ].lo ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) { return query ( 2 * where , IL , mid , pos ) ; }
        else { return query ( 2 * where + 1 , mid + 1 , IR , pos ) ; }
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 0 , 2 * OFFSET ) ;
    char c ;
    int x ;
    int i ;
    while ( q != 0 ) {
        q -- ;
        scanf ( "\n%c%d" , &c , &x ) ;
        if ( c == '>' ) {
            w.update ( 1 , 0 , 2 * OFFSET , x , true ) ;
        }
        else {
            w.update ( 1 , 0 , 2 * OFFSET , x , false ) ;
        }
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        printf ( "%d" , w.query ( 1 , 0 , 2 * OFFSET , a[ i ] + OFFSET ) ) ;
        if ( i == n ) { printf ( "\n" ) ; }
        else { printf ( " " ) ; }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}