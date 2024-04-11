#include<bits/stdc++.h>
using namespace std ;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define MAXN 100007

int n , q ;
string a ;

// a , b , c , ab , bc

vector < int > masks ;
int rvpos[ 35 ] ;

void init ( ) {
    int cnt = 0 ;
    for ( int i = 0 ; i < ( 1 << 5 ) ; ++ i ) {
        rvpos[ i ] = -1 ;
    }
    for ( int i = 0 ; i < ( 1 << 5 ) ; ++ i ) {
        if ( ( i & 8 ) > 0 && ( i & 1 ) == 0 ) { continue ; }
        if ( ( i & 8 ) > 0 && ( i & 2 ) == 0 ) { continue ; }

        if ( ( i & 16 ) > 0 && ( i & 2 ) == 0 ) { continue ; }
        if ( ( i & 16 ) > 0 && ( i & 4 ) == 0 ) { continue ; }
        
        rvpos[ i ] = masks.size ( ) ;
        masks.push_back ( i ) ;
    }
}

struct node {
    int cost[ 13 ] ;
    node ( ) {
        for ( int i = 0 ; i < 13 ; ++ i ) {
            cost[ i ] = MAXN ; 
        }
    }
};

node unite ( node p1 , node p2 ) {
    node ret = node ( ) ;
    for ( int i = 0 ; i < 13 ; ++ i ) {
        for ( int j = 0 ; j < 13 ; ++ j ) {
            if ( ( masks[ i ] & 1 ) > 0 && ( masks[ j ] & 16 ) > 0 ) { continue ; }
            if ( ( masks[ i ] & 8 ) > 0 && ( masks[ j ] & 4 ) > 0 ) { continue ; }
            
            int hh = masks[ i ] | masks[ j ] ;
            if ( ( masks[ i ] & 1 ) > 0 && ( masks[ j ] & 2 ) > 0 ) {
                hh |= 8 ;
            }
            if ( ( masks[ i ] & 2 ) > 0 && ( masks[ j ] & 4 ) > 0 ) {
                hh |= 16 ;
            }
            ret.cost[ rvpos[ hh ] ] = min ( ret.cost[ rvpos[ hh ] ] , p1.cost[ i ] + p2.cost[ j ] ) ;
        }
    }
    return ret ;
}

class Tree {
public :
    node tr[ 4 * MAXN ] ;
    void init ( int where , int IL , int IR ) {
        if ( IL == IR ) {
            tr[ where ] = node ( ) ;
            tr[ where ].cost[ 0 ] = 1 ;
            if ( a[ IL - 1 ] == 'a' ) {
                tr[ where ].cost[ 1 ] = 0 ;
            }
            else if ( a[ IL - 1 ] == 'b' ) {
                tr[ where ].cost[ 2 ] = 0 ;
            }
            else {
                tr[ where ].cost[ 4 ] = 0 ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        init ( 2 * where , IL , mid ) ;
        init ( 2 * where + 1 , mid + 1 , IR ) ;
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }

    void update ( int where , int IL , int IR , int pos ) {
        if ( IR < pos || pos < IL ) { return ; }
        if ( IL == IR ) {
            tr[ where ] = node ( ) ;
            tr[ where ].cost[ 0 ] = 1 ;
            if ( a[ IL - 1 ] == 'a' ) {
                tr[ where ].cost[ 1 ] = 0 ;
            }
            else if ( a[ IL - 1 ] == 'b' ) {
                tr[ where ].cost[ 2 ] = 0 ;
            }
            else {
                tr[ where ].cost[ 4 ] = 0 ;
            }
            return ;
        }
        int mid = ( IL + IR ) / 2 ;
        if ( pos <= mid ) {
            update ( 2 * where , IL , mid , pos ) ;
        }
        else {
            update ( 2 * where + 1 , mid + 1 , IR , pos ) ;
        }
        tr[ where ] = unite ( tr[ 2 * where ] , tr[ 2 * where + 1 ] ) ;
    }

    int query ( ) {
        int ret = MAXN ; 
        for ( int i = 0 ; i < 13 ; ++ i ) {
            ret = min ( ret , tr[ 1 ].cost[ i ] ) ;
        }
        return ret ;
    }
};

Tree w ;



void input ( ) {
    cin >> n >> q ;
    cin >> a ;
    init ( ) ;
}

void solve ( ) {
    w.init ( 1 , 1 , n ) ;
    while ( q -- ) {
        int wh ;
        char c ;
        cin >> wh >> c ;
        -- wh ;
        a[ wh ] = c ;
        w.update ( 1 , 1 , n , wh + 1 ) ;
        cout << w.query ( ) << "\n" ;
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