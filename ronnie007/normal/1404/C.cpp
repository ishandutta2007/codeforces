#include<bits/stdc++.h>
using namespace std ;

#define MAXN 300007
#define MAGIC 500

int n , q ;
int a[ MAXN ] ;

int diff[ MAXN ] ;
int pos[ MAXN ] ;

int ans[ MAXN ] ;

#define inf 1000000007
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
 
struct node {
    int val , br , prior ;
    node *pl , *pr ;
    node ( int x , int y ) {
        this->val = x ;
        this->prior = y ;
        this->br = 1 ;
        this->pl = this->pr = NULL ;
    }
};
 
int get_sz ( node *w ) {
    if ( w == NULL ) { return 0 ; }
    return ( w->br ) ;
}
 
 
void update ( node *arg ) {
    if ( arg == NULL ) { return ; }
    arg->br = 1 + get_sz ( arg->pl ) + get_sz ( arg->pr ) ;
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
    if ( l == NULL && r == NULL ) { w = NULL ; return ; }
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
 
 
long long getk ( node *w , int x ) {
    if ( w == NULL ) { return 0 ; }
    if ( get_sz ( w ) < x ) { return 0 ; }
    int aux = get_sz ( w->pr ) ;
    if ( x <= aux ) { return getk ( w->pr , x ) ; }
    else if ( x == aux + 1 ) { return w->val ; }
    else {
        return getk ( w->pl , x - aux - 1 ) ;
    }
}
 
node *root ;
 
void add ( int x ) {
    node *u1 , *u2 ;
    //u1 = u2 = NULL ;
    split ( root , u1 , u2 , x ) ;
    node *aux = new node ( x , rng ( ) ) ;
    merge ( u1 , u1 , aux ) ;
    update ( u1 ) ;
    merge ( root , u1 , u2 ) ;
    update ( root ) ;
}

class Tree {
public :
    vector < int > tr[ 4 * MAXN ] ;
    void merge ( int where ) {
        int l , r ;
        l = 2 * where ;
        r = 2 * where + 1 ;
        int sz1 = tr[ l ].size ( ) ;
        int sz2 = tr[ r ].size ( ) ;
        int hh1 = 0 ;
        int hh2 = 0 ;
        while ( hh1 < sz1 || hh2 < sz2 ) {
            if ( hh1 == sz1 ) {
                tr[ where ].push_back ( tr[ r ][ hh2 ++ ] ) ;
            }
            else if ( hh2 == sz2 ) {
                tr[ where ].push_back ( tr[ l ][ hh1 ++ ] ) ;
            }
            else {
                if ( tr[ l ][ hh1 ] < tr[ r ][ hh2 ] ) {
                    tr[ where ].push_back ( tr[ l ][ hh1 ++ ] ) ;
                }
                else {
                    tr[ where ].push_back ( tr[ r ][ hh2 ++ ] ) ;
                }
            }
        }
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ].clear ( ) ;
        if ( IL == IR ) {
            tr[ where ].push_back ( pos[ IL ] ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        merge ( where ) ;
    }
    int bin ( int where , int sr ) {
        int sz = tr[ where ].size ( ) ;
        int l , r ;
        l = 0 ;
        r = sz - 1 ;
        if ( tr[ where ][ r ] < sr ) { return 0 ; }
        if ( tr[ where ][ l ] >= sr ) { return sz ; }
        while ( r - l > 3 ) {
            int mid = ( l + r ) / 2 ;
            if ( tr[ where ][ mid ] >= sr ) { r = mid ; }
            else { l = mid ; }
        }
        while ( tr[ where ][ r ] >= sr ) { -- r ; }
        return sz - r - 1 ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR , int sr ) {
        if ( CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return bin ( where , sr ) ;
        }
        int mid = ( IL + IR ) / 2 ;
        return query ( 2 * where , IL , mid , CURL , CURR , sr ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , sr ) ;
    }
};
Tree w ;


void input ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
        diff[ i ] = i - a[ i ] ;
    }
}

void solve ( ) {
    root = NULL ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( diff[ i ] < 0 ) { continue ; }
        if ( diff[ i ] == 0 ) {
            pos[ i ] = i ;
        }
        else {
            pos[ i ] = getk ( root , diff[ i ] ) ;
        }
        add ( pos[ i ] ) ;
    }
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        int l , r ;
        cin >> l >> r ;
        cout << w.query ( 1 , 1 , n , l + 1 , n - r , l + 1 ) << "\n" ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}