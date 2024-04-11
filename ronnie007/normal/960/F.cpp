#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
using namespace std ;

#define MAXN 100007

int n , m ;

struct tuhla {
    int x , y , z ;
    int id ;
};
tuhla a[ MAXN ] ;
int ret[ MAXN ] ;

bool cmp ( tuhla p1 , tuhla p2 ) {
    if ( p1.z != p2.z ) { return ( p1.z < p2.z ) ; }
    return ( p1.id < p2.id ) ;
}

struct Tree {
    int val ;
    int IL , IR ;
    Tree *pl , *pr ;
    Tree ( ) { this->val = this->IL = this->IR = 0 ; this->pl = this->pr = NULL ; }
    Tree ( int _IL , int _IR ) {
        this->val = 0 ;
        this->IL = _IL ;
        this->IR = _IR ;
        this->pl = this->pr = NULL ;
    }
    void update ( int pos , int nwval ) {
        int mid = ( this->IL + this->IR ) / 2 ;
        if ( this->pl == NULL ) {
            this->pl = new Tree ( this->IL , mid ) ;
            this->pr = new Tree ( mid + 1 , this->IR ) ;
        }
        if ( this->IL == this->IR ) {
            this->val = max ( this->val , nwval ) ;
            return ;
        }
        if ( pos <= mid ) {
            this->pl->update ( pos , nwval ) ;
        }
        else {
            this->pr->update ( pos , nwval ) ;
        }
        this->val = max ( this->pl->val , this->pr->val ) ;
    }
    int query ( int CURL , int CURR ) {
        if ( this->IR < CURL || CURR < this->IL ) { return 0 ; }
        if ( CURL <= this->IL && this->IR <= CURR ) { return this->val ; }
        int ret = 0 ;
        if ( this->pl != NULL ) {
            ret = max ( ret , this->pl->query ( CURL , CURR ) ) ;
        }
        if ( this->pr != NULL ) {
            ret = max ( ret , this->pr->query ( CURL , CURR ) ) ;
        }
        return ret ;
    }
};
Tree *root[ MAXN ] ;

void input ( ) {
    scanf ( "%d%d" , &n , &m ) ;
    int i ;
    for ( i = 1 ; i <= n ; i ++ ) {
        root[ i ] = new Tree ( 1 , m ) ;
    }
    for ( i = 1 ; i <= m ; i ++ ) {
        scanf ( "%d%d%d" , &a[ i ].x , &a[ i ].y , &a[ i ].z ) ;
        a[ i ].id = i ;
    }
    sort ( a + 1 , a + m + 1 , cmp ) ;
}

void solve ( ) {
    int i , j ;
    int ans = 0 ;
    for ( i = 1 ; i <= m ; i ++ ) {
        int val = root[ a[ i ].x ]->query ( 1 , a[ i ].id - 1 ) ;
        ret[ i ] = val + 1 ;
        if ( ans < ret[ i ] ) { ans = ret[ i ] ; }
        if ( a[ i ].z != a[ i + 1 ].z ) {
            for ( j = i ; j >= 1 ; j -- ) {
                if ( a[ j ].z != a[ i ].z ) { break ; }
                root[ a[ j ].y ]->update ( a[ j ].id , ret[ j ] ) ;
            }
        }
    }
    printf ( "%d\n" , ans ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}