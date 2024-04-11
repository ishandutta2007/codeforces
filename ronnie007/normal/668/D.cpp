#include<iostream>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cstdlib>
using namespace std ;


#define MAXN 100007

int n ;
struct query {
    int type ;
    int x , y ;
};
query a[ MAXN ] ;

map < int , int > ZX ;


struct node {
    int val ;
    int prior ;
    int br ;
    int sm ;
    int p ;
    node *pl , *pr ;
    node ( ) {
        this->val = this->prior = this->br = 0 ;
        this->pl = this->pr = NULL ;
    }
    node ( int x , int y ) {
        this->val = x ;
        this->prior = rand ( ) ;
        this->br = 1 ;
        this->sm = this->p = y ;
        this->pl = this->pr = NULL ;
    }
};

class Treap {
    private :
    node *root ;
    int get_sz ( node *w ) {
        if ( w == NULL ) { return 0 ; }
        return ( w->br ) ;
    }
    int get_sm ( node *w ) {
        if ( w == NULL ) { return 0 ; }
        return ( w->sm ) ;
    }
    void update ( node *w ) {
        if ( w == NULL ) { return ; }
        w->br = 1 + get_sz ( w->pl ) + get_sz ( w->pr ) ;
        w->sm = w->p + get_sm ( w->pl ) + get_sm ( w->pr ) ;
    }
    void split ( node *w , node * &l , node * &r , int sr ) {
        if ( w == NULL ) { l = r = NULL ; return ; }
        if ( w->val <= sr ) {
            split ( w->pr , w->pr , r , sr ) ;
            l = w ;
            update ( l ) ;
        }
        else {
            split ( w->pl , l , w->pl , sr ) ;
            r = w ;
            update ( r ) ;
        }
    }
    void merge ( node * &w , node *l , node *r ) {
        if ( l == NULL ) { w = r ; return ; }
        if ( r == NULL ) { w = l ; return ; }
        if ( l->prior > r->prior ) {
            merge ( l->pr , l->pr , r ) ;
            w = l ;
            update ( w ) ;
        }
        else {
            merge ( r->pl , l , r->pl ) ;
            w = r ;
            update ( w ) ;
        }
    }
    int get_ans ( node *w , int sr ) {
        if ( w == NULL ) { return 0 ; }
        if ( w->val <= sr ) {
            return get_sm ( w->pl ) + w->p + get_ans ( w->pr , sr ) ;
        }
        else {
            return get_ans ( w->pl , sr ) ;
        }
    }
    public:
    void set ( ) {
        root = NULL ;
    }
    void add ( int val , int type ) {
        node *u1 , *u2 ;
        split ( root , u1 , u2 , val ) ;
        node* nw = new node ( val , type ) ;
        merge ( root , u1 , nw ) ;
        merge ( root , root , u2 ) ;
    }
    int calc ( int val ) {
        return get_ans ( root , val ) ;
    }
};

Treap T[ MAXN ] ;

void init ( ) {
    vector < int > srt ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        srt.push_back ( a[ i ].x ) ;
    }
    sort ( srt.begin ( ) , srt.end ( ) ) ;
    ZX[ srt[ 0 ] ] = 1 ;
    int id = 1 ;
    for ( i = 1 ; i < n ; i ++ ) {
        if ( srt[ i ] == srt[ i - 1 ] ) { continue ; }
        id ++ ;
        ZX[ srt[ i ] ] = id ;
    }
    for ( i = 1 ; i <= n ; i ++ ) {
        a[ i ].x = ZX[ a[ i ].x ] ;
    }
    for ( i = 1 ; i <= id ; i ++ ) {
        T[ i ].set ( ) ;
    }
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%d%d%d" , &a[ i ].type , &a[ i ].y , &a[ i ].x ) ;
    }
    init ( ) ;
}

void solve ( ) {
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        if ( a[ i ].type == 1 ) {
            T[ a[ i ].x ].add ( a[ i ].y , 1 ) ;
        }
        else if ( a[ i ].type == 2 ) {
            T[ a[ i ].x ].add ( a[ i ].y , -1 ) ;
        }
        else {
            printf ( "%d\n" , T[ a[ i ].x ].calc( a[ i ].y ) ) ;
        }
    }
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}