#include<bits/stdc++.h>
using namespace std ;

#define MAXN 400007

int n , m , q ;
struct tuhla {
    int x , y ;
    int ost ;
    int id ;
    bool operator < ( tuhla other ) const {
        if ( x != other.x ) { return x < other.x ; }
        if ( y != other.y ) { return y < other.y ; }
        if ( ost != other.ost ) { return ost < other.ost ; }
        return id < other.id ;
    }
};
tuhla a[ MAXN ] ;

class Tree {
public :
    int tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        tr[ where ] = MAXN ;
        if ( IL == IR ) { return ; }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
    }
    void update ( int where , int IL , int IR , int pos , int val ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = min ( tr[ where ] , val ) ;
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos , val ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos , val ) ;
        }
        tr[ where ] = min ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }
    int query ( int where , int IL , int IR , int CURL , int CURR ) {
        if ( CURL > CURR ) { return MAXN ; }
        if ( IR < CURL || CURR < IL ) { return MAXN ; }
        if ( CURL <= IL && IR <= CURR ) { return tr[ where ] ; }
        int mid = ( IL + IR ) / 2 ;
        return min ( query ( 2 * where , IL , mid , CURL , CURR ) , query ( 2 * where + 1 , mid + 1 , IR , CURL , CURR ) ) ;
    }
};
Tree w ;

void input ( ) {
    scanf ( "%d%d%d" , &n , &m , &q ) ;
}

void solve ( ) {
    int ans = q + 1 ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        scanf ( "%d%d" , &a[ i ].x , &a[ i ].y ) ;
        -- a[ i ].x ; -- a[ i ].y ;
        a[ i ].ost = ( a[ i ].x % 2 ) ;
        a[ i ].x /= 2 ; a[ i ].y /= 2 ;
        a[ i ].id = i ;
    }
    sort ( a + 1 , a + q + 1 ) ;
    w.init ( 1 , 1 , m ) ;
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( a[ i ].ost == 0 ) {
            w.update ( 1 , 1 , m , a[ i ].y + 1 , a[ i ].id ) ;
        }
        else {
            ans = min ( ans , max ( a[ i ].id , w.query ( 1 , 1 , m , 1 , a[ i ].y + 1 ) ) ) ;
        }
    }
    for ( int i = 1 ; i <= q ; ++ i ) {
        if ( i < ans ) { printf ( "YES\n" ) ; }
        else { printf ( "NO\n" ) ; }
    }
}


int main ( ) {
    ios_base :: sync_with_stdio ( false ) ;
    cin.tie ( NULL ) ;
    input ( ) ;
    solve ( ) ;
    return 0 ;
}