#include<bits/stdc++.h>
using namespace std ;

#define MAXN 1007

struct node {
    int val ;
    node *down , *right ;
    node ( ) {
        val = 0 ;
        down = right = NULL ;
    }
    node ( int _val ) {
        val = _val ;
        down = right = NULL ;
    }
};

node *root ;

int n , m , q ;
int a[ MAXN ][ MAXN ] ;

node *w[ MAXN ][ MAXN ] ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( int j = 1 ; j <= m ; ++ j ) {
            scanf ( "%d" , &a[ i ][ j ] ) ;
        }
    }
    for ( int i = 0 ; i <= n + 1 ; ++ i ) {
        for ( int j = 0 ; j <= m + 1 ; ++ j ) {
            w[ i ][ j ] = new node ( a[ i ][ j ] ) ;
        }
    }
    for ( int i = 0 ; i <= n + 1 ; ++ i ) {
        for ( int j = 0 ; j <= m + 1 ; ++ j ) {
            if ( i <= n ) {
                w[ i ][ j ]->down = w[ i + 1 ][ j ] ;
            }
            if ( j <= m ) {
                w[ i ][ j ]->right = w[ i ][ j + 1 ] ;
            }
        }
    }
    root = w[ 0 ][ 0 ] ;
}
vector < pair < node* , node* > > b_up ;
vector < pair < node* , node* > > b_left ;
vector < pair < node* , node* > > b_right ;
vector < pair < node* , node* > > b_down ;

pair < node* , node* > advance ( vector < pair < node* , node* > > &aux , node *h1 , node *h2 , int len , bool dir ) {
    for ( int i = 0 ; i < len ; ++ i ) {
        if ( dir == true ) {
            h1 = h1->right ;
            h2 = h2->right ;
        }
        else {
            h1 = h1->down ;
            h2 = h2->down ;
        }
        aux.push_back ( { h1 , h2 } ) ;
    }
    return { h1 , h2 } ;
}

void solve ( ) {
    int stx1 , sty1 , stx2 , sty2 , lenx , leny ;
    while ( q -- ) {
        scanf ( "%d%d%d%d%d%d" , &stx1 , &sty1 , &stx2 , &sty2 , &lenx , &leny ) ;
        node *aux1 , *aux2 ;
        aux1 = root ; aux2 = root ;
        for ( int i = 1 ; i < stx1 ; ++ i ) {
            aux1 = aux1->down ;
        }
        for ( int i = 1 ; i < sty1 ; ++ i ) {
            aux1 = aux1->right ;
        }
        for ( int i = 1 ; i < stx2 ; ++ i ) {
            aux2 = aux2->down ;
        }
        for ( int i = 1 ; i < sty2 ; ++ i ) {
            aux2 = aux2->right ;
        }

        b_up.clear ( ) ;
        pair < node* , node* > ret ;
        ret = advance ( b_up , aux1 , aux2 , leny , true ) ;

        b_right.clear ( ) ;
        advance ( b_right , ret.first , ret.second , lenx , false ) ;

        b_left.clear ( ) ;
        ret = advance ( b_left , aux1 , aux2 , lenx , false ) ;

        b_down.clear ( ) ;
        advance ( b_down , ret.first , ret.second , leny , true ) ;

        for ( int i = 0 ; i < leny ; ++ i ) {
            swap ( b_up[ i ].first->down , b_up[ i ].second->down ) ;
            swap ( b_down[ i ].first->down , b_down[ i ].second->down ) ;
        }
        for ( int i = 0 ; i < lenx ; ++ i ) {
            swap ( b_left[ i ].first->right , b_left[ i ].second->right ) ;
            swap ( b_right[ i ].first->right , b_right[ i ].second->right ) ;
        }
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        root = root->down ;
        node *aux = root ;
        for ( int j = 1 ; j <= m ; ++ j ) {
            aux = aux->right ;
            printf ( "%d " , aux->val ) ;
        }
        printf ( "\n" ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}