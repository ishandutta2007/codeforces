#include<bits/stdc++.h>
using namespace std ;

#define MAXN 400007

int n ;
pair < int , int > a[ MAXN ] ;
int type[ MAXN ] ;
vector < int > v[ 2 ][ MAXN ] ;

int mxval ;
map < int , int > mp ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
        if ( lazy[ where ] == 0 ) { return ; }
        tr[ where ] += lazy[ where ] ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void init ( int where , int IL , int IR ) {
        tr[ where ] = lazy[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    void set_position ( int where , int IL , int IR , int pos , int val ) {
        push_lazy ( where , IL , IR ) ;
        if ( pos < IL || IR < pos ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = max ( tr[ where ] , val ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2;
        set_position ( 2 * where , IL , mid , pos , val ) ;
        set_position ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        tr[ where ] = max ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
};

Tree w[ 2 ] ;

void input ( ) {
    scanf ( "%d" , &n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d%d%d" , &a[ i ].first , &a[ i ].second , &type[ i ] ) ;
        -- type[ i ] ;
        mp[ a[ i ].first ] = mp[ a[ i ].second ] = 1 ;
    }
    mxval = 0 ;
    for ( auto it = mp.begin ( ) ; it != mp.end ( ) ; ++ it ) {
        it->second = ++ mxval ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        a[ i ].first = mp[ a[ i ].first ] ;
        a[ i ].second = mp[ a[ i ].second ] ;
        v[ type[ i ] ][ a[ i ].second ].push_back ( a[ i ].first ) ;
    }
}

void solve ( ) {
    int ans = 0 ;
    for ( int i : { 0 , 1 } ) {
        w[ i ].init ( 1 , 0 , mxval ) ;
    }
    for ( int i = 1 ; i <= mxval ; ++ i ) {
        for ( int id : { 0 , 1 } ) {
            for ( int j : v[ id ][ i ] ) {
                w[ id ].update ( 1 , 0 , mxval , 0 , j - 1 , 1 ) ;
            }
        }
        int aux0 = w[ 0 ].tr[ 1 ] ;
        int aux1 = w[ 1 ].tr[ 1 ] ;
        ans = max ( ans , max ( aux0 , aux1 ) ) ;
        w[ 0 ].set_position ( 1 , 0 , mxval , i , aux1 ) ;
        w[ 1 ].set_position ( 1 , 0 , mxval , i , aux0 ) ;
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