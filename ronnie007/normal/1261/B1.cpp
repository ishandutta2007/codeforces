#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std ;

#define MAXN 200007

int n , q ;
int st[ MAXN ] ;
pair < int , int > a[ MAXN ] ;
struct query {
    int x , y ;
    int id ;
    bool operator < ( query other ) const {
        return ( other.x > x ) ;
    }
};
struct query b[ MAXN ] ;
int ans[ MAXN ] ;

class Tree {
    public :
    int tr[ 5 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) { ++ tr[ where ] ; return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    int query ( int where , int IL , int IR , int lft ) {
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        if ( tr[ 2 * where ] >= lft ) {
            return query ( 2 * where , IL , mid , lft ) ;
        }
        else {
            return query ( 2 * where + 1 , mid + 1 , IR , lft - tr[ 2 * where ] ) ;
        }
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &st[ i ] ) ;
        a[ i ].first = st[ i ] ;
        a[ i ].second = - i ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    scanf ( "%d" , &q ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        scanf ( "%d%d" , &b[ i ].x , &b[ i ].y ) ;
        b[ i ].id = i ;
    }
    sort ( b + 1 , b + q + 1 ) ;
}

void solve ( ) {
    int cnt = 0 ;
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        while ( cnt < b[ i ].x ) {
            w.update ( 1 , 1 , n , - a[ n - cnt ].second ) ;
            ++ cnt ;
        }
        ans[ b[ i ].id ] = w.query ( 1 , 1 , n , b[ i ].y ) ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        printf ( "%d\n" , st[ ans[ i ] ] ) ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}