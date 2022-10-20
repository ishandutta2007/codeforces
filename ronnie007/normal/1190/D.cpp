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

#define MAXN 200007
#define inf 1000000007

int n ;
pair < int , int > a[ MAXN ] ;

mt19937 rng ( time ( 0 ) ) ;

struct node {
    node *pl , *pr ;
    int key , prior ;
    int cnt ;
    node ( ) {
        this->pl = this->pr = NULL ;
        this->key = this->prior = 0 ;
        this->cnt = 0 ;
    }
    node ( int x ) {
        this->pl = this->pr = NULL ;
        this->key = x ;
        this->prior = rng ( ) ;
        this->cnt = 1 ;
    }
};
node *root ;

int get_sz ( node *w ) {
    if ( w == NULL ) { return 0 ; }
    return w->cnt ;
}

void update ( node *w ) {
    w->cnt = 1 + get_sz ( w->pl ) + get_sz ( w->pr ) ;
}

void split ( node *w , node* (&l) , node* (&r) , int sr ) {
    if ( w == NULL ) { l = NULL ; r = NULL ; return ; }
    if ( w->key <= sr ) {
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

void merge ( node* (&w) , node* l , node* r ) {
    if ( l == NULL ) { w = r ; return ; }
    if ( r == NULL ) { w = l ; return ; }
    if ( l->prior >= r->prior ) {
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
bool check ( node *w , int sr ) {
    if ( w == NULL ) { return false ; }
    if ( w->key == sr ) { return true ; }
    if ( w->key > sr ) {
        return check ( w->pl , sr ) ;
    }
    else {
        return check ( w->pr , sr ) ;
    }
}

int get ( node *w , int sr ) {
    if ( w == NULL ) { return 0 ; }
    if ( w->key > sr ) {
        return get ( w->pl , sr ) ;
    }
    else {
        return 1 + get_sz ( w->pl ) + get ( w->pr , sr ) ;
    }
}

void add_val ( int x ) {
    if ( check ( root , x ) == true ) { return ; }
    node *ret1 , *ret2 , *ret3 ;
    split ( root , ret1 , ret2 , x ) ;
    ret3 = new node ( x ) ;
    merge ( root , ret1 , ret3 ) ;
    merge ( root , root , ret2 ) ;
}

bool cmp ( pair < int , int > p1 , pair < int , int > p2 ) {
    if ( p1.second != p2.second ) {
        return ( p1.second > p2.second ) ;
    }
    return ( p1.first < p2.first ) ;
}

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
    sort ( a + 1 , a + n + 1 , cmp ) ;
}

void solve ( ) {
    root = NULL ;
    vector < int > aux ;
    long long ans = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        aux.clear ( ) ;
        for ( int j = i ; j <= n ; ++ j ) {
            if ( a[ j ].second != a[ i ].second ) { i = j - 1 ; break ; }
            aux.push_back ( a[ j ].first ) ;
            if ( j == n ) { i = j ; }
        }
        aux.push_back ( inf ) ;
        int sz = aux.size ( ) ;
        for ( int j = 0 ; j < sz - 1 ; ++ j ) {
            add_val ( aux[ j ] ) ;
        }
        for ( int j = 1 ; j < sz ; ++ j ) {
            long long hh1 = get ( root , aux[ j - 1 ] ) ;
            long long hh2 = get ( root , aux[ j ] - 1 ) - hh1 + 1 ;
            ans += hh1 * hh2 ;
        }
    }
    cout << ans << "\n" ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}