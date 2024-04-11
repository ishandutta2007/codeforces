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
using namespace std ;


int n , q ;

struct node {
    node *pl , *pr ;
    int IL , IR ;
    int val ;
    node ( ) {
        pl = pr = NULL ;
        IL = IR = val = 0 ;
    }
    node ( int _IL , int _IR , int _val ) {
        pl = pr = NULL ;
        IL = _IL , IR = _IR , val = _val ;
    }
};

class Tree {
    public :
    node *root ;
    void init ( ) {
        root = new node ( 1 , n , 0 ) ;
    }
    void update ( node *w , int st , int en , int val ) {
        if ( w == NULL ) { return ; }
        if ( en < w->IL || w->IR < st ) { return ; }
        if ( st <= w->IL && w->IR <= en ) {
            w->val = max ( w->val , val ) ;
            return ;
        }
        int mid = ( w->IL + w->IR ) / 2 ;
        if ( w->pl == NULL && st <= mid ) {
            w->pl = new node ( w->IL , mid , 0 ) ;
        }
        if ( w->pr == NULL && mid + 1 <= en ) {
            w->pr = new node ( mid + 1 , w->IR , 0 ) ;
        }
        update ( w->pl , st , en , val ) ;
        update ( w->pr , st , en , val ) ;
    }
    int query ( node *w , int pos ) {
        if ( w == NULL ) { return 0 ; }
        if ( pos < w->IL || w->IR < pos ) { return 0 ; }
        if ( w->IL == w->IR ) { return w->val ; }
        int mid = ( w->IL + w->IR ) / 2 ;
        if ( pos <= mid ) {
            return max ( w->val , query ( w->pl , pos ) ) ;
        }
        else {
            return max ( w->val , query ( w->pr , pos ) ) ;
        }
    }
};
map < int , bool > ZX ;

Tree w_up , w_left ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
}

void solve ( ) {
    w_up.init ( ) , w_left.init ( ) ;
    while ( q -- ) {
        int x , y ;
        char c ;
        scanf ( "\n%d%d %c" , &x , &y , &c ) ;
        if ( ZX[ x ] == true ) { printf ( "0\n" ) ; continue ; }
        ZX[ x ] = true ;
        if ( c == 'U' ) {
            int ret = w_left.query ( w_left.root , x ) ;
            printf ( "%d\n" , y - ret ) ;
            w_up.update ( w_up.root , ret , y , x ) ;

        }
        else {
            int ret = w_up.query ( w_up.root , y ) ;
            printf ( "%d\n" , x - ret ) ;
            w_left.update ( w_left.root , ret , x , y ) ;
        }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}