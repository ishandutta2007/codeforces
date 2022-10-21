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

#define MAXN 100007
#define eps 0.0000000000001

int n , mx ;
pair < long long , long long > a[ MAXN ] ;
pair < long double , long double > f[ MAXN ] ;


struct treap {
    long double val ;
    int prior ;
    int cnt ;
    treap *pl , *pr ;
    treap ( ) {
        this->val = this->prior = this->cnt = 0 ;
        this->pl = this->pr = NULL ;
    }
    treap ( long double _val ) {
        this->val = _val ;
        this->cnt = 1 ;
        this->prior = rand ( ) ;
        this->pl = this->pr = NULL ;
    }
};
treap* root ;
treap* emp ;

int get_size ( treap *w ) {
    if ( w == NULL ) { return 0 ; }
    return w->cnt ;
}

void update ( treap* w ) {
    if ( w == NULL ) { return ; }
    w->cnt = 1 + get_size ( w->pl ) + get_size ( w->pr ) ;
}

pair < treap* , treap* > split ( treap* w , long double sr ) {
    if ( w == NULL ) { return make_pair ( emp , emp ) ; }
    if ( w->val < sr - eps ) {
        pair < treap* , treap* > ret = split ( w->pr , sr ) ;
        w->pr = ret.first ;
        update ( w ) ;
        return make_pair ( w , ret.second ) ;
    }
    else {
        pair < treap* , treap* > ret = split ( w->pl , sr ) ;
        w->pl = ret.second ;
        update ( w ) ;
        return make_pair ( ret.first , w ) ;
    }
}

treap* merge ( treap* p1 , treap* p2 ) {
    if ( p1 == NULL ) { return p2 ; }
    if ( p2 == NULL ) { return p1 ; }
    if ( p1->prior >= p2->prior ) {
        treap* ret = merge ( p1->pr , p2 ) ;
        p1->pr = ret ;
        update ( p1 ) ;
        return p1 ;
    }
    else {
        treap* ret = merge ( p1 , p2->pl ) ;
        p2->pl = ret ;
        update ( p2 ) ;
        return p2 ;
    }
}

int query ( treap *w , long double sr ) {
    if ( w == NULL ) { return 0 ; }
    if ( w->val > sr ) {
        return query ( w->pl , sr ) ;
    }
    else {
        return ( get_size ( w->pl ) + 1 + query ( w->pr , sr ) ) ;
    }
}

void add_val ( long double nw ) {
    treap* aux = new treap ( nw ) ;
    pair < treap* , treap* > ret = split ( root , nw ) ;
    root = merge ( ret.first , aux ) ;
    root = merge ( root , ret.second ) ;
}

bool cmp ( pair < long double , long double > p1 , pair < long double , long double > p2 ) {
    long double aux = p1.first - p2.first ;
    if ( aux > -eps && aux < eps ) { return ( p1.second > p2.second ) ; }
    return ( p1.first < p2.first ) ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &mx ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        scanf ( "%I64d%I64d" , &a[ i ].first , &a[ i ].second ) ;
        long double aux = -a[ i ].first ;
        aux /= ( a[ i ].second - mx ) ;
        f[ i ].first = aux ;
        aux = -a[ i ].first ;
        aux /= ( a[ i ].second + mx ) ;
        f[ i ].second = aux ;
    }
    sort ( f + 1 , f + n + 1 , cmp ) ;
}

void solve ( ) {
    int i , j ;
    long long ans = 0 ;
    root = NULL ;
    emp = NULL ;
    for ( i = 1 ; i <= n ; i ++ ) {
        ans += query ( root , - f[ i ].second ) ;
        add_val ( - f[ i ].second ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}

int main ( ) {
    ios::sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}