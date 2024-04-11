#include<bits/stdc++.h>
using namespace std ;

struct node {
    int cnt ;
    node *to[ 2 ] ;
    node ( ) {
        cnt = 0 ;
        to[ 0 ] = to[ 1 ] = NULL ;
    }
};

node *root ;

void add ( node *where , int lvl , int x ) {
    if ( lvl == -1 ) {
        ++ where->cnt ;
        return ;
    }
    int id = ( x & ( 1 << lvl ) ) > 0 ;
    if ( where->to[ id ] == NULL ) {
        where->to[ id ] = new node ( ) ;
    }
    add ( where->to[ id ] , lvl - 1 , x ) ;
    if ( where->to[ 0 ] == NULL ) { where->cnt = where->to[ 1 ]->cnt ; }
    else if ( where->to[ 1 ] == NULL ) { where->cnt = where->to[ 0 ]->cnt ; }
    else {
        where->cnt = max ( where->to[ 0 ]->cnt , where->to[ 1 ]->cnt ) + 1 ;
    }
}

void input ( ) {
    root = new node ( ) ;
}

void solve ( ) {
    int n ;
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x ;
        scanf ( "%d" , &x ) ;
        add ( root , 30 , x ) ;
    }
    printf ( "%d\n" , n - root->cnt ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    /// cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}