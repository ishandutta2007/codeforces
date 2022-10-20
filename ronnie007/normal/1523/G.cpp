#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n , m ;
pair < int , int > a[ MAXN ] ;


class Tree {
    struct node {
        int val ;
        node *pl , *pr ;
        node ( ) {
            val = MAXN ;
            pl = pr = NULL ;
        }
    };
    
    node *tr[ 4 * MAXN ] ;
    void inner_update ( node *where , int l , int r , int pos , int val ) {
        if ( r < pos || pos < l ) { return ; }
        if ( l == r ) {
            where->val = min ( where->val , val ) ;
            return ;
        }
        int mid = ( l + r ) / 2 ;
        if ( pos <= mid ) {
            if ( where->pl == NULL ) {
                where->pl = new node ( ) ;
            }
            inner_update ( where->pl , l , mid , pos , val ) ;
        }
        else {
            if ( where->pr == NULL ) {
                where->pr = new node ( ) ;
            }
            inner_update ( where->pr , mid + 1 , r , pos , val ) ;
        }
        where->val = MAXN ;
        if ( where->pl != NULL ) {
            where->val = min ( where->val , where->pl->val ) ;
        }
        if ( where->pr != NULL ) {
            where->val = min ( where->val , where->pr->val ) ;
        }
    }
    int inner_query ( node *where , int l , int r , int IR ) {
        // printf ( "at %d %d, searching up to %d\n" , where->l , where->r , IR ) ;
        if ( IR < l ) { return MAXN ; }
        if ( r <= IR ) { return where->val ; }
        int mid = ( l + r ) / 2 ;
        int ret = MAXN ;
        if ( where->pl != NULL ) {
            ret = min ( ret , inner_query ( where->pl , l , mid , IR ) ) ;
        }
        if ( where->pr != NULL ) {
            ret = min ( ret , inner_query ( where->pr , mid + 1 , r , IR ) ) ;
        }
        return ret ;
    }
public :
    void init ( int where , int IL , int IR ) {
        tr[ where ] = new node ( ) ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int lim , int val ) {
        inner_update ( tr[ where ] , IL , n , lim , val ) ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , lim , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , lim , val ) ;
        }
    }
    int query ( int where , int IL , int IR , int sr , int lim ) {
        if ( sr > lim || IL > IR ) { return MAXN ; }
        if ( IR < sr || lim < IL ) { return MAXN ; }
        if ( sr <= IL && IR <= lim ) { return inner_query ( tr[ where ] , IL , n , lim ) ; }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , sr , lim ) , query ( 2 * where + 1 , mid + 1 , IR , sr , lim ) ) ;
    }
};

Tree w ;

vector < int > v[ MAXN ] ;


int f ( int l , int r ) {
    if ( r < l ) { return 0 ; }
    int ret = w.query ( 1 , 1 , n , l , r ) ;
    if ( ret == MAXN ) { return 0 ; }
    int x = a[ ret ].first ;
    int y = a[ ret ].second ;
    return f ( l , x - 1 ) + f ( y + 1 , r ) + y - x + 1 ;
}

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
        v[ a[ i ].second - a[ i ].first + 1 ].push_back ( i ) ;
    }
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    vector < int > ans ;
    for ( int i = n ; i >= 1 ; -- i ) {
        for ( auto x : v[ i ] ) {
            w.update ( 1 , 1 , n , a[ x ].first , a[ x ].second , x ) ;
        }
        ans.push_back ( f ( 1 , n ) ) ;
    }
    for ( int i = n - 1 ; i >= 0 ; -- i ) {
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