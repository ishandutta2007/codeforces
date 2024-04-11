#include<bits/stdc++.h>
using namespace std ;

int n ;
#define MAXN 400007

bool fl[ MAXN ] ;

bool ok_down[ MAXN ] ;
bool ok_up[ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    int lazy[ 4 * MAXN ] ;
    void push_lazy ( int where , int IL , int IR ) {
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
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( ) {
        return tr[ 1 ] ;
    }
};
Tree w ;



void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= 2 * n ; ++ i ) {
        fl[ i ] = false ;
    }
    for ( int i = 1 ; i <= n ; ++ i ) {
        int x = 0 ;
        cin >> x ;
        fl[ x ] = true ;
    }
}

void solve ( ) {
    for ( int i = 0 ; i <= n ; ++ i ) {
        ok_up[ i ] = ok_down[ i ] = false ;
    }
    ok_up[ 0 ] = ok_down[ 0 ] = true ;
    int pos1 = 0 ;
    int pos2 = 2 * n + 1 ;
    w.init ( 1 , 1 , 2 * n ) ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        ++ pos1 ; -- pos2 ;
        while ( fl[ pos1 ] == false ) { ++ pos1 ; }
        while ( fl[ pos2 ] == true ) { -- pos2 ; }
        w.update ( 1 , 1 , 2 * n , pos1 , 2 * n , 1 ) ;
        w.update ( 1 , 1 , 2 * n , pos2 , 2 * n , -1 ) ;
        int ret = w.query ( ) ;
        if ( ret >= 0 ) { ok_down[ i ] = true ; }
    }
    w.init ( 1 , 1 , 2 * n ) ;
    pos1 = 2 * n + 1 ;
    pos2 = 0 ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        -- pos1 ; ++ pos2 ;
        while ( fl[ pos1 ] == false ) { -- pos1 ; }
        while ( fl[ pos2 ] == true ) { ++ pos2 ; }
        w.update ( 1 , 1 , 2 * n , 1 , pos1 , 1 ) ;
        w.update ( 1 , 1 , 2 * n , 1 , pos2 , -1 ) ;
        int ret = w.query ( ) ;
        if ( ret >= 0 ) { ok_up[ i ] = true ; }
    }
    int ans = 0 ;
    for ( int i = 0 ; i <= n ; ++ i ) {
        ans += ( ok_down[ i ] & ok_up[ n - i ] ) ;
    }
    cout << ans << "\n" ;
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