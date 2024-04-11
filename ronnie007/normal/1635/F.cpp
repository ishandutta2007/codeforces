#include<bits/stdc++.h>
using namespace std ;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 300007

int n , q ;
int a[ MAXN ] , w[ MAXN ] ;

vector < pair < int , int > > to_query[ MAXN ] ;


long long calc ( int x , int y ) {
    if ( x > y ) { swap ( x , y ) ; }
    return 1LL * ( a[ y ] - a[ x ] ) * ( w[ x ] + w[ y ] ) ;
}

class Tree {
public :
    long long tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = ( 1LL << 62 ) ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , long long val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = min ( tr[ where ] , val ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) { update ( 2 * where , IL , mid , pos , val ) ; }
        else { update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ; }
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return ( 1LL << 62 ) ; }
        if ( IR < CURL || CURR < IL ) { return ( 1LL << 62 ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree tr ;

void input ( ) {
    cin >> n >> q ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] >> w[ i ] ;
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        int l , r ;
        cin >> l >> r ;
        to_query[ r ].push_back ( { l , i } ) ;
    }
}
vector < pair < int , long long > > cands[ MAXN ] ;
stack < int > st ;

long long ans[ MAXN ] ;

void solve ( ) {
    for ( int i = 1 ; i <= n ; ++ i ) {
        while ( st.empty ( ) == false && w[ st.top ( ) ] > w[ i ] ) {
            st.pop ( ) ;
        }
        if ( st.empty ( ) == false ) {
            cands[ i ].push_back ( { st.top ( ) , calc ( st.top ( ) , i ) } ) ;
        }
        st.push ( i ) ;
    }
    while ( st.empty ( ) == false ) { st.pop ( ) ; }

    for ( int i = n ; i >= 1 ; -- i ) {
        while ( st.empty ( ) == false && w[ st.top ( ) ] > w[ i ] ) {
            st.pop ( ) ;
        }
        if ( st.empty ( ) == false ) {
            cands[ st.top ( ) ].push_back ( { i , calc ( i , st.top ( ) ) } ) ;
        }
        st.push ( i ) ;
    }

    tr.init ( 1 , 1 , n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        for ( auto e : cands[ i ] ) {
            tr.update ( 1 , 1 , n , e.first , e.second ) ;
        }
        for ( auto e : to_query[ i ] ) {
            ans[ e.second ] = tr.query ( 1 , 1 , n , e.first , i ) ;
        }
    }

    for ( int i = 1 ; i <= q ; ++ i ) {
        cout << ans[ i ] << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    t = 1 ;
    /// cin >> t ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}