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
#define inf 1000000000

int n , q ;
int a[ MAXN ] ;

vector < pair < int , int > > v[ MAXN ] ;

int ans[ MAXN ] ;

struct node {
    node *pl , *pr ;
    int IL , IR ;
    int mx ;
    node ( ) {
        this->pl = this->pr = NULL ;
        this->IL = this->IR = this->mx = 0 ;
    }
    node ( int _IL , int _IR ) {
        this->pl = this->pr = NULL ;
        this->IL = _IL ;
        this->IR = _IR ;
        this->mx = 0 ;
    }
};

void upd_mx ( node *w ) {
    w->mx = 0 ;
    if ( w->pl != NULL ) { w->mx = max ( w->mx , w->pl->mx ) ; }
    if ( w->pr != NULL ) { w->mx = max ( w->mx , w->pr->mx ) ; }
}

int query ( node *w , int CURL , int CURR ) {
    if ( CURL > CURR ) { return 0 ; }
    if ( w->IR < CURL || CURR < w->IL ) { return 0 ; }
    if ( CURL <= w->IL && w->IR <= CURR ) { return w->mx ; }
    int ret = 0 ;
    if ( w->pl != NULL ) {
        ret = max ( ret , query ( w->pl , CURL , CURR ) ) ;
    }
    if ( w->pr != NULL ) {
        ret = max ( ret , query ( w->pr , CURL , CURR ) ) ;
    }
    return ret ;
}

void update ( node *w , int pos , int val ) {
    if ( w->IR < pos || pos < w->IL ) { return ; }
    if ( w->IL == w->IR ) {
        w->mx = val ;
        return ;
    }
    int mid = ( w->IL + w->IR ) / 2 ;
    if ( pos <= mid ) {
        if ( w->pl == NULL ) {
            w->pl = new node ( w->IL , mid ) ;
        }
        update ( w->pl , pos , val ) ;
    }
    else {
        if ( w->pr == NULL ) {
            w->pr = new node ( mid + 1 , w->IR ) ;
        }
        update ( w->pr , pos , val ) ;
    }
    upd_mx ( w ) ;
}

node* root ;

class SegTree {
public :
    int tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = inf ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = min ( tr[ where ] , val ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return inf ; }
        if ( IR < CURL || CURR < IL ) { return inf ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};

SegTree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    scanf ( "%d" , &q ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        int x , y ;
        scanf ( "%d%d" , &x , &y ) ;
        v[ y ].push_back ( { x , i } ) ;
    }
}

void solve ( ) {
    root = new node ( 0 , inf ) ;
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int st = query ( root , 0 , a[ i ] ) ;
        if ( st > 0 ) {
            int val = a[ st ] ;
            int diff = ( a[ i ] - val ) ;
            w.update ( 1 , 1 , n , st , diff ) ;
            while ( diff > 0 ) {
                val += ( diff / 2 + 1 ) ;
                st = query ( root , val , a[ i ] ) ;
                if ( st == 0 ) { break ; }
                val = a[ st ] ;
                diff = ( a[ i ] - val ) ;
                w.update ( 1 , 1 , n , st , diff ) ;
            }
        }
        st = query ( root , a[ i ] , inf ) ;
        if ( st > 0 ) {
            int val = a[ st ] ;
            int diff = ( val - a[ i ] ) ;
            w.update ( 1 , 1 , n , st , diff ) ;
            while ( diff > 0 ) {
                val -= ( diff / 2 + 1 ) ;
                st = query ( root , a[ i ] , val ) ;
                if ( st == 0 ) { break ; }
                val = a[ st ] ;
                diff = ( val - a[ i ] ) ;
                w.update ( 1 , 1 , n , st , diff ) ;
            }
        }
        int sz = v[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            ans[ v[ i ][ j ].second ] = w.query ( 1 , 1 , n , v[ i ][ j ].first , i ) ; 
        }
        update ( root , a[ i ] , i ) ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        printf ( "%d\n" , ans[ i ] ) ;
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}