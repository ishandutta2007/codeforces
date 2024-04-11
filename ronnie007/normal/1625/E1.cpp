#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 300007

int n , q ;
string a ;

vector < int > v[ MAXN ] ;
int cnt[ MAXN ] , act[ MAXN ] ;

int prv[ MAXN ] ;
int id[ MAXN ] ;
int st[ MAXN ] , en[ MAXN ] ;
int pos_in_parent[ MAXN ] ;

class Tree {
public :
    long long tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , long long nw ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = nw ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , nw ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , nw ) ;
        }
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
    }
    long long query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return 0 ; }
        if ( IR < CURL || CURR < IL ) { return 0 ; }
        if ( CURL <= IL && IR <= CURR ) {
            return tr[ where ] ; 
        }
        int mid = ( IL + IR ) / 2 ;
        return query ( 2 * where , IL , mid , CURL , CURR ) + query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ;
    }
};

Tree w ;

vector < int > fenw[ MAXN ] ;

void init ( int wh ) {
    for ( int i = 0 ; i <= cnt[ wh ] ; ++ i ) {
        fenw[ wh ][ i ] = 0 ;
    }
}

void upd ( int wh , int id , int x ) {
    for ( int i = id ; i <= act[ wh ] ; i += ( i & (-i) ) ) {
        fenw[ wh ][ i ] += x ;
    }
}

int query ( int wh , int id ) {
    int ret = 0 ;
    for ( int i = id ; i >= 1 ; i -= ( i & ( -i ) ) ) {
        ret += fenw[ wh ][ i ] ;
    }
    return ret ;
}

int get ( int prv , int sr ) {
    int l , r , mid ;
    l = 0 , r = v[ prv ].size ( ) - 1 ;
    if ( r < 0 ) { return 0 ; }
    if ( v[ prv ][ l ] > sr ) { return 0 ; }
    while ( r - l > 3 ) {
        mid = ( l + r ) / 2 ;
        if ( v[ prv ][ mid ] <= sr ) { l = mid ; }
        else { r = mid ; }
    }
    while ( v[ prv ][ r ] > sr ) { -- r ; }
    return r + 1 ;
}

void input ( ) {
    cin >> n >> q ;
    cin >> a ;
}

void solve ( ) {
    int lst = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( a[ i - 1 ] == '(' ) {
            v[ lst ].push_back ( i ) ;
            ++ cnt[ lst ] ;
            pos_in_parent[ i ] = cnt[ lst ] ;
            prv[ i ] = lst ;
            st[ i ] = i ;
            lst = i ;

        }
        else {
            if ( lst == 0 ) { continue ; }
            id[ i ] = lst ;
            en[ lst ] = i ;
            lst = prv[ lst ] ;
        }
    }
    w.init ( 1 , 1 , n ) ;
    fenw[ 0 ].resize ( cnt[ 0 ] + 1 ) ;
    act[ 0 ] = cnt[ 0 ] ;
    init ( 0 ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        if ( st[ i ] == i ) {
            fenw[ i ].resize ( cnt[ i ] + 1 ) ;
            init ( i ) ;
            act[ i ] = cnt[ i ] ; 
            w.update ( 1 , 1 , n , i , 1LL * cnt[ i ] * ( cnt[ i ] + 1 ) / 2 ) ;
            if ( pos_in_parent[ i ] > 0 ) {
                upd ( prv[ i ] , pos_in_parent[ i ] , 1 ) ;
            }
        }
    }
    while ( q -- ) {
        int type , x , y ;
        cin >> type >> x >> y ;
        if ( type == 1 ) {
            -- cnt[ prv[ x ] ] ;
            w.update ( 1 , 1 , n , prv[ x ] , 1LL * cnt[ prv[ x ] ] * ( cnt[ prv[ x ] ] + 1 ) / 2 ) ;
            upd ( prv[ x ] , pos_in_parent[ x ] , -1 ) ;
        }
        else {
            long long ans = w.query ( 1 , 1 , n , x , y ) ;
            long long aux = query ( prv[ x ] , pos_in_parent[ id[ y ] ] ) - query ( prv[ x ] , pos_in_parent[ x ] - 1 ) ;
            ans += aux * ( aux + 1 ) / 2 ;
            cout << ans << "\n" ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // cin >> t ;
    t = 1 ;
    // scanf ( "%d" , &t ) ;
    while ( t -- ) { 
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}