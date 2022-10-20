#include<bits/stdc++.h>
using namespace std ;

#define MAXN 100007

int n ;
int a[ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = 0 ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int nw ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) { tr[ where ] = nw ; return ; }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , nw ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , nw ) ;
        }
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( IL > IR || CURL > CURR ) { return MAXN ; }
        if ( IR < CURL || CURR < IL ) { return MAXN ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

bool fl[ MAXN ] ;
int lst[ MAXN ] ;

void input ( ) {
    cin >> n ;
    for ( int i = 1 ; i <= n ; ++ i ) {
        cin >> a[ i ] ;
    }
}


void solve ( ) {
    for ( int i = 1 ; i <= n + 1 ; ++ i ) {
        if ( a[ i ] == 1 ) {
            fl[ 2 ] = true ;
            lst[ a[ i ] ] = i ;
            w.update ( 1 , 1 , n , a[ i ] , i ) ;
            continue ;
        }
        else if ( i <= n ) { fl[ 1 ] = true ; }
        int ret = w.query ( 1 , 1 , n , 1 , a[ i ] - 1 ) ;
        if ( ret > lst[ a[ i ] ] ) {
            fl[ a[ i ] ] = true ;
        }
        lst[ a[ i ] ] = i ;
        w.update ( 1 , 1 , n , a[ i ] , i ) ;
    }
    for ( int i = 2 ; i <= n + 1 ; ++ i ) {
        int ret = w.query ( 1 , 1 , n , 1 , i - 1 ) ;
        if ( ret > lst[ i ] ) {
            fl[ i ] = true ;
        }
    }
    for ( int i = 1 ; i <= n + 2 ; ++ i ) {
        if ( fl[ i ] == false ) {
            cout << i << "\n" ;
            return ;
        }
    }
}

int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}