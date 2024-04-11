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
#include<random>
using namespace std ;

#define MAXN 300007
#define inf 1000000007

int n ;
int st[ MAXN ] , en[ MAXN ] ;

mt19937 mt_rand ( time ( 0 ) ) ;

struct treap {
    treap *pl , *pr ;
    int val , prior ;
    int lazy ;
    int sz ;
    treap ( ) {
        this->pl = this->pr = NULL ;
        this->val = this->prior = 0 ;
        this->lazy = 0 ;
        this->sz = 0 ;
    }
    treap ( int _val ) {
        this->pl = this->pr = NULL ;
        this->prior = mt_rand ( ) ;
        this->val = _val ;
        this->lazy = 0 ;
        this->sz = 1 ;
    }
};

treap *root ;

int get_size ( treap *x ) {
    if ( x == NULL ) { return 0 ; }
    return x->sz ;
}
void update_sz ( treap *x ) {
    if ( x == NULL ) { return ; }
    x->sz = 1 + get_size ( x->pl ) + get_size ( x->pr ) ;
}

void push_lazy ( treap *x ) {
    if ( x == NULL ) { return ; }
    x->val += x->lazy ;
    if ( x->pl != NULL ) { x->pl->lazy += x->lazy ; }
    if ( x->pr != NULL ) { x->pr->lazy += x->lazy ; }
    x->lazy = 0 ;
}

void split ( treap *w , treap *(&l) , treap *(&r) , int sr ) {
    push_lazy ( w ) ;
    if ( w == NULL ) { l = NULL ; r = NULL ; return ; }
    if ( w->val <= sr ) {
        split ( w->pr , w->pr , r , sr ) ;
        l = w ;
        update_sz ( l ) ;
    }
    else {
        split ( w->pl , l , w->pl , sr ) ;
        r = w ;
        update_sz ( r ) ;
    }
}

void merge ( treap *(&w) , treap *l , treap *r ) {
    push_lazy ( l ) ;
    push_lazy ( r ) ;
    if ( l == NULL ) { w = r ; return ; }
    if ( r == NULL ) { w = l ; return ; }
    if ( l->prior >= r->prior ) {
        merge ( l->pr , l->pr , r ) ;
        w = l ;
        update_sz ( w ) ;
    }
    else {
        merge ( r->pl , l , r->pl ) ;
        w = r ;
        update_sz ( w ) ;
    }
}

int get_lst_id ( treap *w , int sr ) {
    push_lazy ( w ) ;
    if ( w == NULL ) { return 0 ; }
    if ( w->val > sr ) {
        return get_lst_id ( w->pl , sr ) ;
    }
    else {
        return max ( w->val , get_lst_id ( w->pr , sr ) ) ;
    }
}
int get_min_val ( treap *w ) {
    push_lazy ( w ) ;
    if ( w == NULL ) { return inf ; }
    return min ( w->val , get_min_val ( w->pl ) ) ;
}

void crop ( treap *(&x) ) {
    if ( x == NULL ) { return ; }
    int aux = get_min_val ( x ) ;
    treap *foo ;
    split ( x , foo , x , aux ) ;
}


void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &st[ i ] , &en[ i ] ) ;
    }
}

void solve ( ) {
    root = NULL ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int l = get_lst_id ( root , st[ i ] - 1 ) ;
        int r = get_lst_id ( root , en[ i ] - 1 ) ;
        treap *aux1 , *aux2 , *aux3 ;
        split ( root , aux1 , aux2 , l ) ;
        split ( aux2 , aux2 , aux3 , r ) ;
        if ( aux2 != NULL ) {
            aux2->lazy += 1 ;
            push_lazy ( aux2 ) ;
        }
        crop ( aux3 ) ;
        treap *add = new treap ( st[ i ] ) ;
        merge ( root , aux1 , add ) ;
        merge ( root , root , aux2 ) ;
        merge ( root , root , aux3 ) ;
    }
    printf ( "%d\n" , get_size ( root ) ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}