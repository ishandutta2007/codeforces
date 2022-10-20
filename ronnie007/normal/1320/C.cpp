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

#define MAXN 200007

int n , m , p ;
pair < int , int > a[ MAXN ] ;
pair < int , int > b[ MAXN ] ;

struct tuhla {
    int x , y , z ;
    bool operator < ( tuhla other ) const {
        return ( x < other.x ) ;
    }
};
tuhla c[ MAXN ] ;

class Tree {
public :
    long long tr[ 5 * MAXN ] ;
    long long lazy[ 5 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        tr[ where ] += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = - b[ IL ].second ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int add ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURL > CURR ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += add ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , add ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , add ) ;
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    long long query ( ) { return tr[ 1 ] ; }
};
Tree w ;

void add ( int id ) {
    int l , r , mid ;
    l = 1 ; r = m ;
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( b[ mid ].first <= c[ id ].y ) { l = mid ; }
        else { r = mid ; }
    }
    while ( l <= m && b[ l ].first <= c[ id ].y ) { ++ l ; }
    w.update ( 1 , 1 , m , l , m , c[ id ].z ) ;
}

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &p ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].first , &a[ i ].second ) ;
    }
    for ( int i = 1 ; i <= m ; ++ i ) {
        scanf ( "%d%d" , &b[ i ].first , &b[ i ].second ) ;
    }
    for ( int i = 1 ; i <= p ; ++ i ) {
        scanf ( "%d%d%d" , &c[ i ].x , &c[ i ].y , &c[ i ].z ) ;
    }
    sort ( a + 1 , a + n + 1 ) ;
    sort ( b + 1 , b + m + 1 ) ;
    sort ( c + 1 , c + p + 1 ) ;
}

void solve ( ) {
    w.init ( 1 , 1 , m ) ;
    int id = 0 ;
    long long ans ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( id < p && c[ id + 1 ].x < a[ i ].first ) {
            add ( ++ id ) ;
        }
        long long aux = w.query ( ) - a[ i ].second ;
        if ( i == 1 ) { ans = aux ; }
        ans = max ( ans , aux ) ;
    }
    printf ( "%I64d\n" , ans ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}