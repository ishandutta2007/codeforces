#include<iostream>
#include<stdio.h>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
using namespace std ;

#define MAXN 1000007
int n , q ;
int a[ MAXN ] ;

int st[ MAXN ] ;
int en[ MAXN ] ;

vector < pair < int , int > > v_st[ MAXN ] ;
long long ans[ MAXN ] ;

class Tree {
    public :
    pair < long long , int > tr[ 6 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = { 0 , 0 } ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int CURL , int CURR , pair < long long , int > add ) {
        if ( CURR < CURL ) { return ; }
        if ( IR < CURL || CURR < IL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            tr[ where ].first += add.first , tr[ where ].second += add.second ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , add ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , add ) ;
    }
    pair < long long , int > query ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return { 0 , 0 } ; }
        if ( IL == IR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        pair < long long , int > ret ;
        if ( pos <= mid ) {
            ret = query ( 2 * where , IL , mid , pos ) ;
        }
        else {
            ret = query ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        ret = { ret.first + tr[ where ].first , ret.second + tr[ where ].second } ;
        return ret ;
    }
};

Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &q ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        scanf ( "%d" , &st[ i ] ) ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        scanf ( "%d" , &en[ i ] ) ;
        v_st[ en[ i ] ].push_back ( { st[ i ] , i } ) ;
    }
}

void calc ( ) {
    stack < int > st ;
    a[ 0 ] = n + 1 ;
    st.push ( 0 ) ;
    w.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( a[ st.top ( ) ] < a[ i ] ) {
            st.pop ( ) ;
        }
        w.update ( 1 , 1 , n , 1 , st.top ( ) , { i - st.top ( ) - 1 , 0 } ) ;
        w.update ( 1 , 1 , n , st.top ( ) + 1 , i , { i , 1 } ) ;
        st.push ( i ) ;
        int sz = v_st[ i ].size ( ) ;
        for ( int j = 0 ; j < sz ; ++ j ) {
            pair < long long , int > ret = w.query ( 1 , 1 , n , v_st[ i ][ j ].first ) ;
            ans[ v_st[ i ][ j ].second ] += ret.first - 1LL * ret.second * v_st[ i ][ j ].first ;
        }
    }
}

void solve ( ) {
    calc ( ) ;
    for ( int i = 1 ; i <= ( n >> 1 ) ; ++ i ) {
        swap ( a[ i ] , a[ n - i + 1 ] ) ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        v_st[ i ].clear ( ) ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        st[ i ] = ( n - st[ i ] + 1 ) ;
        en[ i ] = ( n - en[ i ] + 1 ) ;
        swap ( st[ i ] , en[ i ] ) ;
        v_st[ en[ i ] ].push_back ( { st[ i ] , i } ) ;
    }
    calc ( ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        printf ( "%I64d " , ans[ i ] + ( en[ i ] - st[ i ] + 1 ) ) ;
    }
    printf ( "\n" ) ;
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}