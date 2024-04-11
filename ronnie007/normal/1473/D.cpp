#include<bits/stdc++.h>
using namespace std ;

#define MAXN 200007

int n , m ;
string a ;

struct node {
    int mx , mn ;
    int sm ;
    node ( ) { mx = mn = sm = 0 ; }
    node ( int _mx , int _mn , int _sm ) {
        mx = _mx ; mn = _mn ; sm = _sm ;
    }
};

node unite ( node p1 , node p2 ) {
    node ret ;
    ret.sm = p1.sm + p2.sm ;
    ret.mx = max ( p1.mx , p1.sm + p2.mx ) ;
    ret.mn = min ( p1.mn , p1.sm + p2.mn ) ;
    return ret ;
}

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            if ( a[ IL - 1 ] == '-' ) {
                tr[ where ] = node ( 0 , -1 , -1 ) ;
            }
            else {
                tr[ where ] = node ( 1 , 0 , 1 ) ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    node query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return node ( ) ; }
        if ( CURR < IL || IR < CURL ) { return node ( ) ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return unite ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    cin >> n >> m ;
    cin >> a ;
    w.init ( 1 , 1 , n ) ;
}

void solve ( ) {
    while ( m -- ) {
        int l , r ;
        cin >> l >> r ;
        node ans = node ( ) ;
        node ret = w.query ( 1 , 1 , n , 1 , l - 1 ) ;
        ans = unite ( ans , ret ) ;
        ret = w.query ( 1 , 1 , n , r + 1 , n ) ;
        ans = unite ( ans , ret ) ;
        cout << ans.mx - ans.mn + 1 << "\n" ;
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    cin >> t ;
    // scanf ( "%d" , &t ) ;
    // t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}