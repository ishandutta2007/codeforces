#include<bits/stdc++.h>
using namespace std ;

#define MAXN 400007

int n , k ;
int a[ MAXN ] ;

class Tree {
public :
    long long tr[ 4 * MAXN + 1 ] ;
    long long lazy[ 4 * MAXN + 1 ] ;
    void push_lazy ( int where , int IL , int IR ) {
        tr[ where ] += lazy[ where ] * ( IR - IL + 1 ) ;
        if ( IL != IR ) {
            lazy[ 2 * where ] += lazy[ where ] ;
            lazy[ 2 * where + 1 ] += lazy[ where ] ;
        }
        lazy[ where ] = 0 ;
    }
    void unite ( int where ) {
        tr[ where ] = tr[ 2 * where ] + tr[ 2 * where + 1 ] ;
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
        if ( IL > IR || CURL > CURR ) { return ; }
        if ( CURR < IL || IR < CURL ) { return ; }
        if ( CURL <= IL && IR <= CURR ) {
            lazy[ where ] += val ;
            push_lazy ( where , IL , IR ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        update ( 2 * where , IL , mid , CURL , CURR , val ) ;
        update ( 2 * where + 1 , mid + 1 , IR , CURL , CURR , val ) ;
        unite ( where ) ;
    }
    int query ( int where , int IL , int IR , int lft ) {
        push_lazy ( where , IL , IR ) ;
        if ( tr[ where ] < lft ) { return -1 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = query ( 2 * where , IL , mid , lft ) ;
        if ( ret == -1 ) { return query ( 2 * where + 1 , mid + 1 , IR , lft - tr[ 2 * where ] ) ; }
        return ret ;
    }
    int get_fst ( int where , int IL , int IR ) {
        push_lazy ( where , IL , IR ) ;
        if ( tr[ where ] == 0 ) { return -1 ; }
        if ( IL == IR ) { return IL ; }
        int mid = ( IL + IR ) / 2 ;
        int ret = get_fst ( 2 * where , IL , mid ) ;
        if ( ret == -1 ) { return get_fst ( 2 * where + 1 , mid + 1 , IR ) ; }
        return ret ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d%d" , &n , &k ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        scanf ( "%d" , &a[ i ] ) ;
    }
    sort ( a + 1 , a + n + 1 , greater < int > ( ) ) ;
}

void solve ( ) {
    long long tot = 1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        tot += a[ i ] - 2 ;
    }
    if ( tot < k ) {
        printf ( "-1\n" ) ;
        return ;
    }
    w.init ( 1 , 1 , MAXN ) ;
    w.update ( 1 , 1 , MAXN , 1 , 1 , 1 ) ;
    int ans = -1 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        int aux = w.get_fst ( 1 , 1 , MAXN ) ;
        int hh = ( a[ i ] - 1 ) / 2 ;
        w.update ( 1 , 1 , MAXN , aux , aux , -1 ) ;
        w.update ( 1 , 1 , MAXN , aux + 2 , aux + 2 + hh - 1 , 1 ) ;
        w.update ( 1 , 1 , MAXN , aux + 2 , aux + 2 + ( a[ i ] - 1 - hh ) - 1 , 1 ) ;
        w.push_lazy ( 1 , 1 , MAXN ) ;
        if ( w.tr[ 1 ] >= k ) {
            int sr = w.query ( 1 , 1 , MAXN , k ) ;
            if ( ans < 0 || ans > sr ) { ans = sr ; }
        }
    }
    printf ( "%d\n" , ans - 1 ) ;
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    int t ;
    // scanf ( "%d" , &t ) ;
    // cin >> t ;
    t = 1 ;
    while ( t -- ) {
        input ( ) ;
        solve ( ) ;
    }
    return 0 ;
}